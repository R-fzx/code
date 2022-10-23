#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e3 + 5;

int n;
ll ans;
int a[N], v[N];
bool f[N];

void dfs (int x, ll now) {
    if (x == n + 1) {
        ans = max(ans, now);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (f[i] == 0) {
            int mx = 0;
            for (int j = 1; j <= n; j++) {
                if (f[j] == 1 && (a[i] & a[j]) == 0) {
                    mx = max(mx, a[j]);
                }
            }
            f[i] = 1;
            dfs(x + 1, now + mx);
            f[i] = 0;
        }
    }
}

int main () {
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0); 
    cout << ans;
    return 0;
}