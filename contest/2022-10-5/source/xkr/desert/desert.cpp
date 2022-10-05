#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;
int n, m;
char c[maxn][maxn];
struct node {
    int x, y, s;
    bool operator < (const node &a) const {return s > a.s;}
};
int sx, sy;
int dis[maxn][maxn];
bool p[maxn][maxn];
priority_queue<node> q;
int ans;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
bool valid(int x, int y) {return x >= 1 && x <= n && y >= 1 && y <= m && c[x][y] != 'X';}
void dijkstra(int d) {
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dis[i][j] = 1e9;
    dis[sx][sy] = 0;
    while (!q.empty()) q.pop();
    q.push((node){sx, sy, 0});
    while (!q.empty()) {
        int x = q.top().x, y = q.top().y; q.pop();
        if (p[x][y]) continue; p[x][y] = 1;
        for (int i = 0; i < 8; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (!valid(xx, yy)) continue;
            int s = (i == d ? 3 : 1);
            if (dis[xx][yy] > dis[x][y] + s) {
                dis[xx][yy] = dis[x][y] + s;
                q.push((node){xx, yy, dis[xx][yy]});
            }
        }
    }
    int res = 1e9;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (c[i][j] == '*') res = min(res, dis[i][j]);
    ans = max(ans, res);
}
int main() {
    freopen("desert.in", "r", stdin);
    freopen("desert.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s; m = s.size();
        for (int j = 1; j <= m; j++) {
            c[i][j] = s[j - 1];
            if (c[i][j] == '@') sx = i, sy = j;
        }
    }
    for (int i = 0; i <= 7; i++) dijkstra(i);
    cout << ans << endl;
    return 0;
}