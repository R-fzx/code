"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Explorer = void 0;
const vscode = require("vscode");
class Explorer extends vscode.TreeItem {
    constructor(label, contextValue, collapsibleState, explorerId, type = "", tooltip, data, lightIconPath, darkIconPath, command) {
        super(label, collapsibleState);
        this.label = label;
        this.contextValue = contextValue;
        this.collapsibleState = collapsibleState;
        this.explorerId = explorerId;
        this.type = type;
        this.tooltip = tooltip;
        this.data = data;
        this.lightIconPath = lightIconPath;
        this.darkIconPath = darkIconPath;
        this.command = command;
        this.contextValue = contextValue;
        // console.log(tooltip)
        this.tooltip = tooltip ? tooltip : `${this.label}`;
        this.explorerId = explorerId;
        this.type = type;
        this.data = data;
        if (lightIconPath) {
            this.iconPath = {
                light: lightIconPath,
                dark: darkIconPath,
            };
        }
        this.command = command;
    }
}
exports.Explorer = Explorer;
//# sourceMappingURL=explorer.js.map