"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const axios_1 = require("axios");
const login_1 = require("../Login/login");
const instance = axios_1.default.create({ baseURL: "https://codeforces.com" });
instance.interceptors.request.use((config) => {
    // console.log(config);
    return login_1.default()
        .then((cookie) => {
        // console.log(cookie)
        config.headers.Cookie = cookie;
        return config;
    })
        .catch((error) => {
        return Promise.reject(error);
    });
});
exports.default = instance;
//# sourceMappingURL=axios.js.map