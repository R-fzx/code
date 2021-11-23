'use strict';
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
exports.activate = void 0;
const vscode_1 = require("vscode");
const definitionProvider_1 = require("./providers/definitionProvider");
const completionItemProvider_1 = require("./completions/completionItemProvider");
const utils_1 = require("./utils");
function activate(context) {
    return __awaiter(this, void 0, void 0, function* () {
        const definitions = new definitionProvider_1.TemplatePathProvider();
        context.subscriptions.push(vscode_1.languages.registerDefinitionProvider(definitions.selector, definitions));
        const djangoPythonSnippets = new completionItemProvider_1.DjangoPythonCompletionItemProvider();
        context.subscriptions.push(vscode_1.languages.registerCompletionItemProvider(djangoPythonSnippets.selector, djangoPythonSnippets));
        const djangoAdminSnippets = new completionItemProvider_1.DjangoAdminCompletionItemProvider();
        context.subscriptions.push(vscode_1.languages.registerCompletionItemProvider(djangoAdminSnippets.selector, djangoAdminSnippets));
        const djangoFormSnippets = new completionItemProvider_1.DjangoFormCompletionItemProvider();
        context.subscriptions.push(vscode_1.languages.registerCompletionItemProvider(djangoFormSnippets.selector, djangoFormSnippets));
        const djangoManagerSnippets = new completionItemProvider_1.DjangoManagerCompletionItemProvider();
        context.subscriptions.push(vscode_1.languages.registerCompletionItemProvider(djangoManagerSnippets.selector, djangoManagerSnippets));
        const djangoMigrationSnippets = new completionItemProvider_1.DjangoMigrationCompletionItemProvider();
        context.subscriptions.push(vscode_1.languages.registerCompletionItemProvider(djangoMigrationSnippets.selector, djangoMigrationSnippets));
        const djangoModelSnippets = new completionItemProvider_1.DjangoModelCompletionItemProvider();
        context.subscriptions.push(vscode_1.languages.registerCompletionItemProvider(djangoModelSnippets.selector, djangoModelSnippets));
        const djangoViewSnippets = new completionItemProvider_1.DjangoViewCompletionItemProvider();
        context.subscriptions.push(vscode_1.languages.registerCompletionItemProvider(djangoViewSnippets.selector, djangoViewSnippets));
        const djangoTemplatetagsSnippets = new completionItemProvider_1.DjangoTemplatetagsCompletionItemProvider();
        context.subscriptions.push(vscode_1.languages.registerCompletionItemProvider(djangoTemplatetagsSnippets.selector, djangoTemplatetagsSnippets));
        const djangoUrlSnippets = new completionItemProvider_1.DjangoUrlCompletionItemProvider();
        context.subscriptions.push(vscode_1.languages.registerCompletionItemProvider(djangoUrlSnippets.selector, djangoUrlSnippets));
        utils_1.postInitHook();
    });
}
exports.activate = activate;
//# sourceMappingURL=extension.js.map