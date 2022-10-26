#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 100005;
int n;
int a[maxn];
int ans = 1e18, maxx;
int count(int x) {
    int res = 0;
    while (x) x -= (x & -x), res++;
    return res;
}
int calc(int x) {
    int res = 0;
    for (int i = 1; i <= n; i++) res += count(x - a[i]);
    return res;
}
inline int read() {
    int x = 0; char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {x = (x << 3) + (x << 1) + (c ^ 48); c = getchar();}
    return x;
}
signed main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        maxx = max(maxx, a[i]);
    }
    for (int i = maxx; i <= maxx + 500; i++) ans = min(ans, calc(i));
    cout << ans << endl;
    return 0;
}