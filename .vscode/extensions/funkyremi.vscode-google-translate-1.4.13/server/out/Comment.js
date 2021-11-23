"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.Comment = void 0;
const humanizeString = require("humanize-string");
const CommentParse_1 = require("./syntax/CommentParse");
const TextMateService_1 = require("./syntax/TextMateService");
const google_translate_open_api_1 = require("google-translate-open-api");
const languages = require("../../languages");
class Comment {
    constructor(extensions, _documents, _connection) {
        this._documents = _documents;
        this._connection = _connection;
        this._commentParseCache = new Map();
        this._setting = { multiLineMerge: false, preferredLanguage: extensions.userLanguage };
        this._textMateService = new TextMateService_1.TextMateService(extensions.grammarExtensions, extensions.appRoot);
        _documents.onDidClose(e => this._removeCommentParse(e.document));
        _documents.onDidChangeContent(e => this._removeCommentParse(e.document));
    }
    setSetting(newSetting) {
        if (!newSetting.preferredLanguage) {
            newSetting.preferredLanguage = this._setting.preferredLanguage;
        }
        this._setting = Object.assign(this._setting, newSetting);
        this._setting.preferredLanguage = languages.find(element => element.name === this._setting.preferredLanguage).value;
    }
    translate(text) {
        return __awaiter(this, void 0, void 0, function* () {
            const translationConfiguration = {
                to: this._setting.preferredLanguage,
            };
            return yield google_translate_open_api_1.default(text, translationConfiguration).then(res => {
                if (!!res && !!res.data) {
                    return res.data[0];
                }
                else {
                    return "Google Translate API Error";
                }
            });
        });
    }
    _getSelectionContainPosition(textDocumentPosition) {
        return __awaiter(this, void 0, void 0, function* () {
            return yield this._connection.sendRequest('selectionContains', textDocumentPosition);
        });
    }
    _removeCommentParse(textDocument) {
        const key = `${textDocument.languageId}-${textDocument.uri}`;
        this._commentParseCache.delete(key);
    }
    _getCommentParse(textDocument) {
        return __awaiter(this, void 0, void 0, function* () {
            const key = `${textDocument.languageId}-${textDocument.uri}`;
            if (this._commentParseCache.has(key)) {
                return this._commentParseCache.get(key);
            }
            const grammar = yield this._textMateService.createGrammar(textDocument.languageId);
            const parse = new CommentParse_1.CommentParse(textDocument, grammar, this._setting.multiLineMerge);
            this._commentParseCache.set(key, parse);
            return parse;
        });
    }
    getComment(textDocumentPosition) {
        return __awaiter(this, void 0, void 0, function* () {
            const textDocument = this._documents.get(textDocumentPosition.textDocument.uri);
            if (!textDocument)
                return null;
            const parse = yield this._getCommentParse(textDocument);
            const block = (yield this._getSelectionContainPosition(textDocumentPosition)) || parse.computeText(textDocumentPosition.position);
            if (block) {
                if (block.humanize) {
                    const humanize = humanizeString(block.comment);
                    const targetLanguageComment = yield this.translate(humanize);
                    return {
                        contents: [humanize + ' => ' + targetLanguageComment], range: block.range
                    };
                }
                else {
                    const targetLanguageComment = yield this.translate(block.comment);
                    return {
                        contents: [targetLanguageComment],
                        range: block.range
                    };
                }
            }
            return null;
        });
    }
}
exports.Comment = Comment;
//# sourceMappingURL=Comment.js.map