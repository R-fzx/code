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
exports.createContestFolders = void 0;
const vscode_1 = require("vscode");
const data_1 = require("../data/data");
const fileHandler_1 = require("../fileHandler/fileHandler");
const axios_1 = require("../axios/axios");
const problems_1 = require("../../Component/Contests/Problems/problems");
const cheerio = require("cheerio");
const { join } = require("path");
// #You need Puppeteer to create pdf. After installing Puppeteer (npm i puppeteer --save)
//uncomment required and these line to create pdf.)
// const puppeteer = require("puppeteer");
let puppeteer = null;
let contestCode = 0;
let pdfTrue = false;
let dir = "";
const assetsDir = join(__filename, "..", "..", "..", "..", "res", "template");
function createContestFolders(contestId, name, pdf = false) {
    const rootPath = vscode_1.workspace.workspaceFolders
        ? vscode_1.workspace.workspaceFolders[0]
        : null;
    if (!rootPath) {
        return;
    }
    vscode_1.window.withProgress({
        location: vscode_1.ProgressLocation.Notification,
        title: `${contestId} Folder`,
    }, (progress, token) => __awaiter(this, void 0, void 0, function* () {
        dir = join(rootPath.uri.fsPath, "Codeforces", name);
        console.log("Dir: " + dir);
        contestCode = contestId;
        pdfTrue = pdf;
        progress.report({ increment: 20, message: "Fetching folder..." });
        createReqFiles();
        progress.report({ increment: 20, message: "Fetching problems..." });
        const problemsId = yield getQuestions();
        progress.report({ increment: 60, message: "Opening Sol files..." });
        yield openProblemsFiles(problemsId);
        return;
    }));
}
exports.createContestFolders = createContestFolders;
function createReqFiles() {
    // await FileHandler.createDir(join(__dirname, "..", "Codeforces"));
    fileHandler_1.default.createDir(dir);
}
function getQuestions() {
    return __awaiter(this, void 0, void 0, function* () {
        console.log("Fetching the data...");
        const problemsId = yield getProblemsID();
        console.log(problemsId);
        let getTestCasesPromises = [];
        problemsId.forEach((problem) => {
            getTestCasesPromises.push(getProblemTestCase(problem));
        });
        if (puppeteer && pdfTrue) {
            getProblemStatement(problemsId);
        }
        yield Promise.all(getTestCasesPromises);
        return problemsId;
    });
}
function getProblemsID() {
    const problems = new problems_1.default(data_1.getUserHandle(), contestCode);
    return problems.fetchProblems().then(() => {
        return problems.problemsArr.map((problem) => {
            return { id: problem.id, name: problem.name };
        });
    });
}
function getProblemTestCase(problem) {
    return axios_1.default
        .get("/contest/" + contestCode + "/problem/" + problem.id)
        .then((res) => __awaiter(this, void 0, void 0, function* () {
        const $ = cheerio.load(res.data);
        let testCases = [];
        $(".sample-tests .input pre").each(function (i, elem) {
            testCases[i] = { input: $(elem).text().trim() };
        });
        $(".sample-tests .output pre").each(function (i, elem) {
            testCases[i] = Object.assign(Object.assign({}, testCases[i]), { output: $(elem).text().trim() + "\n" });
        });
        storeTestCases(problem, testCases);
    }))
        .catch((err) => handleError("Failed to get testcases"));
}
function storeTestCases(problem, testCases) {
    return __awaiter(this, void 0, void 0, function* () {
        const problemLabel = `${problem.id}_${problem.name}`;
        const problemDir = join(dir, problemLabel);
        let templateFile = data_1.getTemplateFile();
        if (!templateFile || !fileHandler_1.default.checkExist(templateFile)) {
            templateFile = join(assetsDir, "template.cpp");
        }
        fileHandler_1.default.createDir(problemDir);
        fileHandler_1.default.createDir(join(problemDir, "input"));
        fileHandler_1.default.createDir(join(problemDir, "output"));
        fileHandler_1.default.createDir(join(problemDir, "codeOutput"));
        if (!fileHandler_1.default.checkExist(join(problemDir, problemLabel + ".cpp"))) {
            fileHandler_1.default.copyFile(templateFile, join(problemDir, problemLabel + ".cpp"));
        }
        testCases.forEach((testCase, i) => {
            fileHandler_1.default.createFile(join(problemDir, "input", "input" + i + ".txt"), testCase.input);
            fileHandler_1.default.createFile(join(problemDir, "output", "output" + i + ".txt"), testCase.output);
        });
        console.log("Saved " + "TestCases " + problemLabel);
    });
}
function openProblemsFiles(problemsId) {
    return __awaiter(this, void 0, void 0, function* () {
        for (const { id, name } of problemsId) {
            yield openProblemSolFile(id, name);
        }
    });
}
function openProblemSolFile(id, name) {
    const problemSolFile = join(dir, `${id}_${name}`, `${id}_${name}.cpp`);
    const row = data_1.getTemplateLineNo() ? data_1.getTemplateLineNo() : 0;
    return fileHandler_1.default.openFile(problemSolFile, { preview: false }).then((editor) => {
        const lineCount = editor.document.lineCount;
        const cursorAtLine = lineCount >= row ? row - 1 : lineCount - 1;
        const range = editor.document.lineAt(cursorAtLine).range;
        editor.selection = new vscode_1.Selection(range.end, range.end);
        editor.revealRange(range);
        return;
    });
}
function getProblemStatement(problemsId) {
    problemsId.forEach((problem) => {
        const id = problem.id;
        printPDF("https://codeforces.com" + "/contest/" + contestCode + "/problem/" + id, dir + "/" + id + "/" + id + ".pdf", id);
    });
}
function printPDF(url, path, id) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const browser = yield puppeteer.launch({ headless: true });
            const page = yield browser.newPage();
            yield page.goto(url, { waitUntil: "networkidle0", timeout: 0 });
            yield page.pdf({ path: path });
            yield browser.close();
            console.log("Downloaded " + "Problem " + id);
        }
        catch (err) {
            handleError(err);
        }
    });
}
function handleError(error) {
    console.log("Got an Error. Please try again!!!");
    console.error(error);
    process.exit();
}
//# sourceMappingURL=createContestFolder.js.map