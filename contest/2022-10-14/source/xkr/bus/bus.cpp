#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1000005;
int n;
int a[maxn];
int minn, ans;
signed main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    minn = 1e9;
    for (int i = 1; i <= n; i++) ans += (minn = min(minn, a[i]));
    cout << ans << endl;
    return 0;
}