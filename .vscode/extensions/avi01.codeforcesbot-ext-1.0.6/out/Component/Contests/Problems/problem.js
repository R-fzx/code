"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");
const explorer_1 = require("../../../Container/explorer");
const axios_1 = require("../../../helper/axios/axios");
const path = require("path");
const resPath = path.join(__filename, "..", "..", "..", "..", "..", "res");
class Problem {
    constructor(userHandle, contestId, id) {
        this.name = "";
        this.points = 0;
        this.rejectedAttemptCount = 0;
        this.bestSubmissionTime = 0;
        this.practiceAc = false;
        this.practiceRejects = 0;
        this.userHandle = userHandle;
        this.contestId = contestId;
        this.id = id;
    }
    fetchProblemData() {
        const problemApiUrl = `/api/contest.standings?contestId=${this.contestId}&handles=${this.userHandle}&showUnofficial=true`;
        return axios_1.default.get(problemApiUrl).then((res) => {
            const data = res.data.result;
            this.name = data.problems.filter((problem) => {
                return problem.index === this.id;
            })[0].name;
            const problemIndex = this.id.charCodeAt(0) - "A".charCodeAt(0);
            data.rows.forEach((row) => {
                if (row.party.participantType === "CONTESTANT") {
                    const problemObject = row.problemResults[problemIndex];
                    this.rejectedAttemptCount = problemObject.rejectedAttemptCount;
                    this.bestSubmissionTime = problemObject.bestSubmissionTimeSeconds;
                    this.points = problemObject.points;
                }
                else if (row.party.participantType === "PRACTICE") {
                    const problemPractObject = row.problemResults[problemIndex];
                    this.practiceAc = problemPractObject.points !== 0;
                    this.practiceRejects = problemPractObject.rejectedAttemptCount;
                }
            });
        });
    }
    setProblemData(name, points, rejectedAttemptCount, bestSubmissionTime) {
        this.name = name;
        this.points = points;
        this.rejectedAttemptCount = rejectedAttemptCount;
        this.bestSubmissionTime = bestSubmissionTime;
    }
    toExplorer() {
        let lightIconPath = null;
        let darkIconPath = null;
        let label = `${this.id}_${this.name}`;
        if (this.points !== 0 || this.practiceAc) {
            lightIconPath = path.join(resPath, "img", "light", "ac.svg");
            darkIconPath = path.join(resPath, "img", "dark", "ac.svg");
            if (this.points !== 0) {
                const waCount = this.rejectedAttemptCount === 0 ? " " : this.rejectedAttemptCount;
                label = `${this.id}_${this.name} | +${waCount}`;
            }
        }
        else if (this.rejectedAttemptCount !== 0 || this.practiceRejects !== 0) {
            lightIconPath = path.join(resPath, "img", "light", "wa.svg");
            darkIconPath = path.join(resPath, "img", "dark", "wa.svg");
            if (this.rejectedAttemptCount !== 0) {
                label = `${this.id}_${this.name} | -${this.rejectedAttemptCount}`;
            }
        }
        // console.log(this.id,this.name,label);
        const problemExplorer = new explorer_1.Explorer(label, "Problem", vscode.TreeItemCollapsibleState.None, this.contestId, "Problem", this.name, this, lightIconPath, darkIconPath, {
            command: 'contest.openSol',
            title: '',
            arguments: [this]
        });
        return problemExplorer;
    }
}
exports.default = Problem;
//# sourceMappingURL=problem.js.map