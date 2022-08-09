#include <bits/stdc++.h>
using namespace std;
const int N = 50, K = 2e4 + 10;
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int n, m, kx;
int a[N][N];
int dp[N][N][K];
signed main() {
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    n = read(), m = read(), kx = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    
    dp[1][1][a[1][1]] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= 16384; k++) {
                if (a[i][j] == 0) continue;
                dp[i][j][k] += dp[i - 1][j][k ^ a[i][j]] + dp[i][j - 1][k ^ a[i][j]];
            }
        }
    }
    printf("%d\n", dp[n][m][kx]);
    return 0;
}