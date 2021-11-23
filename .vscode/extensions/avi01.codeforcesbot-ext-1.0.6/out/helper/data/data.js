"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.getSubmitCompiler = exports.setTemplateLineNo = exports.getTemplateLineNo = exports.setTemplateFile = exports.getTemplateFile = exports.setCompileCommand = exports.getCompileCommand = exports.setConfiguration = exports.setUser = exports.getCsrfToken = exports.resetCookie = exports.getCookie = exports.getUserPassword = exports.getUserHandle = exports.getData = exports.updateData = void 0;
let data = {
    handleOrEmail: "",
    password: "",
    lastUpdate: 1603880554122,
    cookie: null,
    csrfToken: null,
    compileCommand: "g++-8 --std=c++14",
    templateFile: "",
    templateLineNo: 0,
    submitCompiler: 54
};
function updateData(newData) {
    data = newData;
}
exports.updateData = updateData;
function getData() {
    return data;
}
exports.getData = getData;
function getUserHandle() {
    return data.handleOrEmail;
}
exports.getUserHandle = getUserHandle;
function getUserPassword() {
    return data.password;
}
exports.getUserPassword = getUserPassword;
function getCookie() {
    return data.cookie;
}
exports.getCookie = getCookie;
function resetCookie() {
    data.cookie = null;
}
exports.resetCookie = resetCookie;
function getCsrfToken() {
    return data.csrfToken;
}
exports.getCsrfToken = getCsrfToken;
function setUser(userHandle, userPassword) {
    console.log('------', userHandle, userPassword);
    data.handleOrEmail = userHandle ? userHandle : '';
    data.password = userPassword ? userPassword : '';
}
exports.setUser = setUser;
function setConfiguration(compileCommand, templateFile, templateLineNo) {
    data.compileCommand = compileCommand;
    data.templateFile = templateFile;
    data.templateLineNo = templateLineNo;
    console.log(data);
    return;
}
exports.setConfiguration = setConfiguration;
function getCompileCommand() {
    return data.compileCommand;
}
exports.getCompileCommand = getCompileCommand;
function setCompileCommand(compileCommand) {
    return data.compileCommand = compileCommand;
}
exports.setCompileCommand = setCompileCommand;
function getTemplateFile() {
    return data.templateFile;
}
exports.getTemplateFile = getTemplateFile;
function setTemplateFile(templateFile) {
    return data.templateFile = templateFile;
}
exports.setTemplateFile = setTemplateFile;
function getTemplateLineNo() {
    return data.templateLineNo;
}
exports.getTemplateLineNo = getTemplateLineNo;
function setTemplateLineNo(templateLineNo) {
    return data.templateLineNo = templateLineNo;
}
exports.setTemplateLineNo = setTemplateLineNo;
function getSubmitCompiler() {
    return data.submitCompiler;
}
exports.getSubmitCompiler = getSubmitCompiler;
//# sourceMappingURL=data.js.map