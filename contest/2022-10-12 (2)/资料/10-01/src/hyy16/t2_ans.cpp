#include <stdio.h>
#include <stdlib.h>
#define max 1000000

long long a,b,i,ans,f[max+1];

void init();

int main()
{
    freopen("t2.in","r",stdin); freopen("t2_ans.out","w",stdout);
    init();
    scanf("%I64d %I64d",&a,&b);
    while (a!=0 || b!=0)
    {
          ans=0;
          for(i=a;i<=b;i++) ans+=f[i];
          printf("%I64d\n",ans);
          scanf("%I64d %I64d",&a,&b); 
    }
    return 0;
}

void init()
{
     long long i,j,k;
     for(i=2;i<=max;i++)
     {
        for(j=i,k=1;j<=max;k++,j*=i)
        {
           if (k>f[j]) f[j]=k;
           if (k<f[j]) printf("%d\n",j);
        }
     }
     return;
}
