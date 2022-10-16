#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e4 + 5;

int T, n;

ll gcd (ll x, ll y) {
    return (y == 0 ? x : gcd(y, x % y));
}

struct D {
    ll x, y;

    void G () {
        ll g = gcd(x, y);
        x /= g, y /= g;
    }
} ans, p[N];

D operator+ (D a, D b) {
    D res;
    res.x = a.x * b.y + a.y * b.x;
    res.y = a.y * b.y;
    res.G();
    return res;
}

void Print (D a) {
    cout << a.x << '/' << a.y << '\n';
}

bool isP (ll x) {
    if (x <= 1) {
        return 0;
    } 
    if (x == 2) {
        return 1;
    }
    ll sq = sqrt(x);
    for (int i = 2; i <= sq; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

ll L (int x) {
    for (int i = x; ; i--) {
        if (isP(i)) {
            return i;
        }
    } 
}

ll R (int x) {
    for (int i = x + 1; ; i++) {
        if (isP(i)) {
            return i;
        }
    }
}
 
int main () {
    freopen("prime.in", "r", stdin);
    freopen("prime.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    for (int i = 2; i <= 10000; i++) {
        p[i].x = 1, p[i].y = L(i) * R(i);
    }
    while (T--) {
        cin >> n;
        ans = p[2];
        for (int i = 3; i <= n; i++) {
            ans = ans + p[i];
        }
        Print(ans);
    }
    return 0;
}