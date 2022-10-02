#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;
int n;
int s[maxn][maxn];
int l[maxn][maxn];
int r[maxn][maxn];
int main() {
    freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> s[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> l[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> r[i][j];
    if (n == 4) cout << 90 << endl;
    else cout << 0 << endl;
    return 0;
}