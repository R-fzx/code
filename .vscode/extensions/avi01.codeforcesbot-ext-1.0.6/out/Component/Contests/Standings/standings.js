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
const axios_1 = require("../../../helper/axios/axios");
const data_1 = require("../../../helper/data/data");
const standing_1 = require("./standing");
const login_1 = require("../../../helper/Login/login");
const cheerio = require("cheerio");
class Standings {
    constructor(userHandle, contestId) {
        this.userHandle = userHandle;
        this.contestId = contestId;
        this.usersStanding = [];
    }
    getStandings() {
        return __awaiter(this, void 0, void 0, function* () {
            if (!data_1.getCsrfToken()) {
                const logged = yield login_1.default();
                if (!logged) {
                    return;
                }
            }
            const standingUrl = `/contest/${this.contestId}/standings/friends/true`;
            return axios_1.default.get(standingUrl).then((res) => {
                const $ = cheerio.load(res.data);
                const rows = $("tr");
                console.log(rows);
                rows.each((i, row) => {
                    if (i === 0) {
                        return;
                    }
                    const rank = $(row).find("td").first().text().replace("\n", "").trim();
                    const user = $(row).find("td a").first().text().trim();
                    const point = $(row).find("td span").first().text().trim();
                    console.log(rank);
                    if (rank.length <= 0) {
                        return;
                    }
                    const standing = new standing_1.default(user, this.contestId, rank, point);
                    this.usersStanding.push(standing);
                });
            });
        });
    }
    toExplorer() {
        return this.usersStanding.map((standing) => {
            return standing.toExplorer();
        });
    }
}
exports.default = Standings;
//# sourceMappingURL=standings.js.map