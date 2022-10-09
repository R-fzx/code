#include<bits/stdc++.h>
#define int long long
#define f(x, y, id) f[x][y + 40000][id]
using namespace std;
inline int read() {
    int x = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)) f |= (c == '-'), c = getchar();
    while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
    return f ? -x : x;
}
const int maxn = 205, maxm = 4 * 1e4 + 5, INF = 1e9 + 7;
int n;
struct node {
    int x, y;
}Point[maxn];
int f[maxn][maxm << 1][2], Sumx, Sumy, Answerx, Answery;
signed main() {
    freopen("seventeen.in", "r", stdin);
    freopen("seventeen.out", "w", stdout);
    n = read();
    for(register int i = 1; i <= n; ++i) Point[i].x = read(), Point[i].y = read(), Sumx += Point[i].x, Sumy += Point[i].y;
    for(register int i = 0; i <= n; ++i) {
        for(register int j = -Sumx; j <= Sumx; ++j) f(i, j, 0) = INF;
        for(register int j = -Sumy; j <= Sumy; ++j) f(i, j, 1) = INF;
    }
    f(0, 0, 0) = f(0, 0, 1) = 0;
    for(register int i = 1; i <= n; ++i) {
        for(register int j = -Sumx; j <= Sumx; ++j) {
            if(j - Point[i].x >= -Sumx) f(i, j, 0) = min(f(i, j, 0), f(i - 1, j - Point[i].x, 0) + Point[i].x * (j - Point[i].x));
            if(j + Point[i].x <= Sumx) f(i, j, 0) = min(f(i, j, 0), f(i - 1, j + Point[i].x, 0) - Point[i].x * (j + Point[i].x));
        } 
        for(register int j = -Sumy; j <= Sumy; ++j) {        
            if(j - Point[i].y >= -Sumy) f(i, j, 1) = min(f(i, j, 1), f(i - 1 ,j - Point[i].y, 1) + Point[i].y * (j - Point[i].y));
            if(j + Point[i].y <= Sumy) f(i, j, 1) = min(f(i, j, 1), f(i - 1, j + Point[i].y, 1) - Point[i].y * (j + Point[i].y));
        }
    }
    for(register int i = -Sumx; i <= Sumx; ++i) Answerx = min(Answerx, f(n, i, 0));
    for(register int i = -Sumy; i <= Sumy; ++i) Answery = min(Answery, f(n, i, 1)); 
    printf("%0.2lf\n", (double)(Answerx + Answery));
    return 0;
}