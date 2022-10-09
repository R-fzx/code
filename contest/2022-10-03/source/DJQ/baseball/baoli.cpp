#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)) f |= (c == '-'), c = getchar();
    while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
    return f? x : x;
}
int main() {
    freopen("baseball.out", "w", stdout);
    for(register int i = 1; i <= 1000; ++i)
        for(register int j = 1; j <= i; ++j) {
            double x = (double) j / i;
            printf("j = %d i = %d : %0.14lf %0.14lf\n", j, i, (double)j / i, x * (double)i);
        }
    return 0;
}
