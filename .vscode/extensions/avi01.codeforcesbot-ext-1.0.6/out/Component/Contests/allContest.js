"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.getContests = void 0;
const axios_1 = require("../../helper/axios/axios");
const explorer_1 = require("../../Container/explorer");
function getContests(type, limit, expandable) {
    const URL = "/api/contest.list";
    return axios_1.default.get(URL).then((res) => {
        const allContests = res.data["result"];
        const typeContests = allContests.filter((contest) => {
            // console.log(contest);
            return (type === 'Past' && contest.phase === "FINISHED") ||
                (type === 'Future' && contest.phase === "BEFORE") ||
                (type === 'Running' && contest.phase !== "BEFORE" && contest.phase !== "FINISHED" && contest.id !== 1308 && contest.id !== 1309);
            return false;
        });
        const limitedContests = typeContests
            .sort((contestA, contestB) => contestB.startTimeSeconds - contestA.startTimeSeconds)
            .slice(0, limit);
        // console.log(limitedContests);
        const contestsExplorer = limitedContests.map((contest) => {
            const contestDate = new Date(contest.startTimeSeconds * 1000);
            let contestDetail = `${contest.name} : \n${contestDate.toString()}`;
            return new explorer_1.Explorer(`${contest.id}_${contest.name}`, `${type}Contest`, expandable, contest.id, "Past", contestDetail);
        });
        return Promise.resolve(contestsExplorer);
    });
}
exports.getContests = getContests;
//# sourceMappingURL=allContest.js.map