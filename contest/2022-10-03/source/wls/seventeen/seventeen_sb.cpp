#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <bits/stdc++.h>
#define println(x) print(x), putchar('\n')
#define printsp(x) print(x), putchar(' ')
#define printpa(x, y) printsp(x), println(y)
using namespace std;
const int N = 2e3 + 10;
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
void print(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
int n;
int x[N], y[N];
map<pair<int, int>, int> dp[2];
int ans = 0x3f3f3f3f;
inline void update(int i, pair<int, int> j, int num) {
    if (dp[i].count(j)) dp[i][j] = min(dp[i][j], num);
    else dp[i][j] = num;
}
signed main() {
    freopen("seventeen.in", "r", stdin);
    freopen("seventeen.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++) x[i] = read(), y[i] = read();
    dp[0][make_pair(0, 0)] = 0;
    for (int i = 1; i <= n; i++) { // i-1 => i
        dp[i & 1].clear();
        for (map<pair<int, int>, int>::iterator it = dp[i & 1 ^ 1].begin(); it != dp[i & 1 ^ 1].end(); it++) {
            int xs = (*it).first.first, ys = (*it).first.second, val = (*it).second;
            update(i & 1, make_pair(xs + x[i], ys + y[i]), val + (xs * x[i]) + (ys * y[i]));
            update(i & 1, make_pair(xs - x[i], ys + y[i]), val - (xs * x[i]) + (ys * y[i]));
            update(i & 1, make_pair(xs + x[i], ys - y[i]), val + (xs * x[i]) - (ys * y[i]));
            update(i & 1, make_pair(xs - x[i], ys - y[i]), val - (xs * x[i]) - (ys * y[i]));
        }
    }
    int minn = 0x3f3f3f3f;
    for (map<pair<int, int>, int>::iterator it = dp[n & 1].begin(); it != dp[n & 1].end(); it++) {
        minn = min(minn, (*it).second);
    }
    printf("%d.00\n", minn);
    cerr << clock() << endl;
    return 0;
}