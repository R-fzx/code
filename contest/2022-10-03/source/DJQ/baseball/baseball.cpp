#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)) {
        if(c == EOF) return -1;
        f |= (c == '-'), c = getchar();
    }
    while(isdigit(c)      ) x = (x * 10) + (c ^ 48), c = getchar();
    return f? x : x;
}
const int maxn = 1e6;
int n;
long double r, eps1, eps2;
int main() {
    freopen("baseball.in", "r", stdin);
    freopen("baseball.out", "w", stdout);
    while(~(n = read())) {
        cin>>r;
        eps1 = pow(10.0, -1 * (n - 1)), eps1 = eps1 * 4.0; 
        eps2 = pow(10.0, -1 * (n - 1)), eps2 = eps2 * 5.0;
        for(register int i = 2; i <= maxn; ++i) {
            long double x = r * (long double)i;
            int Cnt1 = r * i, Cnt2 = Cnt1 + 1;
//            cout << i << " " << Cnt1 << " " << Cnt2 << " " << x << "\n";
            if(Cnt1 < i && x - Cnt1 <= eps1) { printf("%lld\n", i); break; }
            if(Cnt2 < i && Cnt2 - x <= eps2) { printf("%lld\n", i); break; }
        }
    }
    return 0;
}
