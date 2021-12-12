#include<bits/stdc++.h>
#define x1 WYPnmsl
#define y1 wypNMSL
#define x2 WYPNMSL
#define y2 wypnmsl
// #define min(x, y) (x < y ? x : y)
// #define max(x, y) (x > y ? x : y)
#define cnmd(a, x, y) (min(a.x1, a.x2) <= x && x <= max(a.x1, a.x2) && min(a.y1, a.y2) <= y && y <= max(a.y1, a.y2))
using namespace std; 
int n;
struct node {int x1, y1, x2, y2;} a[100005];
// inline bool cnmd(node a, double x, double y) {return min(a.x1, a.x2) <= x && x <= max(a.x1, a.x2) && min(a.y1, a.y2) <= y && y <= max(a.y1, a.y2);}
inline bool check(node a, node b) {
    if (b.x1 == b.x2) swap(a, b);
    if (a.x1 == a.x2) {
        if (b.x1 == b.x2) return 0;
        double k = (b.y1 - b.y2) / (b.x1 - b.x2);
        double l = b.y1 - b.x1 * k;
        double nmsl = a.x1 * k + l;
        if (min(a.y1, a.y2) <= nmsl && nmsl <= max(a.y1, a.y2)) return 1;
        return 0;
    }
    double k1 = (a.y1 - a.y2) / (a.x1 - a.x2), k2 = (b.y1 - b.y2) / (b.x1 - b.x2);
    if (k1 == k2) return 0;
    double l1 = a.y1 - a.x1 * k1, l2 = b.y1 - b.x1 * k2;
    double x = (l2 - l1) / (k1 - k2);
    double y = x * k1 + l1;
    if (cnmd(a, x, y) && cnmd(b, x, y)) return 1;
    return 0;
}
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while (isdigit(c)) {x = (x << 3) + (x << 1) + (c ^ 48); c = getchar();}
    return x * f;
}
int main() {
    freopen("cowjump.in", "r", stdin);
    freopen("cowjump.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++) {a[i].x1 = read(); a[i].y1 = read(); a[i].x2 = read(); a[i].y2 = read();}
    int num1 = 0, num2 = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++) {
            if (!check(a[i], a[j])) continue;
            if (num1 == 0 && num2 == 0) num1 = j, num2 = i;
            else if (num1 == j || num1 == i) {printf("%d\n", num1); return 0;}
            else if (num2 == j || num2 == i) {printf("%d\n", num2); return 0;}
        }
    cout << num1 << endl;
    return 0;
}