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
int a[N];
signed main() {
    freopen("scalar.in", "r", stdin);
    // freopen("scalar.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++) x[i] = read(), a[i] = i;
    for (int i = 1; i <= n; i++) y[i] = read();
    int minn = 0x3f3f3f3f3f3f3f3f;
    do {
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += x[a[i]] * y[i];
        minn = min(minn, ans);
    } while (next_permutation(a + 1, a + n + 1));
    println(minn);
    return 0;
}