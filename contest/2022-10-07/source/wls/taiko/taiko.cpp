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
#define int long long
#define println(x) print(x), putchar('\n')
#define printsp(x) print(x), putchar(' ')
#define printpa(x, y) printsp(x), println(y)
using namespace std;
const int N = 1e5 + 10;
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
bool b[N];
bool vis[N];
int tonum(int l, int r, int m) {
    if (l <= r) {
        int x = 0;
        for (int i = l; i <= r; i++) x = x << 1 | b[i];
        return x;
    } else {
        int x = 0;                                                                         
        for (int i = l; i <= m; i++) x = x << 1 | b[i];
        for (int i = 1; i <= r; i++) x = x << 1 | b[i];
        return x;
    }
}
bool ok = 0;
void dfs(int now, int m) {
    if (ok) return;
    if (now > m) {
        for (int i = m - n + 2; i <= m; i++) {
            if (vis[tonum(i, n - m + i - 1, m)]) return;
        }
        printsp(m);
        for (int i = 1; i <= m; i++) print(b[i]);
        puts("");
        ok = 1;
        return;
    }
    for (int k = 0; k < 2; k++) {
        b[now] = k;
        int f = tonum(now - n + 1, now, m);
        if (vis[f]) continue;
        vis[f] = 1;
        dfs(now + 1, m);
        vis[f] = 0;
    }
}
signed main() {
    freopen("taiko.in", "r", stdin);
    freopen("taiko.out", "w", stdout);
    n = read();
    vis[0] = 1;
    dfs(n + 1, (1 << n));
    return 0;
}
/*
2 00 11
3 000 10 111
4 0000 10011010 1111
*/