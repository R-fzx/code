#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 100005;
int n;
int a[maxn], b[maxn];
int ans;
signed main() {
    freopen("scalar.in", "r", stdin);
    freopen("scalar.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    sort(a + 1, a + 1 + n); sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) ans += a[i] * b[n - i + 1];
    cout << ans << endl;
    return 0;
}