"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.updateLoginStatus = exports.setStatusBarItem = void 0;
let loginStatusBarItem;
function setStatusBarItem(statusBarItem) {
    loginStatusBarItem = statusBarItem;
}
exports.setStatusBarItem = setStatusBarItem;
function updateLoginStatus(login, userHandle) {
    if (!login) {
        loginStatusBarItem.text = `${userHandle}: $(error) Login Failed`;
        loginStatusBarItem.show();
    }
    else {
        loginStatusBarItem.text = `${userHandle}: $(check) Logged in`;
        loginStatusBarItem.show();
    }
}
exports.updateLoginStatus = updateLoginStatus;
//# sourceMappingURL=loginStatus.js.map