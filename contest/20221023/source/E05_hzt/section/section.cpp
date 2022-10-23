#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, m, q, ans, v;
int l = N, r = 0;
int a[N], _a[N];
int tl[N], tr[N], len;

int Query (int x) {
    for (int i = len; i >= 1; i--) {
        if (x >= tl[i] && x <= tr[i]) {
            x = tr[i] - (x - tl[i]);
        }
    }
    return x;
}

void Rs () {
    for (int i = 1; i <= n; i++) {
        _a[i] = a[i];
    }
    for (int i = l; i <= r; i++) {
        a[i] = _a[Query(i)];
    }
    len = 0;
    l = N, r = 0;
}

int main () {
    freopen("section.in", "r", stdin);
    freopen("section.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    v = sqrt(n) + 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            len++;
            tl[len] = x, tr[len] = x + m - 1;
            l = min(l, tl[len]);
            r = max(r, tr[len]);
        }
        else {
            ans ^= a[Query(x)];
        }
        if (len > v) {
            Rs();
        }
    }
    cout << ans;
    return 0;
}