"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.killAll = void 0;
const child_process_1 = require("child_process");
/**
 * kills the process and all its children
 * If you are on linux process needs to be launched in detached state
 * @param pid process identifier
 * @param signal kill signal
 */
function killAll(pid, signal = 'SIGTERM') {
    if (process.platform == "win32") {
        child_process_1.exec(`taskkill /PID ${pid} /T /F`, (error, stdout, stderr) => {
            console.log("taskkill stdout: " + stdout);
            console.log("taskkill stderr: " + stderr);
            if (error) {
                console.log("error: " + error.message);
            }
        });
    }
    else {
        // see https://nodejs.org/api/child_process.html#child_process_options_detached
        // If pid is less than -1, then sig is sent to every process in the process group whose ID is -pid.
        process.kill(-pid, signal);
    }
}
exports.killAll = killAll;
//# sourceMappingURL=utilities.js.map