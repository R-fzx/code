#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long f[105]={0};

long long check(int i, long long p){
     long long l=1, r=p, mid, x;
     int ii;
     while (l<r){
           mid = (l+r+1)/2;
           x = p;
           for (ii=1; ii<=i; ii++) x/=mid;
           if (x>=1) l = mid;
           else r = mid-1;
     }
     return l;
}

long long work(long long c){
     int i, j;
     long long ans=0;
     memset(f, 0, sizeof(f));
     for (i=61; i>=1; i--){
         f[i] = check(i, c);
         for (j=2; j*i<=61; j++) f[i] -= f[i*j];
         ans += i * f[i];
     }
     return ans;
}

int main(){
	freopen("t2.in","r",stdin);
	freopen("t2.out","w",stdout);
    int i, n, j, k;
    long long a, b;
    scanf("%I64d%I64d", &a, &b);
    while (a!=0){
          printf("%I64d\n", work(b)-work(a-1));
          scanf("%I64d%I64d", &a, &b);
    }
    system("pause");
    return 0;
}
