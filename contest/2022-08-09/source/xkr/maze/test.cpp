#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int maxn = 25;
int n, m, k;
int a[maxn][maxn];
int cnt[maxn][maxn];
bool p[maxn][maxn];
unordered_map<int, int> lza[maxn][maxn];
unordered_map<int, int> yxy[maxn][maxn];
int ans;
int res;
inline void dfs1(int x, int y, int s) {
    if (x < 1 || x > n || y < 1 || y > m) return;
    if (!p[x][y]) return;
    cnt[x][y]++; res++;
    lza[x][y][s]++;
    dfs1(x + 1, y, s ^ a[x + 1][y]);
    dfs1(x, y + 1, s ^ a[x][y + 1]);
}
inline void dfs2(int x, int y, int s) {
    if (x < 1 || x > n || y < 1 || y > m) return;
    if (p[x][y]) return;
    cnt[x][y]++; res++;
    yxy[x][y][s]++;
    dfs2(x - 1, y, s ^ a[x - 1][y]);
    dfs2(x, y - 1, s ^ a[x][y - 1]);
}
void calc(int x, int y, int xx, int yy) {
    if (xx > n || yy > m) return;
    for (unordered_map<int, int> :: iterator it = lza[x][y].begin(); it != lza[x][y].end(); it++)
            ans += yxy[xx][yy][k ^ (it -> first)] * (it -> second);
}
int main() {
    // freopen("maze.in", "r", stdin);
    // freopen("maze.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n / 2; i++)
        for (int j = 1; j <= ceil(m * 2. / 3); j++)
            p[i][j] = 1;
    for (int i = n / 2 + 1; i <= n; i++)
        for (int j = 1; j <= m - ceil(m * 2. / 3); j++)
            p[i][j] = 1;
    dfs1(1, 1, a[1][1]);
    dfs2(n, m, a[n][m]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (p[i][j]) {
                if (!p[i + 1][j]) calc(i, j, i + 1, j);
                if (!p[i][j + 1]) calc(i, j, i, j + 1);
            }
    cout << ans << endl;
    return 0;
}