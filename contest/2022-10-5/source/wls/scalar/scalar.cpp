#include <bits/stdc++.h>
#define int long long
#define println(x) print(x), putchar('\n')
#define printsp(x) print(x), putchar(' ')
#define printpa(x, y) printsp(x), println(y)
using namespace std;
const int N = 8e2 + 10;
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
void print(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
int n;
int x[N], y[N];
int dp[N], f[N][N]; // f - y
bool cmp(int a, int b) { return a > b; }
signed main() {
    freopen("scalar.in", "r", stdin);
    freopen("scalar.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++) x[i] = read();
    for (int i = 1; i <= n; i++) y[i] = read();
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += x[i] * y[i];
    println(ans);
    return 0;
}