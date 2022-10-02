#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int n, m;
int a[maxn];
int cnt[maxn];
int lst;
int main() {
    freopen("dandelion.in", "r", stdin);
    freopen("bf.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int l, r; cin >> l >> r;
        l = (l + lst - 1) % n + 1; r = (r + lst - 1) % n + 1;
        if (l > r) swap(l, r);
        // cout << l << ' ' << r << endl;
        memset(cnt, 0, sizeof(cnt));
        int x = 0;
        for (int j = l; j <= r; j++) {
            cnt[a[j]]++;
            if (cnt[a[j]] > cnt[x]) x = a[j];
            else if (cnt[a[j]] == cnt[x]) x = min(x, a[j]);
        }
        cout << (lst = x) << endl;
    }
    return 0;
}