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
const int maxn = 2 * 1e4 + 5, maxK = 1e6 + 5, mod = 1e9 + 7;
int n, m, k;
int f[maxn], Frac[maxK], Inv[maxK], pown[maxn], powk[maxn], Answer;
inline int Ksm(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod, b >>= 1;
    }
    return res;
}
inline int C(int x, int y) { return Frac[x] * Inv[y] % mod * Inv[x - y] % mod; }
inline void Ready() {
    Frac[0] = Inv[0] = 1;
    for(register int i = 1; i <= k; ++i) Frac[i] = Frac[i - 1] * i % mod, Inv[i] = Ksm(Frac[i], mod - 2);
    pown[0] = 1, powk[0] = 1;
    for(register int i = 1; i <= n; ++i) pown[i] = Ksm(i, n), powk[i] = Ksm(i, n * (m - 2));
    for(register int i = 1; i <= n; ++i)
        for(register int j = 0; j < i; ++j) {
            f[i] = (f[i] + ((j & 1) ? -1 : 1ll) * (C(i, i - j) * pown[i - j] % mod) + mod) % mod;
//            printf("%lld\n", C(i, i - j));
        }
//    for(register int i = 1; i <= n; ++i) printf("%lld ", f[i]);
//    printf("\n");
}
signed main() {
    freopen("painting.in", "r", stdin);
    freopen("painting.out", "w", stdout);
    n = read(), m = read(), k = read();
    Ready();
    for(register int i = 1; i <= n; ++i)
        for(register int j = (m == 2 ? 0 : 1); j <= i; ++j)
            Answer = (Answer + C(k, j) * C(k - j, i - j) % mod * C(k - i, i - j) % mod * f[i] % mod * f[i] % mod * powk[j] % mod) % mod;
    printf("%lld\n", Answer);
    return 0;   
}