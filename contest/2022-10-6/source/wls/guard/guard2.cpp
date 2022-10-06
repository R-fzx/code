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
double dp[N][N], f[N][N][M];
signed main() {
    // freopen("guard.in", "r", stdin);
    // freopen("guard.out", "w", stdout);
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

    f[0][0][0] = 1;
    for (int i = 1; i <= n2; i++) {
        f[i][0][0] = f[i - 1][0][0] * (1.0 - p2[i]);
        for (int j = 0; j <= i; j++) {
            for (int k = a2[i]; k <= n; k++) {
                f[i][j][k] = f[i - 1][j - 1][k - a2[i]] * p2[i] + f[i - 1][j][k] * (1.0 - p2[i]);
            }
        }
    }
    for (int j = 0; j <= n2; j++) {
        for (int k = m; k >= 0; k--) {
            f[n2][j][k] += f[n2][j][k + 1];
        }
    }
    double ans = 0;
    for (int i = l; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            int j2 = i - j;
            ans += dp[n1][j] * f[n2][j2][max(0, j - K)];
            // printf("%d %d %lf %lf\n", i, j, dp[n1][j], f[n2][j2][j]);
        }
    }
    printf("%lf\n", ans);
    return 0;
}