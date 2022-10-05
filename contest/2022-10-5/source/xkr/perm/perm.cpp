#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;
int p[10];
int ans;
int A(int n, int m) {
    int res = 1;
    for (int i = n; i >= n - m + 1; i--) res *= i;
    return res;
}
signed main() {
    freopen("perm.in", "r", stdin);
    freopen("perm.out", "w", stdout);
    cin >> s; n = s.size();
    for (int i = 0; i < n; i++) p[s[i] - '0']++;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {p[0]--; continue;}
        int s1 = 0, s2 = 0, s3 = 0;
        for (int j = 0; j <= 9; j++) {
            if (j != 0) s1 += p[j];
            if (j < s[i] - '0' && j != 0) s2 += p[j];
        }
        ans += s2 * A(n - i - 1, s1 - 1);
        ans += (p[0] > 0) * A(n - i - 1, s1);
        // cout << s1 << ' ' << s2 << ' ' << ans << endl;
        p[s[i] - '0']--;
    }
    cout << ans << endl;
    return 0;
}