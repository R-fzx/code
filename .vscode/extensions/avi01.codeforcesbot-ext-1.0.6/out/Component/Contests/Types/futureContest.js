"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.getFutureContests = void 0;
const vscode = require("vscode");
const axios_1 = require("../../../helper/axios/axios");
const explorer_1 = require("../../../Container/explorer");
function getFutureContests(limit) {
    const URL = "https://codeforces.com/api/contest.list";
    return axios_1.default.get(URL).then((res) => {
        const allContests = res.data["result"];
        const allFutureContests = allContests.filter((contest) => {
            return contest.phase === "BEFORE";
        });
        const limitedFutureContests = allFutureContests
            .sort((contestA, contestB) => contestA.startTimeSeconds - contestB.startTimeSeconds)
            .slice(0, limit);
        console.log(limitedFutureContests);
        const futureContestsExplorer = limitedFutureContests.map((contest) => {
            const contestDate = new Date(contest.startTimeSeconds * 1000);
            let contestDetail = `${contest.name} : \n${contestDate.toString()}`;
            return new explorer_1.Explorer(contest.name, "FutureContest", vscode.TreeItemCollapsibleState.None, contest.id, "Future", contestDetail);
        });
        return Promise.resolve(futureContestsExplorer);
    });
}
exports.getFutureContests = getFutureContests;
//# sourceMappingURL=futureContest.js.map