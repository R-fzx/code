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
const fs = require("fs");
const problem_1 = require("./Component/Contests/Problems/problem");
const problems_1 = require("./Component/Contests/Problems/problems");
// testProblem();
testProblems();
function testProblem() {
    return __awaiter(this, void 0, void 0, function* () {
        const problem = new problem_1.default("avi-01", 1437, "E");
        yield problem.fetchProblemData();
        console.log(problem);
        const problem1 = new problem_1.default("whitewalker7", 1436, "D");
        yield problem1.fetchProblemData();
        console.log(problem1);
    });
}
function testProblems() {
    return __awaiter(this, void 0, void 0, function* () {
        const problems = new problems_1.default("avi-01", 1437);
        yield problems.fetchProblems();
        console.log(problems);
        const problems1 = new problems_1.default("whitewalker7", 1436);
        yield problems1.fetchProblems();
        console.log(problems1);
    });
}
//# sourceMappingURL=testing.js.map