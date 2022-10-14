#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)) f |= (c == '-'), c = getchar();
    while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
    return f ? -x : x;
}
const int maxn = 2 * 1e5 + 5;
int n, len;
struct node {
    double x, y;
}Point[maxn], Cnt[maxn];
inline bool cmp1(node A, node B) { return A.x < B.x; }
inline bool cmp2(node A, node B) { return A.y < B.y; }
inline double operator * (node A, node B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
inline double Calc(int l, int r) {
    if(r - l + 1 == 2) return Point[l] * Point[r];
    if(r - l + 1 == 3) return min(Point[l] * Point[l + 1], Point[r - 1] * Point[r]);
    int mid = (l + r) >> 1; double Dis = min(Calc(l, mid), Calc(mid + 1, r)); len = 0;
    for(register int i = l; i <= r; ++i)
        if(fabs(Point[i].x - Point[mid].x) < Dis) Cnt[++len] = Point[i];
    stable_sort(Cnt + 1, Cnt + len + 1, cmp2);
    for(register int i = 1; i <= len; ++i)
        for(register int j = i + 1; j < i + 3 && j <= len; ++j)
            Dis = min(Dis, Cnt[i] * Cnt[j]);
    return Dis;
}
int main() {
    freopen("dark.in", "r", stdin);
    freopen("dark.out", "w", stdout);
    n = read();
    for(register int i = 1; i <= n; ++i) scanf("%lf%lf", &Point[i].x, &Point[i].y);
    stable_sort(Point + 1, Point + n + 1, cmp1);
    printf("%0.3lf\n", Calc(1, n) / (double)2.0);
    return 0;
}
