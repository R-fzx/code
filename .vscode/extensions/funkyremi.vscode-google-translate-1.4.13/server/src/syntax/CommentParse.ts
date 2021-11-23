import { TextDocument, Position, Range } from "vscode-languageserver";
import { IGrammar, StackElement, IToken, IGrammarExtensions } from "./TextMateService";

export interface ITokenState {
    startState: StackElement | null;
    tokens1: IToken[];
    endState: StackElement | null;
}

export interface ICommentOption {
    appRoot: string;
    grammarExtensions: IGrammarExtensions[];
    userLanguage: string;
}

export interface ICommentBlock {
    humanize?: boolean;
    range: Range;
    comment: string;
}

export type checkScopeFunction = (scopes: string[]) => boolean;

export class CommentParse {
    private _model: string[];
    private _lines: ITokenState[] = [];

    constructor(textDocument: TextDocument, private _grammar: IGrammar, private _multiLineMerge: boolean = false) {
        this._model = textDocument.getText().split('\n');
    }

    private _mergeComment(oldComment: string, newLine: string): string {
        if (this._multiLineMerge) {
            let lastLine = oldComment.substring(oldComment.lastIndexOf('\n') + 1);
            lastLine = lastLine.replace(/^([\/\ \*])*/, '');
            let currentLine: string = newLine.replace(/^([\/\ \*])*/, '');
            if ((lastLine >= 'A' && lastLine <= 'Z') && (lastLine.substring(lastLine.length - 1) !== '.') && (currentLine >= 'a' && currentLine <= 'z')) {
                return oldComment + ' ' + currentLine;
            }
        }
        return oldComment + '\n' + newLine;
    }

    private _parseTokensToLine(lineNumber: number): ITokenState[] {
        let state: StackElement | null = null;
        let lineLength = this._lines.length;
        if (lineLength) {
            state = this._lines[lineLength - 1].endState;
        }
        for (let i = lineLength; i <= lineNumber; i++) {
            let tokenizationResult = this._grammar.tokenizeLine(this._model[i], state);
            this._lines.push({
                startState: state,
                tokens1: tokenizationResult.tokens,
                endState: tokenizationResult.ruleStack
            });
            state = tokenizationResult.ruleStack;
        }

        return this._lines;
    }

    private _getTokensAtLine(lineNumber: number) {
        this._parseTokensToLine(lineNumber);
        return this._lines[lineNumber];
    }

    private _parseScopesText(tokens: IToken[], line: number, tokenIndex: number) {
        let tokenStartIndex = tokens[tokenIndex].startIndex;
        let tokenEndIndex = tokens[tokenIndex].endIndex;
        let tokenText = this._model[line].substring(tokenStartIndex, tokenEndIndex);

        let scopes: string[] = [];
        for (let i = tokens[tokenIndex].scopes.length - 1; i >= 0; i--) {
            scopes.push(escape(tokens[tokenIndex].scopes[i]))
        }

        return {
            tokenStartIndex,
            tokenEndIndex,
            tokenText,
            scopes
        }
    }

    public multiScope({ positionLine, dataTokens1, token1Index }: { dataTokens1: IToken[], token1Index: number, positionLine: number }, checkContentHandle: checkScopeFunction, maxLine: number, minLine: number, skipContentHandle?: (scope: string) => boolean) {

        let { tokenStartIndex, tokenEndIndex, tokenText } = this._parseScopesText(dataTokens1, positionLine, token1Index);

        let startLine = positionLine;
        let endLine = positionLine;
        for (let line = positionLine, tokens1 = dataTokens1, tokenIndex = token1Index; line >= minLine;) {
            let index;
            for (index = tokenIndex - 1; index >= 0; index -= 1) {
                let res = this._parseScopesText(tokens1, line, index);
                if (skipContentHandle && skipContentHandle(res.scopes[0])) {
                    continue;
                }
                if (checkContentHandle(res.scopes)) {
                    tokenText = res.tokenText + tokenText;
                    tokenStartIndex = res.tokenStartIndex;
                    startLine = line;
                } else {
                    break;
                }
            }
            if (index >= 0) {
                break
            }
            line -= 1;
            if (line >= minLine) {
                let data1 = this._getTokensAtLine(line);
                tokens1 = data1.tokens1;
                tokenIndex = tokens1.length;
                tokenText = '\n' + tokenText;
            }
        }
        for (let line = positionLine, tokens1 = dataTokens1, tokenIndex = token1Index; line <= maxLine;) {
            let index;
            for (index = tokenIndex + 1; index < tokens1.length; index += 1) {
                let res = this._parseScopesText(tokens1, line, index);
                if (skipContentHandle && skipContentHandle(res.scopes[0])) {
                    continue;
                }
                if (checkContentHandle(res.scopes)) {
                    tokenText = tokenText + res.tokenText;
                    tokenEndIndex = res.tokenEndIndex;
                    endLine = line;
                } else {
                    break;
                }
            }
            if (index < tokens1.length) {
                break
            }
            line += 1;
            if (line <= maxLine) {
                let data1 = this._getTokensAtLine(line);
                tokens1 = data1.tokens1;
                tokenIndex = -1;
                tokenText = tokenText + '\n';
            }
        }
        let newText = '';
        tokenText.split('\n').forEach(item => {
            newText = this._mergeComment(newText, item);
        });

        let range = Range.create({
            line: startLine,
            character: tokenStartIndex
        }, {
                line: endLine,
                character: tokenEndIndex
            });

        return {
            comment: newText,
            range: range
        }

    }

    public computeText(position: Position): ICommentBlock | null {
        function isCommentTranslate(scopes: string[]) {
            let arr = [
                'punctuation.definition.comment',
                'comment.block',
                'comment.line'
            ];

            return scopes.some(scope => {
                return arr.some(item => {
                    return scope.indexOf(item) === 0;
                });
            })
        }

        function skipCommentTranslate(scope: string) {
            return scope.indexOf('punctuation.whitespace.comment') === 0;
        }

        function isStringTranslate(scopes: string[]) {
            let scope = scopes[0];
            let arr = [
                'string.quoted',
                'constant.character.escape'
            ];

            return arr.some(item => {
                return scope.indexOf(item) === 0;
            });
        }

        function isBaseTranslate(scopes: string[]) {
            let scope = scopes[0];
            let arr = [
                'entity',
                'variable',
                'support',
                'meta.object-literal.key'
            ];

            return arr.some(item => {
                return scope.indexOf(item) === 0;
            });
        }

        let data = this._getTokensAtLine(position.line);
        let token1Index = 0;
        for (let i = data.tokens1.length - 1; i >= 0; i--) {
            let t = data.tokens1[i];
            if (position.character - 1 >= t.startIndex) {
                token1Index = i;
                break;
            }
        }

        let { tokenStartIndex, tokenEndIndex, tokenText, scopes } = this._parseScopesText(data.tokens1, position.line, token1Index);
        if (scopes && isStringTranslate(scopes)) {
            return this.multiScope({
                positionLine: position.line,
                dataTokens1: data.tokens1,
                token1Index
            }, isStringTranslate, position.line, position.line);
        }

        if (scopes && isCommentTranslate(scopes)) {
            return this.multiScope({
                positionLine: position.line,
                dataTokens1: data.tokens1,
                token1Index
            }, isCommentTranslate, this._model.length - 1, 0, skipCommentTranslate);
        }

        if (scopes && isBaseTranslate(scopes)) {
            let range = Range.create({
                line: position.line,
                character: tokenStartIndex
            }, {
                    line: position.line,
                    character: tokenEndIndex
                });

            return {
                humanize: true,
                comment: tokenText,
                range: range
            }
        }

        return null;
    }
}