'use strict';
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");
class BirdseyeContentProvider {
    constructor() {
        this._onDidChange = new vscode.EventEmitter();
        this._settings = vscode.workspace.getConfiguration('birdseye');
    }
    start() {
        this.panel = vscode.window.createWebviewPanel("birdseye", "birdseye", vscode.ViewColumn.Two, {
            enableScripts: true,
        });
        this.panel.webview.html = "Starting birdseye...";
        return this.panel;
    }
    /**
     * loads birdseye website
     */
    onBirdseyeRunning() {
        const port = this._settings.get('port');
        this.panel.webview.html = `
        <html> <!-- iframe html thanks to https://github.com/negokaz/vscode-live-server-preview -->
                <header>
                <style>
                        body, html, div {
                            margin: 0;
                            padding: 0;
                            width: 100%;
                            height: 100%;
                            overflow: hidden;
                            background-color: #fff;
                        }
                    </style>
                    </header>
                <body>
                <div>
                    <iframe src="http://127.0.0.1:${port}" width="100%" height="100%" seamless frameborder=0>
                    </iframe>
                </div>
            </body>
        </html>
        `;
    }
}
exports.default = BirdseyeContentProvider;
//# sourceMappingURL=BirdseyeContentProvider.js.map