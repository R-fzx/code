#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int n, m;
char s[N][N];
char cmex(int x, int y) {
    int ca = 0, cb = 0, cc = 0;
    for (int i = x; i <= n; i++) {
        if (s[i][y] == 'A') ca++;
        if (s[i][y] == 'B') cb++;
        if (s[i][y] == 'C') cc++;
    }
    for (int j = y; j <= n; j++) {
        if (s[x][j] == 'A') ca++;
        if (s[x][j] == 'B') cb++;
        if (s[x][j] == 'C') cc++;
    }
    if (!ca) return 'A';
    if (!cb) return 'B';
    if (!cc) return 'C';
    return '0';
}
void fillit(int x, int y, int w, int h, char ch) {
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < y + h; j++) {
            s[i][j] = ch;
        }
    }
}
signed main() {
    freopen("chongjg.in", "r", stdin);
    freopen("chongjg.out", "w", stdout);
    // memset(s, '6', sizeof(s));
    n = read(), m = read();
    int i = 0, j = 0;
    while (i < n || j < m) {
        int a = (n - i), b = (m - j);
        if (a > b) {
            char ch = cmex(i, j);
            fillit(i + 1, j + 1, b, b, ch);
            i += b;
        } else if (a < b) {
            char ch = cmex(i, j);
            fillit(i + 1, j + 1, a, a, ch);
            j += a;
        } else {
            char ch = cmex(i, j);
            fillit(i + 1, j + 1, a, a, ch);
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            putchar(s[i][j]);
        }
        puts("");
    }
    return 0;
}