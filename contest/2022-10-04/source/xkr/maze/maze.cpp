#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
const double eps = 1e-6;
int T;
int n, m;
double k;
char c[maxn][maxn];
struct node {
    int x, y; double s;
    bool operator < (const node &a) const {return s > a.s;}
};
int dx[2] = {-1, 1};
int dy[2] = {-1, 1};
int sx, sy, ex, ey;
double dis[maxn][maxn];
bool p[maxn][maxn];
priority_queue<node> q;
bool valid(int x, int y) {return x >= 1 && x <= n && y >= 1 && y <= m && c[x][y] != '#';}
bool check(double v) {
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = 1e9;
    dis[sx][sy] = 0;
    while (!q.empty()) q.pop();
    q.push((node){sx, sy, 0});
    while (!q.empty()) {
        int x = q.top().x, y = q.top().y; q.pop();
        if (p[x][y]) continue; p[x][y] = 1;
        for (int i = 0; i < 2; i++) {
            int xx = x, yy = y + dy[i];
            if (!valid(xx, yy)) continue;
            if (dis[xx][yy] > dis[x][y] + 1) {
                dis[xx][yy] = dis[x][y] + 1;
                q.push((node){xx, yy, dis[xx][yy]});
            }
        }
        for (int i = 0; i < 2; i++) {
            int xx = x + dx[i], yy = y;
            if (!valid(xx, yy)) continue;
            if (dis[xx][yy] > dis[x][y] + v) {
                dis[xx][yy] = dis[x][y] + v;
                q.push((node){xx, yy, dis[xx][yy]});
            }
        }
    }
    return dis[ex][ey] <= k;
}
void work() {
    // getchar();
    cin >> k >> n >> m;
    // cout << k << ' ' << n << ' ' << m << endl;
    // getchar();
    char x = getchar();
    while (x != '\n') x = getchar();
    for (int i = 1; i <= n; i++) {
        string s; getline(cin, s);
        // cout << s << endl;
        for (int j = 1; j <= m; j++) {
            c[i][j] = s[j - 1];
            if (c[i][j] == 'S') sx = i, sy = j;
            if (c[i][j] == 'E') ex = i, ey = j;
        }
    }
    double l = -eps, r = 10 + eps;
    while (l + eps < r) {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    printf("%.5lf\n", l);
}
int main() {
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    cin >> T; getchar();
    while (T--) work();
    return 0;
}