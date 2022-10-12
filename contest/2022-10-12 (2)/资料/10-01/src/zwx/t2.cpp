#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
long long e[220],f[200],ans,k,h,t,mid,i,j,a,b;
long long half(long long x,int y)
{
    int ii;
    long long z=1;
    for(ii=1;ii<=y;ii++)
    {
      if(b/x<z) return b+1;
      z*=x;
    }
    return z;
}
int main()
{
    freopen("t2.in","r",stdin);
    freopen("t2.out","w",stdout);
    e[0]=1;
    for(i=1;i<=61;i++) 
      e[i]=e[i-1]*2;
    while (1)
    {
        scanf("%I64d%I64d",&a,&b);
        if (!(a|b))
          return 0;
        for (i=1;i<=62;i++)
          f[i]=0;
        ans=0;
        for(i=61;i>0;ans=ans+f[i]*i,i--)
        {
            if(e[i]>b) 
              continue;
            if(e[i]>=a) 
             k=1;
            else
            {
                h=1;
                t=e[61];
                while (h<t)
                {
                    mid=(h+t+1)>>1;
                    if (half(mid,i)>=a)
                      t=mid-1;
                    else 
                      h=mid;
                }
                k=h;
            }
            h=1; t=e[61];
            while (h<t)
            {
                  mid=(h+t+1)>>1;
                  if (half(mid,i)>b)
                     t=mid-1;
                  else 
                     h=mid;
            }
        j=2;
        //printf("%I64d %I64d %I64d\n",i,h,k);
        f[i]=h-k;
        while (i*j<=61)
        {
            f[i]=f[i]-f[i*j];
            j++;
        }
    }
    printf("%I64d\n",ans);         
    }
    return 0;
}
