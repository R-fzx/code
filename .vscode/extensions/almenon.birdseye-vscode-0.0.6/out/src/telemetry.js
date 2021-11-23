"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const vscode_1 = require("vscode");
const vscode_extension_telemetry_1 = require("vscode-extension-telemetry");
const buffer_1 = require("buffer");
class Reporter {
    constructor(enabled) {
        this.enabled = enabled;
        const extensionId = 'almenon.birdseye-vscode';
        const extension = vscode_1.extensions.getExtension(extensionId);
        const extensionVersion = extension.packageJSON.version;
        // following key just allows you to send events to azure insights API
        // so it does not need to be protected
        // but obfuscating anyways - bots scan github for keys, but if you want my key you better work for it, damnit!
        const innocentKitten = buffer_1.Buffer.from('NWYzMWNjNDgtNTA2OC00OGY4LWFjMWMtZDRkY2Y3ZWFhMTM1', 'base64').toString();
        this.reporter = new vscode_extension_telemetry_1.default(extensionId, extensionVersion, innocentKitten);
    }
    sendError(exception, code = 0) {
        if (this.enabled) {
            this.reporter.sendTelemetryEvent('error', {
                'code': code.toString(),
                'exception': exception
            });
        }
    }
    /**
     * we want to collect data on how long the user uses the extension
     * also pythonPath to see if they are using python2 / 3 / virtual env python
     */
    sendFinishedEvent(pythonPath, timeSpentSeconds) {
        if (this.enabled) {
            this.reporter.sendTelemetryEvent('closed', {
                'pythonPath': pythonPath,
                'timeSpent': timeSpentSeconds.toString()
            });
        }
    }
    sendDeactivatedEvent() {
        this.reporter.sendTelemetryEvent('deactivated');
    }
    dispose() { this.reporter.dispose(); }
}
exports.default = Reporter;
//# sourceMappingURL=telemetry.js.map