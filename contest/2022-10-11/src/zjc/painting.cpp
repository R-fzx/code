#include<stdio.h>
#include<iostream>
#define mod 1000000007
using namespace std;
long long c[2005][2005],a[10000],b[10000],d[10000],e[10000],f[2005][2005],ni[1000005],s,t,n,m,k,ans,s1,s2,s3;
long long sumi(long long x,long long y) { long long z=1; for(;y;y>>=1) { if(y&1) z=z*x%mod; x=x*x%mod; } return z; }
void get(int x)
{
    int i;
    for(a[0]=i=1;i<=x;i++) a[i]=a[i-1]*(x+1-i)%mod*ni[i]%mod;
    for(b[0]=i=1;i<=x;i++) b[i]=b[i-1]*(k-x+1-i)%mod*ni[i]%mod;
}
int main()
{
    freopen("painting.in","r",stdin);
    freopen("painting.out","w",stdout);
    long long i,j;
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    if(m==1) { printf("%I64d",sumi(k,n)); return 0; }
    for(i=1;i<=n;i++) ni[i]=sumi(i,mod-2);
    for(i=1;i<=n;i++) f[i][1]=1;
    for(i=2;i<=n;i++) for(j=1;j<=n;j++) f[i][j]=(f[i-1][j-1]+f[i-1][j])*j%mod;
    for(i=1;i<=n;i++) d[i]=f[n][i]*f[n][i]%mod;
    for(i=1;i<=n;i++) e[i]=sumi(i,n*(m-2));
    for(s=1,i=1;(i<=k)&&(i<=n);i++)//一共 
    {
      s=s*(k+1-i)%mod*ni[i]%mod;
      for(get(i),j=max(i*2-k,1LL);j<=i;j++)        //相同 
        ans=(ans+s*a[j]%mod*b[i-j]%mod*d[i]%mod*e[j])%mod;
    }
    printf("%I64d\n",ans);
    return 0;
}
