#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1000005, mod = 1e9 + 7;
int n;
int p[maxn];
int x[maxn], cnt;
int ans = 1;
void get() {
    for (int i = 2; i <= n; i++)
        if (!p[i]) {
            x[++cnt] = i;
            for (int j = i + i; j <= n; j += i) p[j] = 1;
        }
}
signed main() {
    freopen("sakura.in", "r", stdin);
    freopen("sakura.out", "w", stdout);
    cin >> n;
    get();
    for (int i = 1; i <= cnt; i++) {
        int k = x[i], sum = 0;
        while (k <= n) {sum += n / k; k *= x[i];}
        ans = ans * (sum * 2 + 1) % mod;
    }
    cout << ans << endl;
    return 0;
}