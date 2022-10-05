#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 100005;
int n;
int a[maxn], b[maxn];
int x[maxn];
int ans = 1e9;
signed main() {
    freopen("scalar.in", "r", stdin);
    freopen("bf.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i], x[i] = i;
    do {
        int res = 0;
        for (int i = 1; i <= n; i++) res += a[i] * b[x[i]];
        ans = min(ans, res);
    } while (next_permutation(x + 1, x + 1 + n));
    cout << ans << endl;
    return 0;
}