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
const int N = 2e2 + 10, M = 2e3 + 10;
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
int n, l, K;
int m;
int a[N], a2[N];
double p[N], p1[N], p2[N]; int n1, n2;
double dp[N][N], f[2][N][M];
signed main() {
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    n = read(), l = read(), K = read();
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &p[i]);
        p[i] /= 100.0;
    }
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) p1[++n1] = p[i];
        else p2[++n2] = p[i], a2[n2] = a[i];
    }
    for (int i = 1; i <= n; i++) if (a[i] != -1) m += a[i];

    dp[0][0] = 1;
    for (int i = 1; i <= n1; i++) {
        dp[i][0] = dp[i - 1][0] * (1.0 - p1[i]);
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] * p1[i] + dp[i - 1][j] * (1.0 - p1[i]);
        }
    }

    f[0 & 1][0][0] = 1;
    for (int i = 1; i <= n2; i++) {
        f[i & 1][0][0] = f[i & 1 ^ 1][0][0] * (1.0 - p2[i]);
        for (int j = i; j >= 0; j--) {
            for (int k = n; k >= a2[i]; k--) {
                if (j) f[i & 1][j][k] = f[i & 1 ^ 1][j - 1][k - a2[i]] * p2[i] + f[i & 1 ^ 1][j][k] * (1.0 - p2[i]);
                else f[i & 1][j][k] = f[i & 1 ^ 1][j][k] * (1.0 - p2[i]);
            }
        }
    }
    for (int j = 0; j <= n2; j++) {
        for (int k = m; k >= 0; k--) {
            f[n2 & 1][j][k] += f[n2 & 1][j][k + 1];
        }
    }
    double ans = 0;
    for (int i = l; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            int j2 = i - j;
            ans += dp[n1][j] * f[n2 & 1][j2][max(0, j - K)];
        }
    }
    printf("%.6lf\n", ans);
    return 0;
}