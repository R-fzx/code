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
const axios_1 = require("./../axios/axios");
const cheerio = require("cheerio");
const { join } = require("path");
// #You need Puppeteer to create pdf. After installing Puppeteer (npm i puppeteer --save)
//uncomment required and these line to create pdf.)
// const puppeteer = require("puppeteer");
let puppeteer = null;
let contestCode = 0;
let pdfTrue = false;
let dir = '';
const assetsDir = join(__filename, "..", "..", "..", "..", "res", "template");
function createContestFolders(contestId, name, pdf = false) {
    const rootPath = vscode_1.workspace.workspaceFolders ? vscode_1.workspace.workspaceFolders[0] : null;
    if (!rootPath) {
        return;
    }
    dir = rootPath.uri.path + "/Codeforces/" + name;
    console.log("Dir: " + dir);
    contestCode = contestId;
    pdfTrue = pdf;
    createReqFiles();
    getQuestions();
}
exports.createContestFolders = createContestFolders;
function createReqFiles() {
    return __awaiter(this, void 0, void 0, function* () {
        yield fileHandler_1.default.createDir(join(__dirname, "..", "Codeforces"));
        yield fileHandler_1.default.createDir(dir);
    });
}
function getQuestions() {
    return __awaiter(this, void 0, void 0, function* () {
        console.log("Fetching the data...");
        const problemsId = yield getProblemsID();
        let getTestCasesPromises = [];
        problemsId.forEach((id) => {
            getTestCasesPromises.push(getProblemTestCase(id));
        });
        if (puppeteer && (pdfTrue)) {
            getProblemStatement(problemsId);
        }
        yield Promise.all(getTestCasesPromises);
        openProblemsFiles(problemsId);
    });
}
function getProblemsID() {
    return axios_1.default
        .get("/contest/" + contestCode)
        .then((res) => {
        const $ = cheerio.load(res.data);
        const problemsTable = $(".id a");
        let problemsId = [];
        problemsTable.each(function (i, elem) {
            problemsId[i] = $(elem).text().trim();
        });
        return problemsId;
    })
        .catch((err) => handleError("Failed to get problems"));
}
function getProblemTestCase(problemId) {
    return axios_1.default
        .get("/contest/" + contestCode + "/problem/" + problemId)
        .then((res) => __awaiter(this, void 0, void 0, function* () {
        const $ = cheerio.load(res.data);
        let testCases = [];
        $(".sample-tests .input pre").each(function (i, elem) {
            testCases[i] = { input: $(elem).text().trim() };
        });
        $(".sample-tests .output pre").each(function (i, elem) {
            testCases[i] = Object.assign(Object.assign({}, testCases[i]), { output: $(elem).text().trim() + "\n" });
        });
        storeTestCases(problemId, testCases);
    }))
        .catch((err) => handleError("Failed to get testcases"));
}
function storeTestCases(problemId, testCases) {
    return __awaiter(this, void 0, void 0, function* () {
        const problemDir = join(dir, problemId);
        fileHandler_1.default.createDir(problemDir);
        fileHandler_1.default.createDir(join(problemDir, "input"));
        fileHandler_1.default.createDir(join(problemDir, "output"));
        fileHandler_1.default.createDir(join(problemDir, "codeOutput"));
        if (!fileHandler_1.default.checkExist(join(problemDir, problemId + ".cpp"))) {
            if (!fileHandler_1.default.checkExist(join(__dirname, "template.cpp"))) {
                yield fileHandler_1.default.copyFile(join(assetsDir, "template.cpp"), join(problemDir, problemId + ".cpp"));
            }
            else {
                yield fileHandler_1.default.copyFile(join(__dirname, "template.cpp"), join(problemDir, problemId + ".cpp"));
            }
        }
        testCases.forEach((testCase, i) => {
            if (i === 0) {
                fileHandler_1.default.createFile(join(problemDir, problemId + "_in.txt"), testCase.input);
                fileHandler_1.default.createFile(join(problemDir, problemId + "_out.txt"), testCase.output);
            }
            fileHandler_1.default.createFile(join(problemDir, "input", "input" + i + ".txt"), testCase.input);
            fileHandler_1.default.createFile(join(problemDir, "output", "output" + i + ".txt"), testCase.output);
        });
        console.log("Saved " + "TestCases " + problemId);
    });
}
function openProblemsFiles(problemsId) {
    return __awaiter(this, void 0, void 0, function* () {
        for (const id of problemsId) {
            yield openProblemSolFile(id);
        }
    });
}
function openProblemSolFile(problemId) {
    const problemSolFile = join(dir, problemId, problemId + ".cpp");
    const row = data_1.getTemplateLineNo() ? data_1.getTemplateLineNo() : 0;
    return vscode_1.window.showTextDocument(vscode_1.Uri.file(problemSolFile), { preview: false }).then((editor) => __awaiter(this, void 0, void 0, function* () {
        const range = editor.document.lineAt(row - 1).range;
        editor.selection = new vscode_1.Selection(range.end, range.end);
        editor.revealRange(range);
        return;
    }));
}
function getProblemStatement(problemsId) {
    problemsId.forEach((id) => {
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
//# sourceMappingURL=createContestFolders.js.map