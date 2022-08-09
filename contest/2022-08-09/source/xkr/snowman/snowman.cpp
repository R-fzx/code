#include<bits/stdc++.h>
#define ull unsigned int long long
using namespace std;
const int maxn = 500005;
int n;
int d[maxn], a[maxn], ind[maxn];
ull pw[maxn], hsh[maxn];
unordered_map<ull, int> mp;
void discrete() {
    memcpy(ind, a, sizeof(a)); sort(ind + 1, ind + 1 + n);
    int len = unique(ind + 1, ind + 1 + n) - ind - 1;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(ind + 1, ind + 1 + n, a[i]) - ind;
}
void init() {
    pw[0] = 1;
    for (int i = 1; i < n; i++)
        pw[i] = pw[i - 1] * 133331, hsh[i] = hsh[i - 1] * 133331 + a[i];
}
ull get(int l, int r) {return hsh[r] - hsh[l - 1] * pw[r - l + 1];}
bool check(int x) {
    x--;
    mp.clear();
    int maxn = 0;
    for (int i = 1; i + x - 1 < n; i++) {
        ull k = get(i, i + x - 1);
        if (!mp[k]) mp[k] = i;
        else maxn = max(maxn, i - mp[k]);
    }
    return maxn >= x + 1;
}
int main() {
    freopen("snowman.in", "r", stdin);
    freopen("snowman.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
    for (int i = 1; i < n; i++) a[i] = d[i + 1] - d[i];
    discrete(); init();
    int l = 0, r = n;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}