#include<stdio.h>
#include<iostream>
#define mod 1000000007
using namespace std;
long long c[2005][2005],f[2005][2005],ni[1000005],b[10000],s,t,n,m,k,ans;
long long sumi(long long x,long long y) { long long z=1; for(;y;y>>=1) { if(y&1) z=z*x%mod; x=x*x%mod; } return z; }
int main()
{
    freopen("painting.in","r",stdin);
    freopen("painting.out","w",stdout);
    long long i,j;
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    for(i=1;i<=n;i++) ni[i]=sumi(i,mod-2);
    for(c[0][0]=1,i=1;i<=n;i++)
      for(c[i][0]=1,j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    for(i=1;i<=n;i++) f[i][1]=1;
    for(i=2;i<=n;i++)
      for(j=1;j<=n;j++) f[i][j]=(f[i-1][j-1]+f[i-1][j])*j%mod;
    for(s=1,i=1;(i<=k)&&(i<=n);i++)//一共 
    {
      s=s*(k+1-i)%mod*ni[i]%mod;
      for(b[0]=j=1;j<=i;j++) b[j]=b[j-1]*(k-i+1-j)%mod*ni[j]%mod;
      for(t=1,j=max(i*2-k,0LL);j<=i;j++)        //相同 
      {
        t=t*(i+1-j)%mod*ni[j]%mod;
        ans=(ans+s*t%mod
            *c[k-i][i-j]%mod*f[n][i]%mod*
            f[n][i]%mod*sumi(j,n*(m-2)))%mod;
      }
    }
    printf("%I64d\n",ans);
    return 0;
}
        
