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
exports.RatingsProvider = void 0;
const axios_1 = require("../../helper/axios/axios");
const vscode = require("vscode");
const explorer_1 = require("../../Container/explorer");
const data_1 = require("../../helper/data/data");
const friends_1 = require("../../helper/friends/friends");
class RatingsProvider {
    constructor(workspaceRoot) {
        this.workspaceRoot = workspaceRoot;
        this._onDidChangeTreeData = new vscode.EventEmitter();
        this.onDidChangeTreeData = this._onDidChangeTreeData.event;
        console.log(workspaceRoot);
        this.rootPath = workspaceRoot;
    }
    getTreeItem(element) {
        return element;
    }
    getChildren(element) {
        console.log(element);
        return this.getRatings();
    }
    getRatings() {
        return __awaiter(this, void 0, void 0, function* () {
            const userFriends = yield friends_1.default();
            let ratingUrl = "api/user.info?handles=" + data_1.getUserHandle();
            userFriends.forEach((friend) => {
                ratingUrl += ";" + friend;
            });
            return axios_1.default.get(ratingUrl).then((res) => {
                const users = res.data.result;
                users.sort((userA, userB) => {
                    return userB.rating - userA.rating;
                });
                return users.map((user, i) => {
                    let name = user.firstName + " " + user.lastName;
                    if (!user.firstName) {
                        name = "";
                    }
                    const userDetail = {
                        rating: user.rating,
                        handle: user.handle,
                        name: name
                    };
                    return this.getRatingExplorer(userDetail, i + 1);
                });
            });
        });
    }
    getRatingExplorer(userDetail, rank) {
        let label = `${rank}. ${userDetail.rating}: ${userDetail.handle} (${userDetail.name})`;
        if (userDetail.handle === data_1.getUserHandle()) {
            label = `---> ${rank}. ${userDetail.rating}: ${userDetail.handle} (${userDetail.name})`;
        }
        const problemExplorer = new explorer_1.Explorer(label, "Rating", vscode.TreeItemCollapsibleState.None);
        return problemExplorer;
    }
    refresh() {
        console.log("Event");
        console.log(this.onDidChangeTreeData);
        this._onDidChangeTreeData.fire(undefined);
    }
}
exports.RatingsProvider = RatingsProvider;
//# sourceMappingURL=ratings.js.map