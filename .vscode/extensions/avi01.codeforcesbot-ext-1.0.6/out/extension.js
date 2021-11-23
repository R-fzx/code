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
exports.deactivate = exports.activate = void 0;
// The module 'vscode' contains the VS Code extensibility API
// Import the module and reference it with the alias vscode in your code below
const vscode = require("vscode");
const contests_1 = require("./Component/Contests/contests");
const ratings_1 = require("./Component/Rating/ratings");
const loginStatus_1 = require("./Component/LoginStatus/loginStatus");
const data_1 = require("./helper/data/data");
const createContestFolder_1 = require("./helper/createContestFolder/createContestFolder");
const checker_1 = require("./helper/checker/checker");
const fileHandler_1 = require("./helper/fileHandler/fileHandler");
const submit_1 = require("./helper/submit/submit");
// this method is called when your extension is activated
// your extension is activated the very first time the command is executed
function activate(context) {
    console.log('Congratulations, your extension "codeforcesbot-ext" is now active!');
    //set user name and password from vs code global state
    data_1.setUser(context.globalState.get("userHandle"), context.globalState.get("password"));
    setInterval(() => {
        vscode.commands.executeCommand("contests.refresh");
    }, 120000);
    //status bar login status
    const loginStatusBarItem = vscode.window.createStatusBarItem(vscode.StatusBarAlignment.Left, 1);
    loginStatus_1.setStatusBarItem(loginStatusBarItem);
    //TreeProvider
    const contestsProvider = new contests_1.ContestsProvider(vscode.workspace.rootPath ? vscode.workspace.rootPath : "/");
    const ratingsProvider = new ratings_1.RatingsProvider(vscode.workspace.rootPath ? vscode.workspace.rootPath : "/");
    vscode.window.registerTreeDataProvider("contests", contestsProvider);
    vscode.window.registerTreeDataProvider("ratings", ratingsProvider);
    //set Configuration
    updateConfiguration();
    //update Configuration
    vscode.workspace.onDidChangeConfiguration(() => {
        updateConfiguration();
    });
    //refresh view
    const contestsRefreshCommand = vscode.commands.registerCommand("contests.refresh", (node) => {
        console.log("REFRESH.....");
        console.log(node);
        contestsProvider.refresh();
    });
    const ratingsRefreshCommand = vscode.commands.registerCommand("ratings.refresh", (node) => {
        console.log("REFRESH.....");
        console.log(node);
        ratingsProvider.refresh();
    });
    //open solution file
    const openSolCommand = vscode.commands.registerCommand("contest.openSol", (node) => {
        console.log("Opening File.....");
        const solRegexPath = fileHandler_1.default.solPath(node.contestId, node.id);
        fileHandler_1.default.findFile(solRegexPath).then((file) => {
            if (file === null) {
                vscode.window.showErrorMessage("File not found!!! Run create contest folder");
                return;
            }
            fileHandler_1.default.openFile(file, { preview: false });
        });
    });
    //create contest folder
    const createContestFoldersCommand = vscode.commands.registerCommand("contest.createContestFolders", (node) => {
        console.log("Explorer.....");
        console.log(node);
        if (node && node.explorerId) {
            createContestFolder_1.createContestFolders(node.explorerId, node.label);
        }
    });
    // check solution of sample testcases
    const checkerSolCommand = vscode.commands.registerCommand("contest.checkerSol", (node) => __awaiter(this, void 0, void 0, function* () {
        console.log("Checker.....");
        const detail = getContestId(node);
        if (!detail) {
            vscode.window.showErrorMessage(node.fsPath + ": \nFile does not belong to codeforces contest");
            return;
        }
        const checkerResult = yield checker_1.checker(detail.contestId, detail.problemId);
        console.log("CheckerResult:- ", checkerResult);
    }));
    // check solution of sample testcases
    const submitSolCommand = vscode.commands.registerCommand("contest.submitSol", (node) => __awaiter(this, void 0, void 0, function* () {
        console.log("Submit.....");
        const detail = getContestId(node);
        if (!detail) {
            vscode.window.showErrorMessage(node.fsPath + ": \nFile does not belong to codeforces contest");
            return;
        }
        yield submit_1.submitSolution(detail.contestId, detail.problemId);
        contestsProvider.refresh();
    }));
    //update user and password
    const loginCommand = vscode.commands.registerCommand("codeforcesbot-ext.login", () => __awaiter(this, void 0, void 0, function* () {
        vscode.window.showInputBox({
            placeHolder: "Enter user",
            prompt: "Enter user name of Codeforces account",
            validateInput: (userHandle) => {
                return userHandle !== null &&
                    userHandle !== undefined &&
                    userHandle !== ""
                    ? null
                    : "User name can not be empty";
            },
        }).then((userHandle) => __awaiter(this, void 0, void 0, function* () {
            const password = yield vscode.window.showInputBox({
                placeHolder: "Enter password",
                prompt: "Enter password of Codeforces account",
            });
            console.log(userHandle, password);
            context.globalState.update("userHandle", userHandle);
            context.globalState.update("password", password);
            data_1.setUser(userHandle, password);
            data_1.resetCookie();
            contestsProvider.refresh();
        }));
    }));
    context.subscriptions.push(contestsRefreshCommand);
    context.subscriptions.push(ratingsRefreshCommand);
    context.subscriptions.push(openSolCommand);
    context.subscriptions.push(createContestFoldersCommand);
    context.subscriptions.push(checkerSolCommand);
    context.subscriptions.push(submitSolCommand);
    context.subscriptions.push(loginCommand);
}
exports.activate = activate;
function updateConfiguration() {
    const configuration = vscode.workspace.getConfiguration("codeforcesBot");
    console.log("Configuration: ");
    const compileCommand = configuration.compile.command;
    const templateFile = configuration.template.templateFile;
    const templateLineNo = configuration.template.templateLineNumber;
    data_1.setConfiguration(compileCommand, templateFile, templateLineNo);
}
function getContestId(node) {
    if (node && node.data && node.data.contestId && node.data.id) {
        return { contestId: node.data.contestId, problemId: node.data.id };
    }
    else {
        const problemDetail = fileHandler_1.default.getProblemDetail(node.fsPath);
        if (problemDetail && problemDetail.contestId && problemDetail.id) {
            return {
                contestId: problemDetail.contestId,
                problemId: problemDetail.id,
            };
        }
    }
    return null;
}
// this method is called when your extension is deactivated
function deactivate() { }
exports.deactivate = deactivate;
//# sourceMappingURL=extension.js.map