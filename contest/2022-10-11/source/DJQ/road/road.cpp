#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
    int x = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)) f |= (c == '-'), c = getchar();
    while(isdigit(c)) x= (x * 10) + (c ^ 48), c = getchar();
    return f ? -x : x;
}
const int maxn = 5 * 1e4 + 5;
int n, m, P, Q;
struct node {
    int u, v, w1, w2;
}Line[maxn];
int len, maxx, Father[maxn];
vector <int> VecA, VecB;
bool Vst[maxn];
inline bool cmp(int x, int y) { return x > y; }
inline void make_map(int u, int v, int w1, int w2) {
    len++;
    Line[len].u = u;
    Line[len].v = v;
    Line[len].w1 = w1;
    Line[len].w2 = w2;
}
inline int Find(int x) {
    if(Father[x] != x) return Father[x] = Find(Father[x]);
    return Father[x];
}
inline void Unnion(int u, int v) {
    Father[Find(v)] = Find(u);
}
inline bool Check(int A, int B) {
    for(register int i = 1; i <= n; ++i) Father[i] = i;
    for(register int i = 1; i <= m; ++i)
        if(Line[i].w1 >= A && Line[i].w2 >= B) Unnion(Line[i].u, Line[i].v);
    int flag = 1, now = Father[1];
    for(register int i = 2; i <= n; ++i)
        if(Find(i) != now) flag = 0;
    return flag;
}
inline void Work() {
    int nowB = n, Answer = 1e18;
    for(register int nowA = 0; nowA < n; ++nowA) {
        int x = nowB - 1;
        while(x && Check(VecA[nowA], VecB[x])) x--;
        nowB = x + 1;
        if(nowB < n) Answer = min(Answer, VecA[nowA] * P + VecB[nowB] * Q);
    }
    if(Answer == 1e18) { printf("-1\n"); return ; }
    else printf("%lld\n", Answer);
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), P = read(), Q = read();
    for(register int i = 1; i <= m; ++i) {
        int u = read(), v = read(), a = read(), b = read();
        make_map(u, v, a, b), maxx = max(maxx, a);
        VecA.push_back(a), VecB.push_back(b);
    }
    sort(VecA.begin(), VecA.end()), sort(VecB.begin(), VecB.end(), cmp);
    Work();
    return 0;
}