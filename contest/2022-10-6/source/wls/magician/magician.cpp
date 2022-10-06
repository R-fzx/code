#include <bits/stdc++.h>
#define int long long
#define println(x) print(x), putchar('\n')
#define printsp(x) print(x), putchar(' ')
#define printpa(x, y) printsp(x), println(y)
using namespace std;
const int N = 1e5 + 10, mod = 1000000009;
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
int n, m;
bool flag[N];
signed main() {
    freopen("magician.in", "r", stdin);
    freopen("magician.out", "w", stdout);
    n = read(), m = read();
    int ans = 1;
    for (int i = 1; i <= m; i++) {
        int a = read(), b = read();
        if (flag[a] && flag[b]) ans = (ans << 1) % mod;
        flag[a] = flag[b] = 1;
        println(ans - 1);
    }
    return 0;
}