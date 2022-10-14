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
int n, minn, Answer;
signed main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    n = read();
    for(register int i = 1; i <= n; ++i) {
        int x = read();
        if(i == 1) { minn = x, Answer = x * n; continue; }
        if(x < minn) Answer = Answer - minn * (n - i + 1) + x * (n - i + 1), minn = x;
    }
    printf("%lld\n", Answer);
    return 0;
}