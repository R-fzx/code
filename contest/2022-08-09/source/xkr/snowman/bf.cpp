#include<bits/stdc++.h>
using namespace std;
int n;
int a[105];
int ans;
void check(int l1, int r1, int l2, int r2) {
    bool p = 0;
    for (int i = 1; i <= r1 - l1; i++)
        if (a[l1 + i] - a[l2 + i] != a[l1] - a[l2]) {p = 1; break;}
    if (!p) {
        int k = min(r1 - l1 + 1, abs(l1 - l2));
        ans = max(ans, k);
    }
}
int main() {
    freopen("snowman.in", "r", stdin);
    freopen("bf.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int l1 = 1; l1 <= n; l1++)
        for (int r1 = l1 + 1; r1 <= n; r1++)
            for (int l2 = 1; l2 <= n; l2++)
                check(l1, r1, l2, l2 + r1 - l1);
    cout << ans << endl;
    return 0;
}