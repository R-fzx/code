#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int n, a[N], b[N];
signed main() {
    // freopen("snowman.in", "r", stdin);
    // freopen("snowman.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read(), b[i - 1] = a[i] - a[i - 1];
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);

    return 0;
}