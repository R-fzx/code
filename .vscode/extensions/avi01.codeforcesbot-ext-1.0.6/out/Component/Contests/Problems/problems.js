"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const axios_1 = require("../../../helper/axios/axios");
const cheerio = require("cheerio");
const path = require("path");
const problem_1 = require("./problem");
class Problems {
    constructor(userHandle, contestId, problemsArr) {
        this.problemsArr = [];
        this.userHandle = userHandle;
        this.contestId = contestId;
        if (problemsArr) {
            this.problemsArr = problemsArr;
        }
    }
    fetchProblems() {
        const contestApiUrl = `/api/contest.standings?contestId=${this.contestId}&handles=${this.userHandle}&showUnofficial=true`;
        return axios_1.default
            .get(contestApiUrl)
            .then((res) => {
            const data = res.data.result;
            const problemsArrList = data.problems;
            //console.log(problemsArrList);
            let promiseArr = [];
            problemsArrList.forEach((problemObject) => {
                const problemIndex = problemObject.index;
                const problemName = problemObject.name;
                //console.log("INDEX: " + problemObject.index);
                const problem = this.getProblemData(problemIndex, problemName, data);
                this.problemsArr.push(problem);
            });
        })
            .catch((err) => {
            console.error(err);
            return;
        });
    }
    getProblemData(index, name, data) {
        const problemIndex = index.charCodeAt(0) - "A".charCodeAt(0);
        const problem = new problem_1.default(this.userHandle, this.contestId, index);
        problem.name = name;
        data.rows.forEach((row) => {
            if (row.party.participantType === "CONTESTANT") {
                const problemObject = row.problemResults[problemIndex];
                problem.rejectedAttemptCount = problemObject.rejectedAttemptCount;
                problem.bestSubmissionTime = problemObject.bestSubmissionTimeSeconds;
                problem.points = problemObject.points;
            }
            else if (row.party.participantType === "PRACTICE") {
                const problemPractObject = row.problemResults[problemIndex];
                problem.practiceAc = problemPractObject.points !== 0;
                problem.practiceRejects = problemPractObject.rejectedAttemptCount;
            }
        });
        return problem;
    }
    toExplorer() {
        return this.problemsArr.map((problem) => {
            return problem.toExplorer();
        });
    }
}
exports.default = Problems;
//# sourceMappingURL=problems.js.map