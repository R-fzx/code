'use strict';
Object.defineProperty(exports, "__esModule", { value: true });
exports.deactivate = exports.activate = void 0;
const vscode = require("vscode");
const BirdseyeContentProvider_1 = require("./BirdseyeContentProvider");
const birdseye_1 = require("./birdseye");
const birdseyeInstaller = require("./birdseyeInstaller");
const telemetry_1 = require("./telemetry");
const os_1 = require("os");
const needToUpdateMsg = "The package birdseye is out of date";
let eye = new birdseye_1.birdseye();
let myContext;
let settings;
let eyeContent;
let reporter;
let timeStarted;
// your extension is activated the very first time the command is executed
function activate(context) {
    myContext = context;
    let disposablePreview = vscode.commands.registerCommand('extension.birdseye.open', Birdseye);
    context.subscriptions.push(disposablePreview);
}
exports.activate = activate;
function Birdseye() {
    timeStarted = Date.now();
    settings = vscode.workspace.getConfiguration('birdseye');
    reporter = new telemetry_1.default(settings.get('telemetry'));
    eyeContent = new BirdseyeContentProvider_1.default();
    setupEye(onEyeRunning.bind(this));
    eyeContent.start();
    function onEyeRunning() {
        eyeContent.onBirdseyeRunning();
        eyeContent.panel.onDidDispose(dispose);
    }
}
function setupEye(onEyeRunning = () => { }) {
    eye.start(settings.get('port'), settings.get("pythonPath"));
    let birdseyeInstalled = true;
    eye.child.stderr.on("data", data => {
        // we also recieve logs on stderr
        // birdseye will log the following upon start:
        /*
            * Restarting with stat
            * Debugger is active!
            * Debugger PIN: XXX-XXX-XXX
            * Running on http://127.0.0.1:XXXX/ (Press CTRL+C to quit)
            *
        */
        data = data.toString();
        console.log(data);
        if (data.includes("No module named birdseye")) {
            birdseyeInstalled = false;
            birdseyeInstaller.installBirdseye(() => {
                birdseyeInstalled = true;
            });
        }
        else if (data.includes("Running") || data.includes("Debugger is active")) {
            onEyeRunning();
        }
        if (data.includes(needToUpdateMsg)) {
            const lines = data.split(os_1.EOL);
            // find line with update message and show it to user
            for (const line of lines) {
                if (line.includes(needToUpdateMsg)) {
                    // get rid of ugly path before needToUpdateMsg
                    let niceLine = line.slice(line.indexOf(needToUpdateMsg));
                    birdseyeInstaller.upgradeBirdseye(niceLine, () => { });
                }
            }
        }
    });
    eye.child.on('error', err => {
        // technically this could also happen if birdseye could not be killed
        // or if sending a message to it failed
        vscode.window.showErrorMessage("could not start birdseye! error: " + err.message);
        reporter.sendError(err.message);
    });
    eye.child.on("exit", code => {
        if (!eye.exitRequested && birdseyeInstalled) {
            vscode.window.showErrorMessage(`birdseye exited due to an error :( error code: ${code} Exception: ${eye.exception}
                Please raise an issue: https://github.com/Almenon/birdseye-vscode/issues`);
        }
        reporter.sendError(eye.exception, code);
    });
}
function dispose() {
    let timeSpentSeconds = (Date.now() - timeStarted) / 1000;
    reporter.sendFinishedEvent(settings.get("pythonPath"), timeSpentSeconds);
    reporter.dispose();
    eye.stop();
}
function deactivate() {
    reporter.sendDeactivatedEvent();
    dispose();
}
exports.deactivate = deactivate;
//# sourceMappingURL=extension.js.map