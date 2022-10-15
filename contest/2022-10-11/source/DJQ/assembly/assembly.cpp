#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)) f |= (c == '-'), c = getchar();
    while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
    return f ? -x : x;
}
const int maxn = 15;
int n, k, A;
struct node {
    int B, L;
}People[maxn];
int Present[maxn], a[maxn], Sum, tot;
double P, Answer,  Total; 
inline void Calc() {
    P = 1, tot = 0, Sum = 0;
    for(register int i = 1; i <= n; ++i)
        if(a[i]) P *= (double)(People[i].L + Present[i] * 10) / 100.0, tot++;
        else P *= (double)(100 - People[i].L - Present[i] * 10) / 100.0, Sum += People[i].B;
    if(tot > (n / 2)) { Total += P; return ; }
    else Total += P * (double)A / (double)(A + Sum);
    return ;
}
inline void Choose(int len) {
    if(len == n + 1) { Calc(); return ; }
    a[len] = 1, Choose(len + 1);
    a[len] = 0, Choose(len + 1);
}
inline void Search(int len, int x) {
    if(len == n + 1) {  
        Total = 0, Choose(1), Answer = max(Answer, Total);
        return ;
    }
    for(register int i = min((100 - People[len].L) / 10, x); i >= 0; --i) {
        Present[len] = i, x -= i;
        Search(len + 1, x);
        Present[len] = 0, x += i;
    }
}
int main() {
    freopen("assembly.in", "r", stdin);
    freopen("assembly.out", "w", stdout);
    n = read(), k = read(), A = read();
    for(register int i = 1; i <= n; ++i) People[i].B = read(), People[i].L = read();
    Search(1, k);
    printf("%0.6lf\n", Answer);
    return 0;
}