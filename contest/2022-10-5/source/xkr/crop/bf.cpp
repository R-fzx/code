#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 100005;
int n;
int a, b, c, d, X, Y, m;
int x[maxn], y[maxn];
int p[3][3];
int s[3][3];
int ans;
signed main() {
    freopen("crop.in", "r", stdin);
    freopen("bf.out", "w", stdout);
    cin >> n >> a >> b >> c >> d >> X >> Y >> m;
    x[1] = X, y[1] = Y;
    for (int i = 2; i <= n; i++) {
        X = (a * X + b) % m;
        Y = (c * Y + d) % m;
        x[i] = X % 3; y[i] = Y % 3;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            for (int k = 1; k < j; k++)
                if ((x[i] + x[j] + x[k]) % 3 == 0 && (y[i] + y[j] + y[k]) % 3 == 0) ans++;
    cout << ans << endl;
    return 0;
}