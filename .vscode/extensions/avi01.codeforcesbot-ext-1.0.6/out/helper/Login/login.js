"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");
const loginStatus_1 = require("../../Component/LoginStatus/loginStatus");
const data_1 = require("../data/data");
const axios = require("axios");
const cheerio = require("cheerio");
const qs = require("querystring");
const baseUrl = "https://codeforces.com";
let session = {
    csrfToken: "",
    cookie: "",
};
function login() {
    return __awaiter(this, void 0, void 0, function* () {
        let data = data_1.getData();
        const userHandle = data_1.getUserHandle();
        if (userHandle === null || userHandle === undefined || userHandle === '') {
            handleError("Failed to login user: " + userHandle);
            return '';
        }
        if (!data || !data.cookie || data.cookie === '' || !data.lastUpdate || Date.now() - data.lastUpdate > 3600000) {
            return getCsrfAndJid()
                .then(() => {
                return requestLogin();
            })
                .then(() => {
                data.cookie = session.cookie;
                data.csrfToken = session.csrfToken;
                data.lastUpdate = Date.now();
                console.log("Time: " + data.lastUpdate);
                data_1.updateData(data);
                return data.cookie;
            });
        }
        else {
            return data.cookie;
        }
    });
}
function getCsrfAndJid() {
    return axios
        .get(baseUrl + "/enter")
        .then((res) => {
        session.cookie = res["headers"]["set-cookie"][0].split(";")[0];
        const $ = cheerio.load(res.data);
        session.csrfToken = $("meta[name='X-Csrf-Token']")[0].attribs["content"];
        console.log(session);
    })
        .catch((err) => {
        handleError(err);
    });
}
function requestLogin() {
    console.log("Logging...");
    const url = baseUrl + "/enter";
    const user = {
        handleOrEmail: data_1.getUserHandle(),
        password: data_1.getUserPassword(),
    };
    const options = {
        headers: {
            "content-type": "application/x-www-form-urlencoded",
            Cookie: session.cookie,
        },
    };
    const data = Object.assign(Object.assign({}, user), { csrf_token: session.csrfToken, action: "enter" });
    return axios
        .post(url, qs.stringify(data), options)
        .then((res) => {
        const $ = cheerio.load(res.data);
        const userId = $($(".lang-chooser a")[2]).html();
        session.csrfToken = $("meta[name='X-Csrf-Token']")[0].attribs["content"];
        if (userId === 'Enter') {
            session.cookie = '';
            handleError("Failed to login user: " + user.handleOrEmail);
            return;
        }
        loginStatus_1.updateLoginStatus(true, user.handleOrEmail);
        vscode.window.showInformationMessage(`Login Successful. Welcome ${userId}!!!`);
    })
        .catch((err) => {
        handleError(err);
    });
}
function handleError(error) {
    console.error(error);
    const userHandle = data_1.getUserHandle();
    loginStatus_1.updateLoginStatus(false, userHandle);
}
exports.default = login;
//# sourceMappingURL=login.js.map