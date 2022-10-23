#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, m;
ll a[N], b[N];

bool Query (int l, int r) {
    int len = 0;
    for (int i = l; i <= r; i++) {
        len++;
        b[len] = a[i];
    }
    stable_sort(b + 1, b + len + 1);
    for (int i = 1; i <= len - 2; i++) {
        if (b[i] + b[i + 1] > b[i + 2]) {
            return 1;
        }
    }
    return 0;
}

int main () {
    freopen("triangle.in", "r", stdin);
    freopen("triangle.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        if (n > 1000 && (r - l) > 128) {
            cout << "Yes\n";
        }
        else {
            cout << (Query(l, r) ? "Yes" : "No") << '\n';
        }
    }
    return 0;
}