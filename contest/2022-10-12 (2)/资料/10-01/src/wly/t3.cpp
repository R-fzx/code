#include <stdio.h>
#include <stdlib.h>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
#define module 10000000000000LL

long long ans[201]={0}, ans0[201]={0}, ans1[201]={0};

void add(long long *a, long long *b){
     int i;
     b[0] = max(a[0], b[0]);
     for (i=1; i<=b[0]; i++){
         b[i] += a[i];
         if (b[i]>module) b[i+1]+=b[i]/module, b[i]%=module;
     }
     while (b[b[0]]>module || b[b[0]+1]!=0) b[b[0]+1]+=b[b[0]]/module, b[b[0]]%=module, b[0]++;
}

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

void print(int i){
     long long t = module/10;
     if (i!=ans[0]) while (ans[i]<t && t>1) printf("0"), t/=10;
     printf("%I64d", ans[i]);
}

int main(){
    freopen("t3.in", "r", stdin);
    freopen("t3.out", "w", stdout);
    int i, j, n;
    scanf("%d", &n);
    
    ans0[0] = 1;
    ans0[1] = 1;
    ans1[0] = 1;
    ans1[1] = 2;
    
    if (n==2) {printf("1\n"); return 0;  }
    if (n==3) {printf("2\n"); return 0;  }
    
    for (i=4; i<=n; i++){
        add(ans1, ans0);
        mul(ans0, i-1, ans);
        for (j=0; j<=ans1[0]; j++) ans0[j] = ans1[j];
        for (j=0; j<=ans[0];  j++) ans1[j] = ans[j];
    }
    
    for (i=ans[0]; i>=1; i--) print(i);
    printf("\n");
    system("pause");
    return 0;
}
