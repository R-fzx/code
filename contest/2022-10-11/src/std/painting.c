#include <stdio.h>
#define mod 1000000007

int f[2001],c[2001][2001],r1[2001],r2[4001];

int mi(int a,long long b)
{
   int t;
   if (!b)
      return 1;
   t=mi(a,b>>1);
   t=(long long)t*t%mod;
   if (b&1)
      t=(long long)t*a%mod;
   return t;
}

int main()
{
   freopen("painting.in","r",stdin);
   freopen("painting.out","w",stdout);
   int i,j,n,m,k,x,s=0,t=1;
   scanf("%d%d%d",&n,&m,&k);
   if (m==1)
      s=mi(k,n);
   else
   {
      for (i=0;i<=n;i++)
      {
         c[i][0]=1;
         for (j=1;j<=i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
      }
      for (i=1;i<=n;i++)
      {
         f[i]=mi(i,n);
         for (j=1;j<i;j++)
            f[i]=(f[i]-(long long)f[j]*c[i][j]%mod+mod)%mod;
      }
      r1[0]=r2[0]=1;
      for (i=1;i<=n;i++)
         r1[i]=(long long)r1[i-1]*mi(i,mod-2)%mod;
      for (i=1;i<=2*n&&i<=k;i++)
         r2[i]=(long long)r2[i-1]*(k-i+1)%mod;
      for (i=0;i<=n;i++)
      {
         x=mi(i,(long long)(m-2)*n);
         for (j=0;i+j<=n&&i+2*j<=k;j++)
            s=(s+(long long)r2[2*j+i]*r1[j]%mod*r1[j]%mod*r1[i]%mod*f[i+j]%mod*f[i+j]%mod*x)%mod;
      }
   }
   printf("%d\n",s);
   return 0;
}
