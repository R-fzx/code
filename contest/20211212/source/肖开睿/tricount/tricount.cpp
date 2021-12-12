#include<bits/stdc++.h>
#define ll long long
using namespace std;
const double pi = acos(-1);
int n;
ll ans;
double a[100005], up[100005], down[100005];
int s1, s2;
ll calc1(double x) {
    int pos = lower_bound(up + 1, up + 1 + s1, x) - up;
    return 1ll * (pos - 1) * (s1 - pos + 1);
}
ll calc2(double x) {
    int pos = lower_bound(down + 1, down + 1 + s2, x) - down;
    return 1ll * (pos - 1) * (s2 - pos + 1);
}
int main() {
    freopen("tricount.in", "r", stdin);
    freopen("tricount.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        double dist = sqrt(x * x + y * y);
        if (x > 0 && y >= 0) a[i] = asin(y / dist);
        if (x <= 0 && y > 0) a[i] = pi - asin(y / dist);
        if (x < 0 && y <= 0) a[i] = pi + asin(-y / dist);
        if (x >= 0 && y < 0) a[i] = 2 * pi - asin(-y / dist);
        a[i] *= 180 / pi;
        // cout << a[i] << endl;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        if (a[i] >= 180) {s1 = i - 1, s2 = n - i + 1; break;}
    // cout << s1 << ' ' << s2 << endl;
    for (int i = 1; i <= s1; i++) up[i] = a[i];
    for (int i = 1; i <= s2; i++) down[i] = a[i + s1];
    for (int i = 1; i <= s1; i++) ans += calc2(up[i] + 180);
    for (int i = 1; i <= s2; i++) ans += calc1(down[i] - 180);
    cout << ans << endl;
    return 0;
}