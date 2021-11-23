"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.getRunningContests = void 0;
const vscode = require("vscode");
const axios_1 = require("../../../helper/axios/axios");
const explorer_1 = require("../../../Container/explorer");
function getRunningContests(limit) {
    const URL = "https://codeforces.com/api/contest.list";
    return axios_1.default.get(URL).then((res) => {
        const allContests = res.data["result"];
        const allRunningContests = allContests.filter((contest) => {
            return contest.phase !== "BEFORE" && contest.phase !== "FINISHED" && contest.id !== 1308 && contest.id !== 1309;
        });
        const limitedRunningContests = allRunningContests
            .sort((contestA, contestB) => contestA.startTimeSeconds - contestB.startTimeSeconds)
            .slice(0, limit);
        console.log(limitedRunningContests);
        const runningContestsExplorer = limitedRunningContests.map((contest) => {
            const contestDate = new Date(contest.startTimeSeconds * 1000);
            let contestDetail = `${contest.name} : \n${contestDate.toString()}`;
            return new explorer_1.Explorer(contest.name, "RunningContest", vscode.TreeItemCollapsibleState.Collapsed, contest.id, "Running", contestDetail);
        });
        return Promise.resolve(runningContestsExplorer);
    });
}
exports.getRunningContests = getRunningContests;
//# sourceMappingURL=runningContest.js.map