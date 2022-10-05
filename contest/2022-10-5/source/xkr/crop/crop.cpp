#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 100005;
int n;
int a, b, c, d, X, Y, m;
int x[maxn], y[maxn];
int p[5][5];
int s[5][5];
int ans;
signed main() {
    freopen("crop.in", "r", stdin);
    freopen("crop.out", "w", stdout);
    cin >> n >> a >> b >> c >> d >> X >> Y >> m;
    x[1] = X % 3, y[1] = Y % 3;
    for (int i = 2; i <= n; i++) {
        X = (a * X + b) % m;
        Y = (c * Y + d) % m;
        x[i] = X % 3; y[i] = Y % 3;
    }
    for (int i = 1; i <= n; i++) {
        ans += s[(3 - x[i]) % 3][(3 - y[i]) % 3];
        for (int j = 0; j <= 2; j++)
            for (int k = 0; k <= 2; k++)
                s[j][k] += p[(j + 3 - x[i]) % 3][(k + 3 - y[i]) % 3];
        p[x[i]][y[i]]++;
    }
    cout << ans << endl;
    return 0;
}