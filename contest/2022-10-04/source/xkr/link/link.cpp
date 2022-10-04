#include<bits/stdc++.h>
using namespace std;
const int maxn = 205, mod = 1e9 + 7;
int n = 1;
vector<int> a[maxn];
int f[maxn];
int fuck[maxn], cao[maxn], lza[maxn], yxy[maxn];
int ans;
int md(int x) {return (x % mod + mod) % mod;}
void dfs(int x) {
    int sum = 0, res = 0;
    for (int i = 0; i < a[x].size(); i++) {
        int y = a[x][i];
        dfs(y);
        cao[x] += cao[y] + 1;
        sum = (sum + cao[y] + 1) % mod;
        res = (res + 1ll * (cao[y] + 1) * (cao[y] + 1) % mod) % mod;
    }
    yxy[x] = 1ll * md((1ll * sum * sum - res) / 2);
    for (int i = 0; i < a[x].size(); i++) yxy[x] += yxy[a[x][i]];
    for (int i = 0; i < a[x].size(); i++) {
        int y = a[x][i];
        sum = md(sum - cao[y] - 1);
        res = md(res - 1ll * (cao[y] + 1) * (cao[y] + 1));
        lza[x] = (lza[x] + yxy[y] * md(1ll * sum * sum - res) / 2) % mod;
        sum = md(sum + cao[y] + 1);
        res = md(res + 1ll * (cao[y] + 1) * (cao[y] + 1));
        lza[x] += lza[y];
    }
    for (int i = 0; i < a[x].size(); i++) fuck[x] += lza[a[x][i]];
}
int main() {
    freopen("link.in", "r", stdin);
    freopen("link.out", "w", stdout);
    while (cin >> f[++n]);
    n--;
    for (int i = 2; i <= n; i++) a[++f[i]].push_back(i);
    dfs(1);
    for (int i = 1; i <= n; i++) ans += fuck[i];
    cout << ans << endl;
    return 0;
}