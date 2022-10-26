#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 200005;
int n, m, k;
int a[maxn];
int lg[maxn];
int f[maxn][25];
struct node {int x, y;} d[maxn];
void init() {
    lg[0] = -1;
    for (int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1, f[i][0] = a[i];
    for (int j = 1; j <= lg[n]; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}
int query(int l, int r) {
    int k = lg[r - l + 1];
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}
int ans;
int check(node a, node b) {
    if (abs(a.x - b.x) <= 1) return abs(a.x - b.x) + abs(a.y - b.y);
    int s = query(a.x, b.x);
    if (min(a.y, b.y) >= s) return a.y + b.y - 2 * s + abs(a.x - b.x);
    else return abs(a.x - b.x) + abs(a.y - b.y);
}
void Sub1() {
    for (int i = 1; i <= m; i++)
        for (int j = 1; j < i; j++)
            if (check(d[i], d[j]) <= k) ans++;
    cout << ans << endl;
}
void Sub2() {

}
signed main() {
    freopen("h.in", "r", stdin);
    freopen("h.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> d[i].x >> d[i].y;
    if (n <= 1000) Sub1();
    return 0;
}
//我这个做法他妈假了
//妈的被蚊子咬影响了我的状态