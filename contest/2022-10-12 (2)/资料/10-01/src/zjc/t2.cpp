#include<stdio.h>
#include<algorithm>
using namespace std;
long long e[100],n,m,f[100],ans,k,l,r,mid;
long long mi(long long x,int y)
{
    int i;
    long long z=1;
    for(i=1;i<=y;i++)
    {
      if(m/x<z) return m+1;
      z*=x;
    }
    return z;
}
int main()
{
    freopen("t2.in","r",stdin);
    freopen("t2.out","w",stdout);
    int i,j;
    for(e[0]=i=1;i<=61;i++) e[i]=e[i-1]*2;
    //for(i=1;i<=61;i++) printf("%I64d\n",e[i]);
    while(1)
    {
      scanf("%I64d%I64d",&n,&m); if(!(m|n)) return 0;
      memset(f,0,sizeof(f)),ans=0;
      for(i=61;i;ans+=f[i]*i,i--)
      {
        if(e[i]>m) continue;
        if(e[i]>=n) k=1;
        else
        {
          for(l=1,r=e[61];l<r;)
          {
            mid=(l+r+1)>>1;
            if(mi(mid,i)>=n) r=mid-1;
            else l=mid;
          }
          k=l;
        }
        for(l=1,r=e[61];l<r;)
        {
          mid=(l+r+1)>>1;
          if(mi(mid,i)>m) r=mid-1;
          else l=mid;
        }
        for(f[i]=l-k,j=2;i*j<=61;j++) f[i]-=f[i*j];
      }
      printf("%I64d\n",ans);
    }
    return 0;
}    
