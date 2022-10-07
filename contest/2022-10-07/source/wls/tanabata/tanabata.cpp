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
int n, m, t;
int x[N], y[N];
struct Cnt {
    int i, cnt;
} cntx[N], cnty[N];
bool cmp(Cnt a, Cnt b) { return (a.cnt < b.cnt) || ((a.cnt == b.cnt) && (a.i > b.i)); }
signed main() {
    freopen("tanabata.in", "r", stdin);
    freopen("tanabata.out", "w", stdout);
    n = read(), m = read(), t = read();
    for (int i = 1; i <= n; i++) cntx[i].i = i;
    for (int i = 1; i <= m; i++) cnty[i].i = i;
    for (int i = 1; i <= t; i++) x[i] = read(), y[i] = read(), cntx[x[i]].cnt++, cnty[y[i]].cnt++;
    sort(cntx + 1, cntx + n + 1, cmp);
    sort(cnty + 1, cnty + m + 1, cmp);
    bool xflag = 0, yflag = 0;
    int lans = 0, rans = 0;
    if (t % n == 0) {
        xflag = 1;
        int nn = t / n;
        int l = 1, r = n;
        for (l = 1; cntx[l].cnt < nn; l++) {
            while (cntx[l].cnt < nn) {
                int d = min(nn - cntx[l].cnt, cntx[r].cnt - nn);
                cntx[l].cnt += d, cntx[r].cnt -= d;
                lans += d;
                if (cntx[r].cnt <= nn) --r;
            }
        }
    }
    if (t % m == 0) {
        yflag = 1;
        int mm = t / m;
        int l = 1, r = m;
        for (l = 1; cnty[l].cnt < mm; l++) {
            while (cnty[l].cnt < mm) {
                int d = min(mm - cnty[l].cnt, cnty[r].cnt - mm);
                cnty[l].cnt += d, cnty[r].cnt -= d;
                rans += d;
                if (cnty[r].cnt <= mm) --r;
            }
        }
    }
    if (xflag && yflag) printf("both %d\n", lans + rans);
    else if (xflag) printf("row %d\n", lans);
    else if (yflag) printf("column %d\n", rans);
    else puts("impossible");
    return 0;
}