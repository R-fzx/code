#include <bits/stdc++.h>
#define side(x) (((x) & 1) + 1)
using namespace std;
const int N = 1e3 + 10;
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int n, k;
int mp[N][N];
int win = 0; // 1: Kitty; 2: ITer; 3: inl;
map<pair<int, int>, bool> vis;
int dx[4] = {1, -1, 0, 0},
    dy[4] = {0, 0, 1, -1};
bool in(int x, int y) {
    return 1 <= x && x <= 1000 && 1 <= y && y <= 1000;
}
int cntqi(int x, int y) {
    int qi = 4;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        qi -= (bool)(mp[nx][ny]);
    }
    return qi;
}
bool checkdie(int x, int y) {
    vis.clear();
    int ch = mp[x][y];
    if (ch == 0) return 0;
    queue<pair<int, int> > q;
    vis[make_pair(x, y)] = 1;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        pair<int, int> now = q.front(); q.pop();
        if (cntqi(now.first, now.second)) return 0;
        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i], ny = now.second + dy[i];
            if (!in(nx, ny) || mp[nx][ny] != ch || vis[make_pair(nx, ny)]) continue;
            vis[make_pair(nx, ny)] = 1;
            q.push(make_pair(nx, ny));
        }
    }
    return 1;
}
void cleardie(int x, int y) {
    vis.clear();
    int ch = mp[x][y];
    if (ch == 0) return;
    queue<pair<int, int> > q;
    vis[make_pair(x, y)] = 1;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        pair<int, int> now = q.front(); q.pop();
        mp[now.first][now.second] = 0;
        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i], ny = now.second + dy[i];
            if (!in(nx, ny) || mp[nx][ny] != ch || vis[make_pair(nx, ny)]) continue;
            vis[make_pair(nx, ny)] = 1;
            q.push(make_pair(nx, ny));
        }
    }
}
bool checkwin(int x, int y) {
    int ch = mp[x][y];
    int l, r;
    int nx, ny;

    nx = x, ny = y;
    while (in(nx, ny) && mp[nx][ny] == ch) nx--;
    l = nx + 1;
    nx = x, ny = y;
    while (in(nx, ny) && mp[nx][ny] == ch) nx++;
    r = nx - 1;
    if (r - l + 1 >= k) return 1;

    nx = x, ny = y;
    while (in(nx, ny) && mp[nx][ny] == ch) ny--;
    l = ny + 1;
    nx = x, ny = y;
    while (in(nx, ny) && mp[nx][ny] == ch) ny++;
    r = ny - 1;
    if (r - l + 1 >= k) return 1;

    nx = x, ny = y;
    while (in(nx, ny) && mp[nx][ny] == ch) nx--, ny--;
    l = nx + 1;
    nx = x, ny = y;
    while (in(nx, ny) && mp[nx][ny] == ch) nx++, ny++;
    r = nx - 1;
    if (r - l + 1 >= k) return 1;

    nx = x, ny = y;
    while (in(nx, ny) && mp[nx][ny] == ch) nx--, ny++;
    l = nx + 1;
    nx = x, ny = y;
    while (in(nx, ny) && mp[nx][ny] == ch) nx++, ny--;
    r = nx - 1;
    if (r - l + 1 >= k) return 1;

    return 0;
}
void print() {
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            printf("%d ", mp[i][j]);
        }
        puts("");
    }
}
signed main() {
    freopen("FIR.in", "r", stdin);
    freopen("FIR.out", "w", stdout);
    int st = -1;
    n = read(), k = read();
    for (int i = 1; i <= n; i++) {
        int x = read(), y = read();
        if (win) continue;
        if (mp[x][y]) {
            win = 3;
            continue;
        }
        mp[x][y] = side(i);
        bool eaten = false;
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j], ny = y + dy[j];
            if (mp[nx][ny] != mp[x][y] && checkdie(nx, ny)) {
                eaten = true;
                cleardie(nx, ny);
            }
        }
        if (!eaten) {
            if (checkdie(x, y)) {
                win = 3;
                continue;
            }
        }
        if (checkwin(x, y)) {
            win = side(i);
            st = i;
            continue;
        }
        // printf("win = %d\n", win);
        // print();
    }
    if (win == 1) printf("Kitty %d\n", st);
    else if (win == 2) printf("ITer %d\n", st);
    else if (win == 3) puts("illegal");
    else puts("draw");
    return 0;
}
/*
20 5
2 3
3 3
3 2
2 2
4 3
2 4
5 3
1 3
3 4
5 5
2 3
3 3
2 3
2 5
6 3
1 5
3 3
1 5
1 5
1 5
*/