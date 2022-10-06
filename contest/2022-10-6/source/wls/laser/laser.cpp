#include <bits/stdc++.h>
#define println(x) print(x), putchar('\n')
#define printsp(x) print(x), putchar(' ')
#define printpa(x, y) printsp(x), println(y)
using namespace std;
const int N = 1e4 + 10;
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
int n, K;
int a[N], b[N];
bool check(int num) {
    for (int i = 1; i <= n; i++) if (a[i] <= num && num <= b[i]) return 1;
    return 0;
}
int getbits(int num) {
    int cnt = 0;
    while (num) ++cnt, num /= 10;
    return cnt;
}
set<pair<int, int> > dd;

signed main() {
    freopen("laser.in", "r", stdin);
    freopen("laser.out", "w", stdout);
    n = read(), K = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read(), b[i] = read();
    }

    if (K == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < a[i] % 10; j++) {
                for (int j2 = a[i] % 10; j2 < 10; j2++) dd.insert(make_pair(j, j2));
            }
            for (int j = 1; j <= b[i] % 10; j++) {
                for (int j2 = b[i] % 10 + 1; j2 < 10; j2++) dd.insert(make_pair(j, j2));
            }
        }
        for (int i = 1; i <= 9; i++) {
            print(i);
            if (dd.count(make_pair(i, i + 1)) || dd.count(make_pair(i + 1, i))) puts("");
        }
        puts("");
    } else if (n <= 50) {
        for (int i = 1; i <= n; i++) {
            for (int j = a[i]; j <= b[i]; j++) {
                int num = j;
                for (int k = 0; k <= min(getbits(j) - 1, K - 1); k++) {
                    num = j;
                    int pow10k = pow(10, k);
                    int p = (int)(num / pow10k) % 10;
                    if (!p) continue;
                    for (int q = 1; q <= 9; q++) {
                        num = j;
                        if (p == q) continue;
                        if (dd.count(make_pair(p, q))) continue;
                        // println(num);
                        num = num - p * pow10k + q * pow10k;
                        // printpa(p, q);
                        // println(num);
                        if (!check(num)) dd.insert(make_pair(p, q));
                    }
                }
            }
        }
        for (int i = 1; i <= 9; i++) {
            print(i);
            if (dd.count(make_pair(i, i + 1)) || dd.count(make_pair(i + 1, i))) puts("");
        }
        puts("");
    }
    return 0;
}