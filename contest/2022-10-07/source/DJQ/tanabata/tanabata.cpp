#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
    int x = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)) f |= (c == '-'), c = getchar();
    while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
    return f ? -x : x;
}
const int maxn = 1e5 + 5;
int n, m, T;
int X[maxn], Y[maxn], a[maxn], c[maxn], Answer;
inline void Work(int Id) {
    int Avg = 0, Sum = 0, x1 = 0;
    for(register int i = 1; i <= n; ++i) a[i] = (!Id ? X[i] : Y[i]), Avg += a[i];
    Avg /= n;
    c[1] = 0, Sum = Avg - a[1];
    for(register int i = 2; i <= n; ++i) c[i] = Sum, Sum += Avg - a[i];
    sort(c + 1, c + n + 1);
    x1 = c[(n + 1) >> 1];
    for(register int i = 1; i <= n; ++i) Answer += abs(x1 - c[i]);
}
signed main() {
    freopen("tanabata.in", "r", stdin);
    freopen("tanabata.out", "w", stdout);
    n = read(), m = read(), T = read();
    for(register int i = 1; i <= T; ++i) X[read()]++, Y[read()]++;
    if(T % n != 0 && T % m != 0) { printf("impossible\n"); return 0; }
    else if(T % n != 0) printf("column "), Work(1);
    else if(T % m != 0) printf("row "), Work(0);
    else printf("both "), Work(0), Work(1);
    printf("%lld\n", Answer);
    return 0;
}