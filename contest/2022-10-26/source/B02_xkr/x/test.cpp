#include<bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize("inline")
using namespace std;
const int maxn = 100005;
int n;
struct node {
    int x, y;
    bool operator < (const node &a) const {return x - y > a.x - a.y;}
} a[maxn];
int x[maxn];
int ans;
vector<int> d[maxn];
int in[maxn];
int f[maxn];
queue<int> q;
bool p = 1;
void topo() {
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) q.push(i), f[i] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < d[u].size(); i++) {
            int v = d[u][i];
            f[v] = max(f[v], f[u] + 1);
            if (--in[v] == 0) q.push(v);
        }
    }
}
inline int read() {
    int x = 0; char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {x = (x << 3) + (x << 1) + (c ^ 48); c = getchar();}
    return x;
}
void Sub2() {
    for (int i = 1; i <= n; i++) x[i] = a[i].x;
    sort(x + 1, x + 1 + n);
    int len = unique(x + 1, x + 1 + n) - x - 1;
    cout << len << endl;
}
int main() {
    freopen("x.in", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i].x = read(); a[i].y = read();
        if (a[i].y != 0) p = 0;
    }
    if (p) {Sub2(); return 0;}
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= min(i + 2000, n); j++)
            if (a[i].x - a[i].y > a[j].x + a[j].y) d[i].push_back(j), in[j]++;
    topo();
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout << ans << endl;
    cerr << clock() * 1. / 1000 << endl;
    return 0;
}
//我完全可以卡你
//冲击失败
//你会不会写快读那两行什么p1p2buf之类的东西