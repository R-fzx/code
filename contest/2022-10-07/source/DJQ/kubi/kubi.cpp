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
const int maxn = 1e5 + 5, INF = 1e9 + 7;
int T, A, B, K;
int Cnt[maxn], num[maxn];
signed main() {
    freopen("kubi.in", "r", stdin);
    freopen("kubi.out", "w", stdout);
    T = read();
    while(T--) {
        A = read(), B = read(), K = read();
        fill(num, num + B + 1, -1);
        Cnt[0] = A % B, num[A % B] = 0;
        if(Cnt[0] == 0) { printf("0 0\n"); continue; }
        for(register int i = 1; i <= B + 1; ++i) {
            Cnt[i] = Cnt[i - 1] * K % B;
            if(Cnt[i] == 0) { printf("%d 0\n", i, 0); break; }
            if(~num[Cnt[i]]) { printf("%d %d\n", num[Cnt[i]], i - num[Cnt[i]]); break; }
            num[Cnt[i]] = i;
        }

    }
    return 0;
}