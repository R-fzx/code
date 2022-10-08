#include<bits/stdc++.h>
using namespace std;
int n, m;
int f[205][205];
int x[205];
int ans, res;
bool check(int cnt) {
    for (int i = 1; i <= cnt; i++)
        for (int j = 1; j < i; j++)
            if (f[x[i]][x[j]] || f[x[j]][x[i]]) return 0;
    return 1;
}
void Sub1() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] |= (f[i][k] & f[k][j]);
    for (int i = 0; i < (1 << n); i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            if ((i >> j - 1) & 1) x[++cnt] = j;
        if (check(cnt) && ans < cnt) ans = cnt, res = i;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        if ((res >> i - 1) & 1) cout << i << ' ';
    cout << endl;
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        f[x][y] = 1;
    }
    if (n <= 20) Sub1();
    else cout << 1 << endl << 1 << endl;
    return 0;
}