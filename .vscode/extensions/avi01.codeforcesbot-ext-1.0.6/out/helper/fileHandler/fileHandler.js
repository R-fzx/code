"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const fs = require("fs");
const { join, sep } = require("path");
const vscode = require("vscode");
class FileHandler {
    static openFile(path, options) {
        return vscode.window.showTextDocument(vscode.Uri.file(path), options);
    }
    static findFile(path) {
        return vscode.workspace.findFiles(path).then((files) => {
            if (files.length === 0) {
                return null;
            }
            else {
                return files[0].fsPath;
            }
        });
    }
    static getProblemDetail(path) {
        const paths = path.split(sep);
        const size = paths.length;
        const regexPath = "^.*Codeforces,.*_.*,.*_.*,.*_.*\.cpp$";
        if (!paths.join(",").match(regexPath)) {
            return null;
        }
        const id = paths[size - 1].split("_")[0];
        const contestId = Number(paths[size - 3].split("_")[0]);
        const isNotNumber = isNaN(contestId);
        if (contestId && id && !isNotNumber) {
            return { contestId: contestId, id: id };
        }
        return null;
    }
    static solPath(contestId, problemId) {
        return join("Codeforces", `${contestId}*`, `${problemId}*`, `${problemId}*.cpp`);
    }
    static readFile(path, encoding = "ascii") {
        if (!this.checkExist(path)) {
            return null;
        }
        return fs.readFileSync(path, { encoding: encoding });
    }
    static readDir(path) {
        if (!this.checkExist(path)) {
            return null;
        }
        return fs.readdirSync(path);
    }
    static createDir(path, recursive = true) {
        if (!fs.existsSync(path)) {
            fs.mkdirSync(path, { recursive: recursive });
        }
    }
    static createFile(fileName, data) {
        fs.writeFileSync(fileName, data, (err) => (err ? this.handleError(err) : null));
    }
    static copyFile(fromCopy, toCopy) {
        fs.copyFileSync(fromCopy, toCopy, (err) => this.handleError(err));
    }
    static checkExist(path) {
        if (!fs.existsSync(path)) {
            return false;
        }
        return true;
    }
    static handleError(error) {
        console.log(error);
        throw new Error("Failure!!!!!");
    }
}
exports.default = FileHandler;
//# sourceMappingURL=fileHandler.js.map