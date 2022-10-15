#include <stdio.h>
#include <stdlib.h>
#define  min(a, b) a<b?a:b
#define  max(a, b) a>b?a:b

int n, k, a;
int l[10]={0}, b[10]={0}, lim;
double ans=0.0, mid=0.0;

void cal(){
     int    x, i, j, tot=0, nob = 0;
     double rate;
     mid = 0.0;
     for (i=0; i<=lim; i++){
         x = i;
         rate = 1.0;
         tot = 0;  nob = 0;
         for (j=1; j<=n; j++){
             if (x & 1){
                   rate *= l[j] * 0.01;
                   tot++;
             }
             else{
                  rate *= (1 - l[j]*0.01);
                  nob += b[j];
             }
             x >>= 1;
         }
         if (tot > n/2) mid += rate;
         else mid += rate * (a*1.0/(nob+a));
     }
     ans = max(mid, ans);
}

void dfs(int d, int m){
     int x, i;
     x = min (m, (100-l[d])/10);
     if (d==n){
         l[d] += x * 10;
         cal();
         l[d] -= x * 10;
         return;
     }
     for (i=0; i<=x; i++){
         l[d] += i * 10;
         dfs(d+1, m-i);
         l[d] -= i * 10;
     }
}

int main(){
    int i;
    freopen ("assembly.in", "r", stdin);
    freopen ("assembly.out", "w", stdout);
    scanf ("%d%d%d", &n, &k, &a);
    lim = (1<<n) - 1;
    for (i=1; i<=n; i++) scanf ("%d%d", &b[i], &l[i]);
    dfs(1, k);
    printf ("%.6lf\n", ans);
    system("pause");
    return 0;
}
