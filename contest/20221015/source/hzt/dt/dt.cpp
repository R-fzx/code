#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, m;
int a[N];
ll ans;

int main () {
    freopen("dt.in", "r", stdin);
    freopen("dt.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ans += min(a[x], a[y]);
    }
    cout << ans;
    return 0;
}