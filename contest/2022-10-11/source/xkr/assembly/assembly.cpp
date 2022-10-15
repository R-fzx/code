#include<bits/stdc++.h>
using namespace std;
int n, k, a;
int b[9], l[9];
double ans;
void solve() {
    double res = 0;
    for (int i = 0; i < (1 << n); i++) {
        double p = 1; int sum = 0, cnt = 0;
        for (int j = 1; j <= n; j++)
            if ((i >> j - 1) & 1) cnt++, p *= (double)l[j] / 100.;
            else p *= (double)(100 - l[j]) / 100., sum += b[j];
        if (cnt * 2 > n) res += p;
        else res += p * (double)a / (a + sum);
    }
    ans = max(ans, res);
}
void dfs(int x, int k) {
    if (x == n + 1) return solve();
    for (int i = 0; i <= min((100 - l[i]) / 10, k); i++) {
        l[x] += i * 10;
        dfs(x + 1, k - i);
        l[x] -= i * 10;
    }
}
int main() {
    freopen("assembly.in", "r", stdin);
    freopen("assembly.out", "w", stdout);
    cin >> n >> k >> a;
    for (int i = 1; i <= n; i++) cin >> b[i] >> l[i];
    dfs(1, k);
    printf("%.6lf\n", ans);
    return 0;
}