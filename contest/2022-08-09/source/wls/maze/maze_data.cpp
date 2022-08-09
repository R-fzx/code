#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int n = 10, m = 15;
signed main() {
    freopen("maze.in", "w", stdout);
    printf("%d %d %d\n", n, m, (int)((double)(rand()) / RAND_MAX * 1e3));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (rand() < RAND_MAX / 10) printf("0 ");
            else printf("%d ", (int)((double)(rand()) / RAND_MAX * 1e3));
        }
        puts("");
    }
    return 0;
}