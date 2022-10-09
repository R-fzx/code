#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)) f |= (c == '-'), c = getchar();
    while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
    return f ? -x:  x;
}
const int maxn = 1e6 + 5;
int L, R;
int Answer;
int main() {
    freopen("sillyz.in", "r", stdin);
    freopen("sillyz.out", "w", stdout);
    L = read(), R = read();
    for(register int i = 1; i <= R; ++i) {
        int x = i, Cnt = i, flag = 1;
        while(x) {
            Cnt *= (x % 10);
            if(Cnt > R) { flag = 0; break; }
            x /= 10;
        }
        if(flag && Cnt >= L) Answer++;
    }
    printf("%d\n", Answer);
    return 0;
}