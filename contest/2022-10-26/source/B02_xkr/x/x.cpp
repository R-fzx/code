#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n;
struct node {
    int x, y;
    bool operator < (const node &a) const {return x - y > a.x - a.y;}
} a[maxn];
int x[maxn];
int ans;
vector<int> d[maxn];
int in[maxn];
int f[maxn];
queue<int> q;
bool p = 1;
void topo() {
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) q.push(i), f[i] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < d[u].size(); i++) {
            int v = d[u][i];
            f[v] = max(f[v], f[u] + 1);
            if (--in[v] == 0) q.push(v);
        }
    }
}
namespace io {
    const int SIZE = (1 << 21) + 1;
    char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
    // getchar
    #define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
    // print the remaining part
    inline void flush () {
        fwrite (obuf, 1, oS - obuf, stdout);
        oS = obuf;
    }
    // putchar
    inline void putc (char x) {
        *oS ++ = x;
        if (oS == oT) flush ();
    }
    // input a signed integer
    template <class I>
    inline void gi (I &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
        for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
    }
    // print a signed integer
    template <class I>
    inline void print (I x) {
        if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
        while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
        while (qr) putc (qu[qr --]);
    }
    //no need to call flush at the end manually!
    struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
void Sub2() {
    for (int i = 1; i <= n; i++) x[i] = a[i].x;
    sort(x + 1, x + 1 + n);
    int len = unique(x + 1, x + 1 + n) - x - 1;
    print(len);
}
int main() {
    freopen("x.in", "r", stdin);
    freopen("x.out", "w", stdout);
    gi(n);
    for (int i = 1; i <= n; i++) {
        gi(a[i].x); gi(a[i].y);
        if (a[i].y != 0) p = 0;
    }
    if (p) {Sub2(); return 0;}
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= min(i + 2000, n); j++)
            if (a[i].x - a[i].y > a[j].x + a[j].y) d[i].push_back(j), in[j]++;
    topo();
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    print(ans);
    return 0;
}
//我完全可以卡你
//冲击失败
//你会不会写快读那两行什么p1p2buf之类的东西
//今天期望[140,170]