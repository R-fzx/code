"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.getPastContests = void 0;
const vscode = require("vscode");
const axios_1 = require("../../../helper/axios/axios");
const explorer_1 = require("../../../Container/explorer");
function getPastContests(limit) {
    const URL = "https://codeforces.com/api/contest.list";
    return axios_1.default.get(URL).then((res) => {
        const allContests = res.data["result"];
        const allPastContests = allContests.filter((contest) => {
            return contest.phase === "FINISHED";
        });
        const limitedPastContests = allPastContests
            .sort((contestA, contestB) => contestB.startTimeSeconds - contestA.startTimeSeconds)
            .slice(0, limit);
        console.log(limitedPastContests);
        const pastContestsExplorer = limitedPastContests.map((contest) => {
            const contestDate = new Date(contest.startTimeSeconds * 1000);
            let contestDetail = `${contest.name} : \n${contestDate.toString()}`;
            return new explorer_1.Explorer(contest.name, "PastContest", vscode.TreeItemCollapsibleState.Collapsed, contest.id, "Past", contestDetail);
        });
        return Promise.resolve(pastContestsExplorer);
    });
}
exports.getPastContests = getPastContests;
//# sourceMappingURL=pastContest.js.map