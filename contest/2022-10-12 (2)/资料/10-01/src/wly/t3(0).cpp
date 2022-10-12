#include <stdio.h>
#include <stdlib.h>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
#define module 10000000000000LL
int n;
long long c[201][101]={0}, mid[201]={0}, ans[201]={0};

void mul(long long *a, int b, long long *c){
     long long m[201]={0};
     int i;
     m[0] = max(m[0], a[0]);
     for (i=1; i<=m[0]; i++)
     {
         m[i] += a[i] * b;
         if (m[i]>module) m[i+1]+=m[i]/module, m[i]%=module;
     }
     while (m[m[0]]>module || m[m[0]+1]!=0) m[m[0]+1]+= m[m[0]]/module, m[m[0]]%=module, m[0]++;
     for (i=0; i<=m[0]; i++) c[i] = m[i];
}

void div(long long *a, int b){
     long long m[201]={0};
     int i;
     m[0] = a[0];
     for (i=a[0]; i>=1; i--){
         m[i] += a[i]/b;
         if (i!=1) a[i-1] += a[i]%b;
     }
     while (m[m[0]]==0) m[0]--;
     for (i=0; i<=m[0]; i++) a[i] = m[i];
}

void add(long long *a, long long *b){
     int i;
     b[0] = max(a[0], b[0]);
     for (i=1; i<=b[0]; i++){
         b[i] += a[i];
         if (b[i]>module) b[i+1]+=b[i]/module, b[i]%=module;
     }
     while (b[b[0]]>module || b[b[0]+1]!=0) b[b[0]+1]+=b[b[0]]/module, b[b[0]]%=module, b[0]++;
}

void D(long long *a, long long *b){
     int i;
     for (i=min(a[0], b[0]); i>=1; i--){
         b[i] -= a[i];
         if (b[i]<0) b[i+1]--, b[i]+=module;
     }
     while (b[b[0]]==0) b[0]--;
}

void print(int i){
     long long t = module/10;
     if (i!=ans[0]) while (ans[i]<t && t>1) printf("0"), t/=10;
     printf("%I64d", ans[i]);
}

int main(){
    freopen("t3.in", "r", stdin);
    freopen("t3.out", "w", stdout);
    int i, j, mark=1;;
    scanf("%d", &n);
    c[1][0] = 1;
    c[1][1] = n;
    for (i=2; i<=n; i++)
    {
        mul (c[i-1], n-i+1, c[i]);
        div (c[i], i);
    }
    for (i=2; i<=n; i++)
    {
        for (j=2; j<=n-i; j++) mul(c[i], j, c[i]);
        if (mark==1) add(c[i], ans);
        else D(c[i], ans);
      //  printf("%I64d\n", ans[0]);
        mark = -mark;
    }
    for (i=ans[0]; i>=1; i--) print(i);
    printf("\n");
    system("pause");
    return 0;
}
