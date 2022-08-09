#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int maxn = 25;
int n, m, x;
int a[maxn][maxn];
int cnt[maxn][maxn];
unordered_map<int, int> lza[maxn];
unordered_map<int, int> yxy[maxn];
int ans;
int res;
inline void dfs1(int x, int y, int s) {
    cnt[x][y]++; res++;
    if (x == n / 2) lza[y][s]++;
    if (x < n / 2) dfs1(x + 1, y, s ^ a[x + 1][y]);
    if (y < m) dfs1(x, y + 1, s ^ a[x][y + 1]);
}
inline void dfs2(int x, int y, int s) {
    cnt[x][y]++; res++;
    if (x == n / 2 + 1) yxy[y][s]++;
    if (x > n / 2 + 1) dfs2(x - 1, y, s ^ a[x - 1][y]);
    if (y > 1) dfs2(x, y - 1, s ^ a[x][y - 1]);
}
int main() {
    freopen("maze.in", "r", stdin);
    freopen("bf.out", "w", stdout);
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    dfs1(1, 1, a[1][1]);
    dfs2(n, m, a[n][m]);
    for (int i = 1; i <= m; i++)
        for (unordered_map<int, int> :: iterator it = lza[i].begin(); it != lza[i].end(); it++)
            ans += yxy[i][x ^ (it -> first)] * (it -> second);
    cout << ans << endl;
    cerr << clock() * 1. / 1000 << endl;
    cerr << res << endl;
    for (int i = 1; i <= 20; i++, cerr << endl)
        for (int j = 1; j <= 20; j++)
            cerr << cnt[i][j] << ' ';
    return 0;
}