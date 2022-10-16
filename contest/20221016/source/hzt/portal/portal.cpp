#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int N = 505;

int n, m, qx, qy, fx, fy;
char c[N][N];
int u[N][N], d[N][N], l[N][N], r[N][N];

void U (int &x, int y) {
    if (x == 0) {
        x = y;
    }
}

struct D {
    int x, y, val;
};

queue<D> q;
bool f[N][N];

bool inMap (int x, int y) {
    return (x > 0 && x <= n && y > 0 && y <= m);
}

void R (D a) {
    if (inMap(a.x, a.y) && c[a.x][a.y] != '#' && f[a.x][a.y] == 0) {
        f[a.x][a.y] = 1;
        q.push(a);
    } 
}

int Bfs () {
    q.push({qx, qy, 0});
    f[qx][qy] = 1;
    while (!q.empty()) {
        D t = q.front();
        q.pop();
        if (t.x == fx && t.y == fy) {
            return t.val;
        }
        bool fl = 0;
        for (int i = 0; i < 4; i++) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            fl |= (inMap(nx, ny) && c[nx][ny] == '#');
            R((D){nx, ny, t.val + 1});
        }
        if (fl) {
            int px[4] = {t.x, t.x, u[t.x][t.y], d[t.x][t.y]};
            int py[4] = {l[t.x][t.y], r[t.x][t.y], t.y, t.y};
            for (int i = 0; i < 4; i++) {
                R((D){px[i], py[i], t.val + 1});
            }
        }
    }
    return -1;
}

int main () {
    freopen("portal.in", "r", stdin);
    freopen("portal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if (c[i][j] == 'C') {
                qx = i, qy = j;
            }
            if (c[i][j] == 'F') {
                fx = i, fy = j;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        r[i][1] = 1, l[i][m] = m;
    }
    for (int i = 1; i <= m; i++) {
        d[1][i] = 1, u[n][i] = n;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == '#') {
                U(l[i][j], j + 1);
                U(u[i][j], i + 1);
            }
            else {
                U(l[i][j], l[i][j - 1]);
                U(u[i][j], u[i - 1][j]);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (c[i][j] == '#') {
                U(r[i][j], j - 1);
                U(d[i][j], i - 1);
            }
            else {
                U(r[i][j], r[i][j + 1]);
                U(d[i][j], d[i + 1][j]);
            }
        }
    }
    int ans = Bfs();
    if (ans == -1) {
        cout << "nemoguce";
    }
    else {
        cout << ans;
    }
    return 0;
}