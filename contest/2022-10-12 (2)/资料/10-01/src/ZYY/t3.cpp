#include <stdio.h>
#include <stdlib.h>

long long c[201][201],p[201];
long long f[201];
int n,i,j,k;

void yh(int num)
{
     int i,j;
     c[1][0]=c[1][1]=p[1]=1;
     for (i=2; i<=num; i++)
     {
         c[i][0]=c[i][i]=1;
         p[i]=p[i-1]*i;
         for (j=1; j<i; j++)
             c[i][j]=c[i-1][j-1]+c[i-1][j];
     }
}

int main()
{
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    
    scanf("%d",&n);
    yh(n);
    f[2]=1;
    f[3]=2;
    if (n<=3)
       printf("%I64d\n",f[n]);
    else
    {
        for (i=4; i<=n; i++)
        {
            f[i]=p[i-1];
            for (j=2; j<i-i/2; j++)
                f[i]+=c[i][j]*f[j]*f[i-j];
            
            if (i%2==0)
               f[i]+=c[i][i/2]*f[i/2]*f[i/2]/2;
        }
        printf("%I64d\n",f[n]);
    }
    
    return 0;
}
