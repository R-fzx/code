#include <bits/stdc++.h>
#define println(x) print(x), putchar('\n')
#define printsp(x) print(x), putchar(' ')
#define printpa(x, y) printsp(x), println(y)
using namespace std;
const int N = 2e3 + 10;
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
int n = 20;
signed main() {
    freopen("seventeen.in", "w", stdout);
    srand(time(NULL));
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        int x = rand() % 100 + 1, y = rand() % 100 + 1;
        printf("%d %d\n", x, y);
    }
    return 0;
}