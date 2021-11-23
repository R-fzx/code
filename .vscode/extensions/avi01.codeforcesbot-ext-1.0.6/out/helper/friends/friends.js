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
const axios_1 = require("../axios/axios");
const data_1 = require("../data/data");
const login_1 = require("../Login/login");
const cheerio = require("cheerio");
function getFriends() {
    return __awaiter(this, void 0, void 0, function* () {
        if (!data_1.getCsrfToken()) {
            const logged = yield login_1.default();
            if (!logged) {
                return [];
            }
        }
        const friendsUrl = `/friends`;
        return axios_1.default.get(friendsUrl).then((res) => {
            const data = res.data;
            const userFriends = [];
            const $ = cheerio.load(data);
            const rows = $(".datatable a");
            rows.each((i, row) => {
                userFriends.push($(row).text());
            });
            return userFriends;
        });
    });
}
exports.default = getFriends;
//# sourceMappingURL=friends.js.map