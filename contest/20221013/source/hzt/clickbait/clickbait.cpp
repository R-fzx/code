#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int main () {
    freopen("clickbait.in", "r", stdin);
    freopen("clickbait.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        char c;
        cin >> c;
        if (c >= '1' && c <= '9') {
            k = max(k, c - '0');
        }
    }
    for (int i = 2; i <= k; i++) {
        cout << i << '\n';
    }
    cout << 1;
    return 0;
}