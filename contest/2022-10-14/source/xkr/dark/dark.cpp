#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 400005;
int n; 
struct node {
    int x, y;
    bool operator < (const node &a) const {return (x + 2242) * (y + 2242) > (a.x + 2242) * (a.y + 2242);}
} a[maxn];
int dist(node a, node b) {return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);}
int ans = 1e18;
signed main() {
    freopen("dark.in", "r", stdin);
    freopen("dark.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= min(i + 100, n); j++)
            ans = min(ans, dist(a[i], a[j]));
    for (int i = 1; i <= 230; i++)
        for (int j = n; j >= max(i + 1, n - 230); j--)
            ans = min(ans, dist(a[i], a[j]));
    printf("%.3lf\n", sqrt(ans) / 2);
    return 0;
}