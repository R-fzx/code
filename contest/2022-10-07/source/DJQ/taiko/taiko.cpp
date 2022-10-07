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
const int maxn = (1 << 11) + 5;
int K, n;
struct node {
    int v, nex;
}edge[maxn << 1];
int head[maxn], len, Vst[maxn], Stack[maxn], top;
inline void make_map(int u, int v) {
    len++;
    edge[len].nex = head[u];
    edge[len].v = v;
    head[u] = len;
}
inline void Search(int x) {
    Vst[x] = 1;
    for(register int i = head[x]; i; i = edge[i].nex) {
        int y = edge[i].v;
        if(Vst[y]) continue;
        Search(y);
    }
    Stack[++top] = x;
}
signed main() {
    freopen("taiko.in", "r", stdin);
    freopen("taiko.out", "w", stdout);
    K = read(), n = (1 << K);
    printf("%lld ", n);
    for(register int i = 0; i < n; ++i) {
        int u = i, v = (i % (n >> 1)) << 1 | 1;
        make_map(u, v);
        v = (i % (n >> 1)) << 1;
        make_map(u, v);
    }
    Search(0);
    for(register int i = top; i >= 1; --i) printf("%d", Stack[i] / (n >> 1));
    return 0;
}