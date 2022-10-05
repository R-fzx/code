#include <bits/stdc++.h>
#define println(x) print(x), putchar('\n')
#define printsp(x) print(x), putchar(' ')
#define printpa(x, y) printsp(x), println(y)
#define xy2i(x, y) (((x) - 1) * (n) + (y))
#define in(x, y) ((1 <= (x)) && ((x) <= (n)) && (1 <= (y)) && ((y) <= (n)))
using namespace std;
const int N = 5e2 + 10;
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
int n;
char s[N];
char mp[N][N];
int sx, sy;
int ed[N]; int edcnt;
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
struct node {
    int v, type;
};
vector<node> G[N * N];
void make_map() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mp[i][j] == 'X') continue;
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!in(x, y) || mp[x][y] == 'X') continue;
                G[xy2i(i, j)].push_back((node){xy2i(x, y), k});
            }
        }
    }
}
bool vis[N * N];
int d[N * N];
void dij(int kk) {
    memset(vis, 0, sizeof(vis));
    memset(d, 0x3f, sizeof(d));
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > q;
    int s = xy2i(sx, sy);
    d[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int now = q.top().second; q.pop();
        if (vis[now]) continue;
        vis[now] = 1;
        for (int i = 0; i < G[now].size(); i++) {
            int v = G[now][i].v, tp = G[now][i].type;
            double dis;
            if (tp == kk) dis = 3;
            else dis = 1;
            if (d[v] > d[now] + dis) {
                d[v] = d[now] + dis;
                q.push(make_pair(d[v], v));
            }
        }
    }
}
signed main() {
    freopen("desert.in", "r", stdin);
    freopen("desert.out", "w", stdout);
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        fgets(s + 1, 110, stdin);
        int mm = strlen(s + 1), m = 0;
        for (int j = 1; j <= mm; j++) {
            if (s[j] != ' ' && s[j] != '\n') mp[i][++m] = s[j];
        }
        for (int j = 1; j <= n; j++) {
            if (mp[i][j] == '@') sx = i, sy = j;
            else if (mp[i][j] == '*') ed[++edcnt] = xy2i(i, j);
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     printf("%s\n", mp[i] + 1);
    // }
    make_map();
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        dij(i);
        int minn = 0x3f3f3f3f;
        for (int j = 1; j <= edcnt; j++) {
            minn = min(minn, d[ed[j]]);
        }
        // println(minn);
        ans = max(ans, minn);
    }
    println(ans);
    return 0;
}
/*
3
-X*
@-*
XX-
*/