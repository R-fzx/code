#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;
int n, ans, res;
int a[maxn], b[maxn], c[maxn];
int cnt[maxn], p[maxn];
int t[maxn], f[maxn];
int init() {
    random_shuffle(b + 1, b + 1 + n);
    return 1;
}
void work() {
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = i; p[a[i]]++;
    }
    int sum = 0; ans = 0;
    do {
        for (int i = 1; i <= n; i++) cnt[a[i]] = p[a[i]];
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            int x = b[i];
            int lza = cnt[a[x] - 1] + cnt[a[x]] + cnt[a[x] + 1];
            if (!lza) {tmp++; continue;}
            int rd = rand()  % lza + 1;
            if (rd <= cnt[a[x] - 1]) cnt[a[x] - 1]--;
            else if (rd <= cnt[a[x] - 1] + cnt[a[x]]) cnt[a[x]]--;
            else cnt[a[x] + 1]--;
        }
        ans = max(ans, tmp);
        if (++sum == 40000) break;
    } while (init());
    cout << ans << endl;
}
int main() {
    freopen("puppet.in", "r", stdin);
    freopen("puppet.out", "w", stdout);
    while (cin >> n) work();
    return 0;
}