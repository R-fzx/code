#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define  min(a,b) a<b?a:b
//分别以a/b/c为关键字、a+b+c为第二关键字sort，选前面各100个DP   在前一百个而不选是因为它被选成b/c会更优。所以不会漏。 
using namespace std;
struct name{ long long a, b, c, sum, num; };
struct name p1[500005]={0,0,0}, p[350]={0,0,0};

long long f[305][305][305]={0}, g[305][305][305]={0};
int  hash[500005]={0};

bool cmp1(struct name aa, struct name bb){
     return aa.a>bb.a || (aa.a==bb.a && aa.sum>bb.sum);
}

bool cmp2(struct name aa, struct name bb){
     return aa.b>bb.b || (aa.b==bb.b && aa.sum>bb.sum);
}

bool cmp3(struct name aa, struct name bb){
     return aa.c>bb.c || (aa.c==bb.c && aa.sum>bb.sum);
}

int main(){
    
    freopen ("ゆりっぺ.in", "r", stdin);
    freopen ("ゆりっぺ.out", "w", stdout);
    
    long long i, n, a, b, c, d, sum, x, xa, xb, xc, nn;
    
    scanf ("%I64d%I64d%I64d%I64d", &n, &a, &b, &c);
    if (a+b+c>n) {  printf("I am a godlike cowcowcow\n");  return 0;  }
    
    for (i=1; i<=n; i++){
        scanf ("%I64d%I64d%I64d", &p1[i].a, &p1[i].b, &p1[i].c);
        p1[i].sum = p1[i].a + p1[i].b + p1[i].c;
        p1[i].num = i;
    }
    
    x = min(100, a+b+c);
    
	partial_sort(p1 + 1, p1 + 1 + x, p1 + 1 + n, cmp1);
    nn = 0;
    for (i=1; i<=x; i++){
        p[++nn] = p1[i];
        hash[p1[i].num] = 1;
        //printf("%I64d\n", p1[i].num);
    }
    
	partial_sort(p1 + 1, p1 + 1 + x, p1 + 1 + n, cmp2);
    for (i=1; i<=x; i++)
    if (hash[p1[i].num]==0){
        p[++nn] = p1[i];
        hash[p1[i].num] = 1;
        //printf("%I64d\n", p1[i].num);
    }
    
	partial_sort(p1 + 1, p1 + 1 + x, p1 + 1 + n, cmp3);
    for (i=1; i<=x; i++)
    if (hash[p1[i].num]==0){
        p[++nn] = p1[i];
        hash[p1[i].num] = 1;
        //printf("%I64d\n", p1[i].num);
    }
    
    n = nn;
    for (i=1; i<=n; i++){
        for (xa=min(i-1,a); xa>=0; xa--){
            for (xb=min(i-1-xa,b); xb>=0; xb--){
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
                             flag = 1;
                       }
                    //if (flag==0) xa=-1, xb=-1, xc=-1;
                }
            }
        }
    }
    printf("%I64d\n%I64d\n", f[a][b][c], g[a][b][c]);
    //system("pause");
    return 0;
} 
