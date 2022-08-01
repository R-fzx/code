#include<bits/stdc++.h>
#define ull unsigned int long long
using namespace std;
int n, len, m;
string t[205], s;
ull k[205];
int f[205];
double dp[1005][205];
ull hsh[1000005], pw[1000005];
int lst[205];
double p;
double ans[205];
unordered_map<ull, int> mp;
struct node {
    int s, id;
    bool operator < (const node &a) const {return s < a.s;}
} a[205];
ull get(int l, int r) {return hsh[r] - hsh[l - 1] * pw[r - l + 1];}
int main() {
    freopen("ppfish.in", "r", stdin);
    freopen("ppfish.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) {
        t[i] = " " + t[i];
        for (int j = 1; j < t[i].size(); j++)
            k[i] = k[i] * 133331 + t[i][j];
    }
    cin >> s; len = s.size(); s = " " + s;
    pw[0] = 1;
    for (int i = 1; i <= len; i++)
        hsh[i] = hsh[i - 1] * 133331 + s[i], pw[i] = pw[i - 1] * 133331;
    for (int i = 1; i <= 20; i++)
        for (int l = 1; i + l - 1 <= len; l++)
            mp[get(i, i + l - 1)]++;
    for (int i = 1; i <= n; i++) a[i] = (node){mp[k[i]], i};
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        for (int j = i - 1; j >= 1; j--)
            if (a[i].s > a[j].s) {lst[i] = j; break;}
    cin >> p >> m;
    for (int i = 1; i <= n; i++) dp[0][i] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = dp[i - 1][j] * (1 - dp[i - 1][lst[j]]) * p + dp[i - 1][lst[j]];
    for (int i = 1; i <= n; i++) ans[a[i].id] = dp[m][i];
    for (int i = 1; i <= n; i++) printf("%.3lf ", ans[i]);
    cout << endl;
    cerr << clock() * 1. / 1000 << endl;
    return 0;
}