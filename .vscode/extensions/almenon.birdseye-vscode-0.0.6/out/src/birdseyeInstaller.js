"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.upgradeBirdseye = exports.installBirdseye = void 0;
const vscode = require("vscode");
const child_process_1 = require("child_process");
/**
 * Gives user installation prompt
 * Calls postinstallhook if user accepts prompt and installation is successful
 * Or if user says they have installed birdseye manually
 * @param postInstallHook
 */
function installBirdseye(postInstallHook) {
    // function thanks to duroktar - see https://github.com/Duroktar/Wolf/blob/master/src/hunterInstaller.ts
    const settings = vscode.workspace.getConfiguration('birdseye');
    let pythonPath = settings.get('pythonPath');
    const installbirdseye = { title: "Install Package" };
    const installedManually = { title: "I installed manually" };
    vscode.window
        .showInformationMessage("Birdseye requires the birdseye package. Install now or run 'pip install birdseye --user' manually.", installbirdseye, installedManually)
        .then(result => {
        if (result === installbirdseye) {
            install(pythonPath, postInstallHook);
        }
        else {
            postInstallHook();
        }
    });
}
exports.installBirdseye = installBirdseye;
/**
 * Gives user upgrade prompt
 * Calls postinstallhook if user clicks on upgrade and installation is successful
 * @param updateMsg
 * @param postInstallHook
 */
function upgradeBirdseye(updateMsg, postUpgradeHook) {
    const settings = vscode.workspace.getConfiguration('birdseye');
    let pythonPath = settings.get('pythonPath');
    if (settings.get('warnIfOutdated')) {
        vscode.window.showInformationMessage(updateMsg, 'upgrade').then(() => {
            install(pythonPath, postUpgradeHook, true);
        });
    }
}
exports.upgradeBirdseye = upgradeBirdseye;
/**
 * installs birdseye, using pythonPath to decide whether to use pip or pip3
 */
function install(pythonPath = "python", postInstallHook, upgrade = false) {
    const child = child_process_1.spawn(pythonPath, ["-m", "pip", "install", "birdseye", "--user", upgrade ? "--upgrade" : ""]);
    child.stderr.on("data", data => {
        console.error("INSTALL_ERROR:", data + "");
    });
    child.on('error', err => {
        vscode.window.showErrorMessage("pip is not installed! error: " + err.message);
    });
    child.on("close", code => {
        if (code !== 0) {
            vscode.window.showWarningMessage(`There was an error attempting to install birdseye. Please try running 'pip install birdseye --user ${upgrade ? '--upgrade' : ''}' manually.`);
        }
        else {
            vscode.window.showInformationMessage("birdseye installed successfully. Please close and re-open birdseye");
            postInstallHook();
        }
    });
}
//# sourceMappingURL=birdseyeInstaller.js.map