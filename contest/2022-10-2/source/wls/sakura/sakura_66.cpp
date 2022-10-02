#include <bits/stdc++.h>
#define println(x) print(x), putchar('\n')
#define printsp(x) print(x), putchar(' ')
#define printpa(x, y) printsp(x), println(y)
using namespace std;
const int N = 1e5 + 10;
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
int n, jc = 1;
signed main() {
    n = read();
    for (int i = 1; i <= n; i++) jc *= i;
    int ans = 0;
    for (int x = 1; x <= 100; x++) {
        for (int y = 1; y <= 100; y++) {
            ans += (x * y == jc * (x + y));
        }
    }
    println(ans);
    return 0;
}