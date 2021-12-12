#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node {int x, y; double dist;} a[100005];
double dis(node a, node b) {return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}
double helen(double x, double y, double z) {
    double p = (x + y + z) / 2;
    return sqrt(p * (p - x) * (p - y) * (p - z));
}
bool check(node a, node b, node c) {
    double s = helen(dis(a, b), dis(b, c), dis(c, a));
    // cout << s << endl;
    // cout <<helen(dis(a, b), a.dist, b.dist)<< ' ' <<helen(dis(b, c), b.dist, c.dist)<< ' ' << helen(dis(c, a), c.dist, a.dist) << endl;
    double nmsl = helen(dis(a, b), a.dist, b.dist) + helen(dis(b, c), b.dist, c.dist) + helen(dis(c, a), c.dist, a.dist);
    // cout << nmsl << ' ' << s << endl;
    return fabs(s - nmsl) < 1e-6;
}   
int main() {
    // freopen("tricount.in", "r", stdin);
    // freopen("tricount.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y, a[i].dist = sqrt(a[i].x * a[i].x + a[i].y * a[i].y);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            for (int k = 1; k < j; k++)
                ans += check(a[i], a[j], a[k]);
    cout << ans << endl;
    return 0;
}