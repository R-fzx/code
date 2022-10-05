#include <bits/stdc++.h>
#define int long long
#define println(x) print(x), putchar('\n')
#define printsp(x) print(x), putchar(' ')
#define printpa(x, y) printsp(x), println(y)
using namespace std;
const int N = 1e5 + 10;
const double eps = 1e-5;
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
struct point {
    double x, y;
    point(double x, double y):x(x), y(y) {}
};
struct line {
    double k, b;
    double operator () (double x) { return k * x + b; }
    line(double k, double b):k(k), b(b) {}
};
struct pline {
    point a, b;
    pline(point a, point b):a(a), b(b) {}
    pline(double x1, double y1, double x2, double y2):a(x1, y1), b(x2, y2) {}
};
int n;
double x[N], y[N];
void input() {
    n = read();
    int a = read(), b = read(), c = read(), d = read(), x0 = read(), y0 = read(), m = read();
    int xx = x0, yy = y0;
    x[1] = (double)(x0), y[1] = (double)(y0);
    for (int i = 2; i <= n; i++) {
        xx = (a * xx + b) % m;
        yy = (c * yy + d) % m;
        x[i] = (double)(xx), y[i] = (double)(yy);
    }
}
line p2line(point a, point b) { // a---b
    double k = (b.y - a.y) / (b.x - a.x);
    double b_ = a.y - a.x * k;
    return line(k, b_);
}
point midpoint(pline l) {
    return point((l.a.x + l.b.x) / 2.0, (l.a.y + l.b.y) / 2.0);
}
point jd(line a, line b) {
    return point((b.b - a.b) / (a.k - b.k), a((b.b - a.b) / (a.k - b.k)));
}
signed main() {
    freopen("crop.in", "r", stdin);
    freopen("crop.out", "w", stdout);
    // printf("%lf %lf\n", p2line(point(1, 2), point(4, -4)).k, p2line(point(1, 2), point(4, -4)).b);
    input();
    // for (int i = 1; i <= n; i++) printf("%lf %lf\n", x[i], y[i]);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                pline pl1(x[i], y[i], x[j], y[j]);
                pline pl2(x[j], y[j], x[k], y[k]);
                point p1 = midpoint(pl1), p2 = midpoint(pl2);
                // printf("%lf %lf\n", p2.x, p2.y);
                line l1 = p2line(p1, point(x[k], y[k]));
                line l2 = p2line(p2, point(x[i], y[i]));
                point q = jd(l1, l2);
                // printf("%d %d %d\n", i, j, k);
                // printf("l1: %lf %lf\n", l1.k, l1.b);
                // printf("l2: %lf %lf\n", l2.k, l2.b);
                // printf("%lf %lf\n", q.x, q.y);
                double xx = (int)(q.x + 0.5), yy = (int)(q.y + 0.5);
                if (fabs(xx - q.x) <= eps && fabs(yy - q.y) <= eps) cnt++;
            }
        }
    }
    println(cnt);
    return 0;
}