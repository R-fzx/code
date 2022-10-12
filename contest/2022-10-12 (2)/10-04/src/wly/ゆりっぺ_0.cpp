#include <stdio.h>
#include <stdlib.h>
#define min(a,b) a<b?a:b
struct name{ long long a, b, c, sum; } p[500005]={0,0,0};
long long f[305][305][305]={0}, g[305][305][305]={0};
int main(){
    long long n, a, b, c, xa, xb, xc, i;
    scanf ("%I64d%I64d%I64d%I64d", &n, &a, &b, &c);
    for (i=1; i<=n; i++){
        scanf ("%I64d%I64d%I64d", &p[i].a, &p[i].b, &p[i].c);
        p[i].sum = p[i].a + p[i].b + p[i].c;
        //sum += p[i].s;
        for (xa=min(i-1,a); xa>=0; xa--){
            //if (xa>a) continue;
            for (xb=min(i-1-xa,b); xb>=0; xb--){
                //if (xb>b)  continue;
                for (xc=min(i-1-xa-xb,c); xc>=0; xc--){
                    //printf("%I64d %I64d %I64d %I64d\n", i, xa, xb, xc);
                    int flag = 0;
                    if (f[xa][xb][xc]+p[i].a>f[xa+1][xb][xc]
                       || (f[xa][xb][xc]+p[i].a==f[xa+1][xb][xc]
                          && g[xa][xb][xc]+p[i].sum>g[xa+1][xb][xc]) 
                       ){
                             f[xa+1][xb][xc] = f[xa][xb][xc]+p[i].a;
                             g[xa+1][xb][xc] = g[xa][xb][xc]+p[i].sum;
                             flag = 1;
                       }
                    if (f[xa][xb][xc]+p[i].b>f[xa][xb+1][xc]
                       || (f[xa][xb][xc]+p[i].b==f[xa][xb+1][xc]
                          && g[xa][xb][xc]+p[i].sum>g[xa][xb+1][xc]) 
                       ){
                             f[xa][xb+1][xc] = f[xa][xb][xc]+p[i].b;
                             g[xa][xb+1][xc] = g[xa][xb][xc]+p[i].sum;
                             flag = 1;
                       }
                    if (f[xa][xb][xc]+p[i].c>f[xa][xb][xc+1]
                       || (f[xa][xb][xc]+p[i].c==f[xa][xb][xc+1]
                          && g[xa][xb][xc]+p[i].sum>g[xa][xb][xc+1]) 
                       ){
                             f[xa][xb][xc+1] = f[xa][xb][xc]+p[i].c;
                             g[xa][xb][xc+1] = g[xa][xb][xc]+p[i].sum;
                             flag=1;
                       }
                    if (flag==0) xa=-1, xb=-1, xc=-1;
                }
            }
        }
    }
    printf("%I64d\n%I64d\n", f[a][b][c], g[a][b][c]);
    system("pause");
    return 0;
} 
