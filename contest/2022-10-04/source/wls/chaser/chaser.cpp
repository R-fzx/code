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
int n;
double xw1, yw1, xw2, yw2, vw;
double xt1, yt1, xt2, yt2, vt;
double d1, d2;
double f(double x, double k, double b) {
    return k * x + b;
}
double d(int x1, int y1, int x2, int y2) { return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); }
signed main() {
    // freopen("chaser.in", "r", stdin);
    // freopen("chaser.out", "w", stdout);
    // while (~scanf("%lf%lf%lf%lf%lf", &xw1, &yw1, &xw2, &yw2, &vw)) {
    //     scanf("%lf%lf%lf%lf%lf", &xt1, &yt1, &xt2, &yt2, &vt);
    //     scanf("%lf%lf", &d1, &d2);
    //     double kw = (yw2 - yw1) / (xw2 - xw1);
    //     double bw = yw1 - kw * xw1;
    //     bool havejd = 0;
    //     int yy1 = f(xt1, kw, bw), yy2 = f(xt2, kw, bw);
    //     if (yy1 == yt1 && yy2 == yt2) { puts("Dangerous"); continue; }
    //     if ((yy1 <= yt1 && yy2 >= yt2) || (yy1 >= yt1 && yy2 <= yt2)) havejd = 1;
    //     if (havejd) {
    //         double kt = (yt2 - yt1) / (xt2 - xt1);
    //         double bt = yt1 - kt * xt1;
    //         double jdx = (bt - bw) / (kw - kt);
    //         double jdy = f(jdx, kw, bw);
    //         double sw = d(xw1, yw1, jdx, jdy);
    //         double t = sw / vw;
    //         double lent = d(xt1, yt1, xt2, yt2), st = t * vt;
    //         double pt = st % (lent * 2); // place of t
    //         bool way = (pt >= lent);
    //         // Go Forward

    //     }
    // }
    return 0;
}