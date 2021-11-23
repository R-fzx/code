"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");
const explorer_1 = require("../../../Container/explorer");
const axios_1 = require("../../../helper/axios/axios");
const data_1 = require("../../../helper/data/data");
class Standing {
    constructor(userHandle, contestId, rank = "0", points = 0) {
        this.userHandle = userHandle;
        this.contestId = contestId;
        this.rank = rank;
        this.points = points;
    }
    getStanding() {
        const standingUrl = `/api/contest.standings?contestId=${this.contestId}&handles=${this.userHandle}&showUnofficial=true`;
        return axios_1.default.get(standingUrl).then((res) => {
            console.log(res);
            const data = res.data.result.rows;
            const handlesContestData = data.filter((handleData) => {
                return handleData.party.participantType === "CONTESTANT";
            });
            if (handlesContestData.length === 0) {
                return;
            }
            const handleRank = handlesContestData[0].rank;
            const handlePoints = handlesContestData[0].points;
            this.rank = handleRank;
            this.points = handlePoints;
        });
    }
    toExplorer() {
        let label = `${this.rank} : ${this.userHandle}`;
        if (this.userHandle === data_1.getUserHandle()) {
            label = `---> ${this.rank} : ${this.userHandle}`;
        }
        const problemExplorer = new explorer_1.Explorer(label, "Standing", vscode.TreeItemCollapsibleState.None, this.contestId, "Standing");
        return problemExplorer;
    }
}
exports.default = Standing;
//# sourceMappingURL=standing.js.map