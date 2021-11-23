'use strict';
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");
const cp = require("child_process");
const os = require("os");
var channel = null;
const fullRange = doc => doc.validateRange(new vscode.Range(0, 0, Number.MAX_VALUE, Number.MAX_VALUE));
const LATEX_MODE = { language: 'latex', scheme: 'file' };
class OperatingSystem {
    constructor(name, file_ext, checker) {
        this.name = name;
        this.file_ext = file_ext;
        this.checker = checker;
    }
}
exports.OperatingSystem = OperatingSystem;
const windows = new OperatingSystem('win32', '.exe', 'where');
const linux = new OperatingSystem('linux', '.pl', 'which');
const mac = new OperatingSystem('darwin', '.pl', 'which');
class LaTexFormatter {
    constructor() {
        this.machine_os = os.platform();
        console.log(this.machine_os);
        this.formatter = 'latexindent';
    }
    formatDocument(document) {
        return new Promise((resolve, reject) => {
            let formatter = 'latexindent';
            let filename = document.fileName;
            if (this.machine_os == windows.name) {
                this.current_os = windows;
            }
            else if (this.machine_os == linux.name) {
                this.current_os = linux;
            }
            else if (this.machine_os == mac.name) {
                this.current_os = mac;
            }
            this.checkPath(this.current_os.checker).then((res) => {
                if (!res) {
                    showErrorMessage('Can not find latexindent in PATH!');
                    return resolve(null);
                }
                this.format(filename, document).then((res) => {
                    return resolve(res);
                });
            });
        });
    }
    checkPath(checker) {
        return new Promise((resolve, reject) => {
            cp.exec(checker + ' ' + this.formatter, (err, stdout, stderr) => {
                if (stdout == '') {
                    this.formatter += this.current_os.file_ext;
                    this.checkPath(checker).then((res) => {
                        if (res)
                            resolve(true);
                        else
                            resolve(false);
                    });
                }
                resolve(true);
            });
        });
    }
    format(filename, document) {
        return new Promise((resolve, reject) => {
            cp.exec(this.formatter + ' "' + filename + '"', (err, stdout, stderr) => {
                if (stdout != '') {
                    var edit = [vscode.TextEdit.replace(fullRange(document), stdout)];
                    return resolve(edit);
                }
                return resolve(null);
            });
        });
    }
}
exports.LaTexFormatter = LaTexFormatter;
function showErrorMessage(msg) {
    vscode.window.showErrorMessage(msg);
}
class LaTexDocumentRangeFormatter {
    constructor() {
        this.formatter = new LaTexFormatter();
    }
    provideDocumentFormattingEdits(document, options, token) {
        return document.save().then(() => {
            return this.formatter.formatDocument(document);
        });
    }
}
function activate(context) {
    channel = vscode.window.createOutputChannel('latex-formatter');
    context.subscriptions.push(vscode.languages.registerDocumentFormattingEditProvider(LATEX_MODE, new LaTexDocumentRangeFormatter()));
}
exports.activate = activate;
// this method is called when your extension is deactivated
function deactivate() {
}
exports.deactivate = deactivate;
//# sourceMappingURL=extension.js.map