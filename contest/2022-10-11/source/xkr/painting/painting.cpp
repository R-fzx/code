#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n, m, k;
int inv[2005];
int c[2005][2005];
int r[2005];
int ans;
int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return res;
}
void init() {
    for (int i = 1; i <= 2000; i++) inv[i] = power(i, mod - 2);
    c[1][0] = c[1][1] = 1;
    for (int i = 2; i <= 2000; i++)
        for (int j = 0; j <= i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    // int res = 1;
}
int C(int n, int m) {
    int res = 1;
    for (int i = n; i >= n - m + 1; i--) {
        res = res * i % mod * inv[i - (n - m)] % mod;
        // cout << i << ' ' << i - n + m << ' ' << inv[i - (n - m)] << endl;
    }
    return res;
}
int calc(int x, int y) {
    int res = C(k, x) * c[x][y] % mod * C(k - x, x - y) % mod * power(x, n * (m - 2)) % mod;
    return res;
}
int get(int x) {
    int res = 1, p = 1;
    for (int i = 0; i <= x; i++) {
        res = res + c[n][i] * power(x - i, n) * p;
        // cout << res << endl;
        p *= -1;
    }
    return res;
}
signed main() {
    cin >> n >> m >> k;
    init();
    // cout << C(2, 2) << endl;
    // cout << inv[2] << endl;
    // cout << power(2, mod - 2) << endl;
    for (int x = 1; x <= min(k, n); x++) {
        int res = get(x);
        for (int y = max(0ll, 2 * x - n); y <= x; y++)
            ans = (ans + calc(x, y) * res * res) % mod;
    }
    // cout << calc(1, 0) << endl;
    // cout << C(2, 1) << endl;
    // cout << C(1, 0) << endl;
    // cout << C(1, 1) << endl;
    cout << ans << endl;
    cout << get(2) << endl;
    // cout << get(1) << endl;
    // cout << calc(2, 2) * get(2) << endl;
    // cout << get(2) << endl;
    // cout << C(2, 2) << ' ' << C(2, 2) << ' ' << C(0, 0) << ' ' << power(2, 0) << endl;
    return 0;
}