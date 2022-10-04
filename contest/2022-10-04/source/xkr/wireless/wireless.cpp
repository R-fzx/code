#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int sum[3005][3005];
int get(int x, int y, int z, int w) {return sum[z][w] - sum[z][y - 1] - sum[x - 1][w] + sum[x - 1][y - 1];}
int ans;
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while (isdigit(c)) {x = (x << 3) + (x << 1) + (c ^ 48); c = getchar();}
    return x * f;
}
int main() {
    freopen("wireless.in", "r", stdin);
    freopen("wireless.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x, y; x = read(); y = read();
        sum[x][y] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= m; y++)
            for (int z = x; z <= n; z++) {
                if (get(x, y, z, y)) break;
                int l = y - 1, r = m + 1;
                while (l + 1 < r) {
                    int mid = l + r >> 1;
                    if (!get(x, y, z, mid)) l = mid;
                    else r = mid;
                }
                ans = max(ans, (z - x + 1) * (l - y + 1));
            }
    cout << ans << endl;
    cerr << clock() * 1. / 1000 << endl;
    return 0;
}