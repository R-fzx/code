#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const int mod = 10007;

int n, m, k;
int ans;

int gcd (int x, int y) {
    return (y == 0 ? x : gcd(y, x % y));
}

void dfs (int x, int now) {
    if (x == n + 1) {
        if (now % k == 0 && gcd(now / k, k) == 1) {
            ans++;
        }
        return;
    }
    for (int i = 1; i <= m; i++) {
        dfs(x + 1, now * i);
    }
}

int main () {
    freopen("orbits.in", "r", stdin);
    freopen("orbits.out", "w", stdout);
    cin >> n >> m >> k;
    dfs(1, 1);
    cout << ans % mod;
    return 0;
}