#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 205, maxm = 50005;
int n, m, p, q;
struct node {int u, v, x, y, p;};
vector<node> a[maxn];
int dx[maxm], dy[maxm];
int ans = 2e18;
int cnt;
int fuck, l1, l2;
bool f[maxn];
void dfs(int x) {
    cnt++; f[x] = 1;
    for (int i = 0; i < a[x].size(); i++) {
        int y = a[x][i].v;
        if (f[y] || !a[x][i].p) continue;
        dfs(y);
    }
}
bool check(int x, int y) {
    // cout << ":::" << x << ' ' << y << endl;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < a[i].size(); j++)
            if (a[i][j].x <= x && a[i][j].y <= y) a[i][j].p = 1;
            else a[i][j].p = 0;
    cnt = 0; dfs(1);
    return cnt == n;
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> p >> q;
    for (int i = 1; i <= m; i++) {
        int u, v, x, y; cin >> u >> v >> x >> y;
        a[u].push_back((node){u, v, x, y, 1}); a[v].push_back((node){v, u, x, y, 1});
        dx[i] = x, dy[i] = y;
    }
    sort(dx + 1, dx + 1 + m);
    sort(dy + 1, dy + 1 + m);
    for (int i = 1; i <= m; i++) {
        int l = 0, r = m + 1;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            // cerr << "***" << mid << endl;
            if (check(dx[i], dy[mid])) r = mid;
            else l = mid;
        }
        if (r != m + 1) ans = min(ans, dx[i] * p + dy[r] * q);
    }
    if (ans == 2e18) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}