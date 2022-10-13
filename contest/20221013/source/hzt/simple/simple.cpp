#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6 + 5;
const int v = 5e7;

int T, n, q;
int x[N], y[N];
ll ans = 0;

int Max (int x, int y) {
    return (x > y ? x : y);
}

int main () {
    freopen("simple.in", "r", stdin);
    freopen("simple.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
        }
        while (q--) {
            int a, b;
            cin >> a >> b;
            ans = 0;
            for (int i = 1; i <= n; i++) {
                ans += Max(abs(a - x[i]), abs(b - y[i]));
            }
            cout << ans << '\n';
        }
    }
    return 0;
}