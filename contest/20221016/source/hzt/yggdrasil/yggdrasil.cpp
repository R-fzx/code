#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using pr = pair<int, int>;
using ll = long long;

const int N = 7e5 + 5;
const ll inf = 1e18;

int n, k;
int a[N];

vector<pr> e[N];

ll dfs (int x, int fa, int now) {
    ll res = 0;
    for (auto i : e[x]) {
        if (i.first != fa) {
            res += dfs(i.first, x, now + i.second - a[x]);
        }
    }
    return res + now;
}

int main () {
    freopen("yggdrasil.in", "r", stdin);
    freopen("yggdrasil.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        e[x].push_back({y, z});
        e[y].push_back({x, z});
    }
    ll ans = inf;
    for (int i = 1; i <= n; i++) {
        ll now = dfs(i, 0, 0);
        if (now < ans) {
            ans = now;
            k = i;
        }
    }
    cout << k << '\n' << ans;
    return 0;
}