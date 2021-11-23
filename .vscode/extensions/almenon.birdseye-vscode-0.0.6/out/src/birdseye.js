"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.birdseye = void 0;
const child_process_1 = require("child_process");
const utilities_1 = require("./utilities");
/**
 * function taken from Duroktar's Wolf Ext
 * Calls postinstallhook if user accepts prompt and installation is successful
 * @param postInstallHook
 */
class birdseye {
    constructor() {
        this.running = false;
        this.exitRequested = false;
    }
    start(port = "7777", pythonPath = 'python') {
        let isWin = process.platform == "win32";
        this.exitRequested = false;
        // if non-windows spawn in detached state so we can easily kill children
        this.child = child_process_1.spawn(pythonPath, ["-m", "birdseye", port], { 'detached': !isWin });
        this.running = true;
        this.child.stderr.on("data", data => {
            data = data.toString();
            console.log(data);
            if (this.hasError(data)) {
                // save exception for later to show user when birdseye exits
                this.exception = data;
            }
        });
        this.child.on('error', err => {
            this.running = false;
            console.error(err.message);
        });
        this.child.on("exit", code => {
            if (!this.exitRequested) {
                this.running = false;
            }
        });
    }
    stop() {
        if (this.running) {
            this.exitRequested = true;
            utilities_1.killAll(this.child.pid);
            this.running = false;
        }
    }
    hasError(data) {
        data = data.toLowerCase();
        return !data.startsWith("127.0.0.1") && // anything starting with 127.0.0.1 will just be normal web requests
            (data.includes("Traceback (most recent call last)") || data.includes("Error") || data.includes("Exception"));
    }
}
exports.birdseye = birdseye;
//# sourceMappingURL=birdseye.js.map