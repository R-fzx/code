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
#define xy2i(x, y) (((x) - 1) * (m) + (y))
#define in(x, y) ((1 <= (x)) && ((x) <= (n)) && (1 <= (y)) && ((y) <= (m)))
using namespace std;
const int N = 1e2 + 10;
const double eps = 1e-6;
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
int T;
double L;
int n, m;
char mp[N][N];
int sx, sy, tx, ty;
int dx[4] = {1, -1, 0, 0},
    dy[4] = {0, 0, 1, -1};
struct node {
    int v, type; // 0 - Up/Down;
};
vector<node> G[N * N];
void make_map() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            G[xy2i(i, j)].clear();
            if (mp[i][j] == '#') continue;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!in(x, y) || mp[x][y] == '#') continue;
                G[xy2i(i, j)].push_back((node){xy2i(x, y), k / 2});
            }
        }
    }
}
bool vis[N * N];
double d[N * N];
bool dij(double vl) {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n * m; i++) d[i] = 1e15;
    // memset(d, 0x1f, sizeof(d));
    // printf("%lf %d %d\n", d[1], d[1], sizeof(int));
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > q;
    int s = xy2i(sx, sy);
    d[s] = 0.0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int now = q.top().second; q.pop();
        if (vis[now]) continue;
        vis[now] = 1;
        for (int i = 0; i < G[now].size(); i++) {
            int v = G[now][i].v, tp = G[now][i].type;
            double dis;
            if (tp) dis = 1.0;
            else dis = vl;
            if (d[v] > d[now] + dis) {
                d[v] = d[now] + dis;
                q.push(make_pair(d[v], v));
            }
        }
    }
    return d[xy2i(tx, ty)] >= L;
}
signed main() {
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    scanf("%d\n", &T);
    while (T--) {
        scanf("%lf%d%d\n", &L, &n, &m);
        for (int i = 1; i <= n; i++) {
            fgets(mp[i] + 1, 110, stdin);
            for (int j = 1; j <= m; j++) {
                if (mp[i][j] == 'S') sx = i, sy = j;
                else if (mp[i][j] == 'E') tx = i, ty = j;
            }
        }
        make_map();
        double l = 0, r = 10;
        while (l + eps < r) {
            double mid = (l + r) / 2.0;
            if (dij(mid)) {
                r = mid;
            } else l = mid;
        }
        printf("%.5lf\n", l);
    }
    // cerr << clock() << endl;
    return 0;
}
/*
2
2.5 4 5
#####
#S  #
#  E#
#####
21 13 12
############
#S##     #E#
# ##  #  # #
#   # #  # #
### # #  # #
#   # #  # #
#  ## #  # #
##  # #  # #
### # #  # #
##  # #  # #
#  ## #    #
#     #    #
############
*/