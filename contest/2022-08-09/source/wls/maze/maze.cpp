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
using namespace std;
const int N = 50, K = 1e4 + 10;
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int n, m, kx;
int a[N][N];
unordered_map<int, int> dp[N][N], dp2[N][N];
signed main() {
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    n = read(), m = read(), kx = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    
    dp[1][1][a[1][1]] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i + j - 1 <= max(n, m); j++) {
            if (a[i][j] == 0) continue;
            if (j > m) continue;
            for (unordered_map<int, int>::iterator it = dp[i][j].begin(); it != dp[i][j].end(); it++) {
                int k = (*it).first;
                dp[i + 1][j][k ^ a[i + 1][j]] += (*it).second;
                dp[i][j + 1][k ^ a[i][j + 1]] += (*it).second;
            }
        }
    }

    dp2[n][m][a[n][m]] = 1;
    for (int i = n; i > 0; i--) {
        for (int j = m; (n - i + 1) + (m - j + 1) - 1 <= max(n, m); j--) {
            if (a[i][j] == 0) continue;
            if (j <= 0) continue;
            for (unordered_map<int, int>::iterator it = dp2[i][j].begin(); it != dp2[i][j].end(); it++) {
                int k = (*it).first;
                dp2[i - 1][j][k ^ a[i - 1][j]] += (*it).second;
                dp2[i][j - 1][k ^ a[i][j - 1]] += (*it).second;
            }
        }
    }
    int res = 0;
    for (int i = max(1ll, n - m + 1); i <= n; i++) {
        int j = n - i + 1;
        if (a[i][j] == 0) continue;
        // printf("%d %d\n", i, j, res);
        for (unordered_map<int, int>::iterator it = dp[i][j].begin(); it != dp[i][j].end(); it++) {
            int k = (*it).first;
            res += dp[i][j][k] * dp2[i][j][kx ^ a[i][j] ^ k];
        }
    }
    printf("%lld\n", res);
    // cerr << clock() << endl;
    return 0;
}
/*
3 3 1
1 1 1
1 1 1
0 0 1
*/