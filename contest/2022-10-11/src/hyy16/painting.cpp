#include <stdio.h>
#include <stdlib.h>
#define mo 1000000007

int i,j;
int n,m,k,max,color,com,mid;
long long key,ans;
long long f[2005][2005],c[2005][2005];
int niyuan[2005],sm[2005];

long long C(long long n,long long m);
long long sumi(int a,int b);

int main()
{
    freopen("painting.in","r",stdin); freopen("painting.out","w",stdout);
    scanf("%I64d %I64d %I64d",&n,&m,&k);
    if (n<k) max=n;
    else max=k;
    for(i=1;i<=max;i++)
       niyuan[i]=sumi(i,mo-2);
    if (m<2)
    {
       printf("%I64d\n",sumi(k,n));
       return 0;
    }
    mid=(m-2)*n;
    f[0][0]=1;
    for(i=1;i<=max;i++)
       for(j=1;j<=n;j++)
          f[i][j]=(f[i-1][j-1]+f[i][j-1])*i%mo;
    for(i=0;i<=max;i++)
       sm[i]=sumi(i,mid);
    for(i=0;i<=max;i++)
    {
       c[i][0]=1;
       for(j=1;j<=max;j++)
          c[i][j]=(c[i][j-1]*(k-i-j+1)%mo*niyuan[j])%mo;
    }
    for(color=1;color<=max;color++)
       for(com=0;com<=color;com++)
       {
          key=sm[com];
          key*=c[0][com],key%=mo;
          key*=c[com][color-com],key%=mo;
          key*=c[color][color-com],key%=mo;
          key*=f[color][n],key%=mo;
          key*=f[color][n],key%=mo;
          ans+=key,ans%=mo;
       }
    printf("%I64d\n",ans);
    return 0;
}

long long C(long long n,long long m)
{
    long long ret=1,i;
    for(i=n-m+1;i<=n;i++) ret*=i,ret%=mo;
    for(i=1;i<=m;i++) ret*=niyuan[i],ret%=mo;
    return ret;
}

long long sumi(int a,int b)
{
    long long ret=1,i,k=a;
    for(i=1;i<=b;(i<<=1))
    {
       if ((b&i)>0) ret*=k,ret%=mo;
       k*=k,k%=mo;
    }
    return ret;
}
