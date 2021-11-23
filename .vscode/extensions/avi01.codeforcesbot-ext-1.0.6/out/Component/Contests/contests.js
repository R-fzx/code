"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.ContestsProvider = void 0;
const vscode = require("vscode");
const explorer_1 = require("../../Container/explorer");
const problems_1 = require("./Problems/problems");
const data_1 = require("../../helper/data/data");
const allContest_1 = require("./allContest");
const standing_1 = require("./Standings/standing");
const standings_1 = require("./Standings/standings");
class ContestsProvider {
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
        if (!element) {
            return this.getContestTypeExplorer();
        }
        else if (element.label === 'Past') {
            return allContest_1.getContests(element.label, 10, vscode.TreeItemCollapsibleState.Collapsed);
        }
        else if (element.label === 'Running') {
            return allContest_1.getContests(element.label, 20, vscode.TreeItemCollapsibleState.Collapsed);
        }
        else if (element.label === 'Future') {
            return allContest_1.getContests(element.label, 20, vscode.TreeItemCollapsibleState.None);
        }
        else if (element.type === 'Past' || element.type === 'Running') {
            return this.getContestExplorer(element.explorerId);
        }
        else if (element.label === 'Problems') {
            const contestId = element.explorerId ? element.explorerId : 0;
            const problems = new problems_1.default(data_1.getUserHandle(), contestId);
            return problems.fetchProblems().then(() => {
                return problems.toExplorer();
            });
        }
        else if (element.label === 'Standings') {
            const contestId = element.explorerId ? element.explorerId : 0;
            let standingsExplorer = [];
            const userStanding = new standing_1.default(data_1.getUserHandle(), contestId);
            return userStanding.getStanding().then(() => {
                standingsExplorer.push(userStanding.toExplorer());
                standingsExplorer.push(new explorer_1.Explorer("Friends", "FriendsStanding", vscode.TreeItemCollapsibleState.Collapsed, contestId));
                return Promise.resolve(standingsExplorer);
            });
        }
        else if (element.label === 'Friends') {
            const contestId = element.explorerId ? element.explorerId : 0;
            const standings = new standings_1.default(data_1.getUserHandle(), contestId);
            return standings.getStandings().then(() => {
                return standings.toExplorer();
            });
        }
        else {
            return Promise.resolve([]);
        }
    }
    getContestTypeExplorer() {
        let contestExplorers = [];
        contestExplorers.push(new explorer_1.Explorer("Running", "ContestType", vscode.TreeItemCollapsibleState.Expanded));
        contestExplorers.push(new explorer_1.Explorer("Future", "ContestType", vscode.TreeItemCollapsibleState.Collapsed));
        contestExplorers.push(new explorer_1.Explorer("Past", "ContestType", vscode.TreeItemCollapsibleState.Collapsed));
        return Promise.resolve(contestExplorers);
    }
    getContestExplorer(contestId) {
        let contestExplorers = [];
        contestExplorers.push(new explorer_1.Explorer("Standings", "Standings", vscode.TreeItemCollapsibleState.Collapsed, contestId));
        contestExplorers.push(new explorer_1.Explorer("Problems", "Problems", vscode.TreeItemCollapsibleState.Expanded, contestId));
        return Promise.resolve(contestExplorers);
    }
    refresh() {
        console.log("Event");
        console.log(this.onDidChangeTreeData);
        this._onDidChangeTreeData.fire(undefined);
    }
}
exports.ContestsProvider = ContestsProvider;
//# sourceMappingURL=contests.js.map