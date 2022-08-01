#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, m;
vector<int> a[maxn];
int in[maxn];
int out[maxn];
int f[maxn];
queue<int> q;
int ans;
int main() {
    freopen("lyx.in", "r", stdin);
    freopen("lyx.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        a[x].push_back(y); in[y]++; out[x]++;
    }
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) q.push(i), f[i] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (!out[u]) ans += f[u];
        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i];
            f[v] += f[u];
            if (--in[v] == 0) q.push(v);
        }
    }
    cout << ans << endl;
    return 0;
}