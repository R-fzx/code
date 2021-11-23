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
exports.checker = void 0;
const vscode = require("vscode");
const data_1 = require("../data/data");
const fileHandler_1 = require("../fileHandler/fileHandler");
const cp = require("child_process");
const fs = require("fs");
const { join, basename, sep } = require("path");
const { table } = require("table");
let contestCode = 0;
let problemId = "A";
let problemLabel = "";
let solPath = "";
let problemFolder = "";
function checker(contestCodeIn, problemIdIn) {
    contestCode = contestCodeIn;
    problemId = problemIdIn;
    problemLabel = `${contestCode}/${problemId}`;
    return vscode.window.withProgress({
        location: vscode.ProgressLocation.Notification,
        title: `${problemLabel} Checker`,
    }, (progress, token) => {
        console.log("Progress...");
        console.log(progress);
        console.log(token);
        return check(progress);
    });
}
exports.checker = checker;
function check(progress) {
    return new Promise((resolve) => {
        if (!contestCode || !problemId) {
            vscode.window.showErrorMessage("Wrong Problem for checking");
            resolve(false);
            return;
        }
        const solRegexPath = fileHandler_1.default.solPath(contestCode, problemId);
        return fileHandler_1.default.findFile(solRegexPath).then((file) => {
            if (file === null) {
                resolve(false);
                vscode.window.showErrorMessage(`${problemLabel}: Problem Solution File not found`);
                return;
            }
            solPath = file;
            problemFolder = join(solPath, "..");
            console.log("FileFound: " + solPath);
            progress.report({ increment: 10, message: "Compiling..." });
            compileProgram()
                .then((compiled) => {
                if (!compiled) {
                    resolve(false);
                    return;
                }
                progress.report({ increment: 50, message: "Checking Solution..." });
                return getOutput();
            })
                .then((output) => {
                if (!output) {
                    resolve(false);
                    return;
                }
                progress.report({ increment: 100, message: "Checking Complete." });
                resolve(true);
            });
        });
    });
}
function compileProgram() {
    const compileCommand = data_1.getCompileCommand();
    const solFile = basename(solPath);
    const cmd = `${compileCommand} -o compiledSol "${solFile}"`;
    return execShell(cmd, problemFolder)
        .then((stdout) => {
        console.log("Compiled Successfully");
        return true;
    })
        .catch((error) => {
        vscode.window
            .showErrorMessage(`${problemLabel}: Compilation Error!!!`, "See Error")
            .then((clicked) => {
            if (clicked === "See Error") {
                const checkerOut = join(problemFolder, "checkerOut.txt");
                fileHandler_1.default.createFile(checkerOut, error);
                fileHandler_1.default.openFile(checkerOut);
            }
        });
        return false;
    });
}
function getOutput() {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const fileName = join(problemFolder, "sol");
            const inputFolder = join(problemFolder, "input");
            const outputFolder = join(problemFolder, "output");
            const codeOutputFolder = join(problemFolder, "codeOutput");
            if (!fileHandler_1.default.checkExist(inputFolder) ||
                !fileHandler_1.default.checkExist(outputFolder)) {
                handleError("TestCases folder missing");
                return;
            }
            fileHandler_1.default.createDir(codeOutputFolder);
            const inputs = fileHandler_1.default.readDir(inputFolder);
            const outputs = fileHandler_1.default.readDir(outputFolder);
            let testCases = [];
            let failedCount = 0;
            let i = 0;
            for (const inputNo of inputs) {
                const outputFile = join(outputFolder, outputs[i]);
                const inputFile = join(inputFolder, inputNo);
                const codeOutputFile = join(codeOutputFolder, `codeOutput${i}.txt`);
                const solFile = `.${sep}compiledSol`;
                const inFile = join(".", basename(inputFolder), basename(inputFile));
                const cmd = yield execShell("timeout 2s echo Working").then((stdout) => {
                    console.log(stdout);
                    return `timeout 2s  "${solFile}" < "${inFile}"`;
                }).catch((error) => {
                    return `"${solFile}" < "${inFile}"`;
                });
                const runCorrectly = yield execShell(cmd, problemFolder)
                    .then((stdout) => {
                    console.log(stdout);
                    const modOut = stdout
                        .replace(/(\r\n)+/g, "\n")
                        .replace(/\r+/g, "\n")
                        .trim();
                    fileHandler_1.default.createFile(codeOutputFile, modOut);
                    if (!testOutput(codeOutputFile, outputFile, i)) {
                        testCases.push({
                            no: i,
                            input: inputFile,
                            output: outputFile,
                            codeOutput: codeOutputFile,
                            verdict: false,
                        });
                        failedCount += 1;
                    }
                    else {
                        testCases.push({
                            no: i,
                            input: inputFile,
                            output: outputFile,
                            codeOutput: codeOutputFile,
                            verdict: true,
                        });
                    }
                    return true;
                })
                    .catch((error) => {
                    console.log(error);
                    vscode.window
                        .showErrorMessage(`${problemLabel}: Solution do not run for the input ${i}`, "See Error")
                        .then((clicked) => {
                        if (clicked === "See Error") {
                            const checkerOut = join(problemFolder, "checkerOut.txt");
                            fileHandler_1.default.createFile(checkerOut, error);
                            fileHandler_1.default.openFile(checkerOut);
                        }
                    });
                    return false;
                });
                if (!runCorrectly) {
                    return false;
                }
                i++;
            }
            let message = "All Sample TestCases Passed";
            if (failedCount !== 0) {
                message = "\n" + failedCount + " Sample TestCases failed";
            }
            vscode.window
                .showInformationMessage(`${problemLabel}: ${message}`, "See Result")
                .then((clicked) => {
                if (clicked === "See Result") {
                    outputTestCases(testCases);
                }
            });
            return failedCount === 0;
        }
        catch (err) {
            return false;
        }
    });
}
function testOutput(codeOutputFile, outputFile, testNo) {
    const codeOutput = fileHandler_1.default.readFile(codeOutputFile).toString().trim();
    const output = fileHandler_1.default.readFile(outputFile).toString().trim();
    if (codeOutput === output) {
        console.log("TestCase " + testNo + " passed \u2714");
        return 1;
    }
    else {
        console.log("TestCase " + testNo + " failed \u2718");
        return 0;
    }
}
function outputTestCases(testCases) {
    let data = [["No", "Input", "Output", "CodeOutput", "Verdict"]];
    testCases.forEach((testCase) => {
        const no = testCase.no;
        const input = fs.readFileSync(testCase.input).toString();
        const output = fs.readFileSync(testCase.output).toString();
        const codeOutput = fs.readFileSync(testCase.codeOutput).toString();
        const verdict = testCase.verdict ? "Passed" : "Failed";
        data.push([no, input, output, codeOutput, verdict]);
    });
    const outputData = table(data);
    const checkerOut = join(problemFolder, "checkerOut.txt");
    fileHandler_1.default.createFile(checkerOut, outputData);
    fileHandler_1.default.openFile(checkerOut);
}
function execShell(cmd, execDir) {
    return new Promise((resolve, reject) => {
        cp.exec(cmd, { cwd: execDir }, (err, out) => {
            if (err) {
                return reject(err);
            }
            return resolve(out);
        });
    });
}
function handleError(error) {
    console.log("Got an Error. Please try again!!!");
    console.error(error);
}
//# sourceMappingURL=checker.js.map