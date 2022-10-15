#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;
int a[N], cnt[N], mx;

int main () {
    freopen("vote.in", "r", stdin);
    freopen("vote.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    } 
    for (int i = 1; i <= m; i++) {
        cnt[a[i]]++;
        mx = max(mx, cnt[a[i]]);
    }
    if (mx == 1) {
        cout << "0.0000";
        return 0;
    }
    int ans = 0; 
    int t = (n - m);
    for (int i = 1; i <= n; i++) {
        if (cnt[i] != mx) {
            t += cnt[i];
        }
        if (cnt[i] == mx) {
            ans++;
        }
    }
    double p = 1;
    while (t % ans != 0 && ans != 1) {
        int k = t % ans;
        p *= (k * 1.0 / ans);
        t += (ans - k) * mx;
        ans = k;
    }
    if (ans == 1) {
        printf("%.4lf", p);
    }
    else {
        cout << "0.0000";
    }
    return 0;
}