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
exports.submitSolution = void 0;
const vscode_1 = require("vscode");
const fileHandler_1 = require("../fileHandler/fileHandler");
const axios_1 = require("../axios/axios");
const checker_1 = require("../checker/checker");
const data_1 = require("../data/data");
const login_1 = require("../Login/login");
const cheerio = require("cheerio");
const formData = require("form-data");
let contestId = 0;
let problemId = "";
let problemLabel = "";
let solFile;
function submitSolution(contestIdIn, problemIdIn) {
    return __awaiter(this, void 0, void 0, function* () {
        contestId = contestIdIn;
        problemId = problemIdIn;
        problemLabel = `${contestId}/${problemId}`;
        if (!contestId || !problemId) {
            vscode_1.window.showErrorMessage("Contest or Problem not found");
            return;
        }
        const solRegexPath = fileHandler_1.default.solPath(contestId, problemId);
        const isSolFile = yield fileHandler_1.default.findFile(solRegexPath);
        if (isSolFile === null) {
            vscode_1.window.showErrorMessage(`${problemLabel}: Problem Solution File not found`);
            return;
        }
        solFile = isSolFile;
        return vscode_1.window.withProgress({
            location: vscode_1.ProgressLocation.Notification,
            title: `${problemLabel} Submit`,
            cancellable: true,
        }, (progress, token) => __awaiter(this, void 0, void 0, function* () {
            console.log("Progress...");
            console.log(progress);
            console.log(token);
            token.onCancellationRequested(() => {
                console.log("User cancelled the submission");
                return;
            });
            progress.report({
                message: "Checking sample testcases...",
                increment: 10,
            });
            const checkerResult = yield checker_1.checker(contestId, problemId);
            progress.report({ message: "Sample testcases checked", increment: 20 });
            let userSelection;
            if (!checkerResult) {
                userSelection = yield vscode_1.window.showErrorMessage(problemLabel +
                    ": Solution failed in sample test cases. Do you want to submit any way?", "Submit", "Cancel");
            }
            else {
                userSelection = yield vscode_1.window.showInformationMessage(problemLabel +
                    ": Solution passed in sample test cases. Confirm to submit.", "Submit", "Cancel");
            }
            if (userSelection !== "Submit") {
                return;
            }
            progress.report({ message: "Submitting the solution...", increment: 20 });
            const submissionId = yield submit();
            console.log("submitResult:" + submissionId);
            if (!submissionId) {
                return;
            }
            progress.report({ message: "TESTING...", increment: 30 });
            const verdict = yield checkVerdict(parseInt(submissionId));
            console.log("verdict:" + verdict);
            return;
        }));
    });
}
exports.submitSolution = submitSolution;
function submit() {
    return __awaiter(this, void 0, void 0, function* () {
        const submitUrl = `/contest/${contestId}/submit`;
        const sol = fileHandler_1.default.readFile(solFile);
        if (!data_1.getCsrfToken()) {
            const logged = yield login_1.default();
            if (!logged) {
                vscode_1.window.showErrorMessage(problemLabel + ": User not logged in.");
                return;
            }
        }
        const form = new formData();
        form.append("action", "submitSolutionFormSubmitted");
        form.append("csrf_token", data_1.getCsrfToken());
        form.append("programTypeId", data_1.getSubmitCompiler());
        form.append("source", sol);
        form.append("submittedProblemIndex", problemId);
        const options = {
            method: "POST",
            url: submitUrl,
            headers: Object.assign({}, form.getHeaders()),
            data: form,
        };
        return axios_1.default(options)
            .then((res) => {
            const $ = cheerio.load(res.data);
            const sameSourceDiv = $(".error.for__source");
            if (sameSourceDiv.length > 0) {
                vscode_1.window.showErrorMessage(problemLabel + ": You have submitted exactly the same code before");
                return null;
            }
            const submissionId = $("a.view-source").attr("submissionid");
            console.log(submissionId);
            return submissionId;
        })
            .catch((res) => {
            console.error(res);
            return null;
        });
    });
}
function checkVerdict(submissionId) {
    return __awaiter(this, void 0, void 0, function* () {
        const URL = `/api/user.status?handle=${data_1.getUserHandle()}&from=1&count=40`;
        let verdict = "TESTING";
        while (verdict === "TESTING") {
            yield wait(2000);
            const res = yield axios_1.default.get(URL);
            const submissions = res.data.result;
            const submission = submissions.find((submission) => {
                return submission.id === submissionId;
            });
            verdict = submission.verdict;
        }
        if (verdict === "OK") {
            vscode_1.window.showInformationMessage(problemLabel + ": Solution Passed");
        }
        else {
            vscode_1.window.showErrorMessage(problemLabel + ": Solution Failed:- " + verdict);
        }
        return verdict;
    });
}
function wait(ms) {
    return __awaiter(this, void 0, void 0, function* () {
        return new Promise(resolve => {
            setTimeout(resolve, ms);
        });
    });
}
//# sourceMappingURL=submit.js.map