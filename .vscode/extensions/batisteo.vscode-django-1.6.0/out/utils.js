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
exports.postInitHook = exports.readSnippets = void 0;
const path = require("path");
const fs = require("fs");
const toml = require("toml");
const folder = path.resolve(__dirname, "../completions/snippets/");
function readSnippets(name) {
    return toml.parse(fs.readFileSync(path.resolve(folder, name), "utf-8")).snippets;
}
exports.readSnippets = readSnippets;
function postInitHook() {
    return __awaiter(this, void 0, void 0, function* () { });
}
exports.postInitHook = postInitHook;
//# sourceMappingURL=utils.js.map