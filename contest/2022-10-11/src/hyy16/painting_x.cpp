#include <stdio.h>
#include <stdlib.h>
#define mo 1000000007

int n,m,k,max,key,ans,color,com,mid;

int C(int n,int m);
int sumi(int a,int b);

int main()
{
    freopen("painting.in","r",stdin); freopen("painting.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    if (n<k) max=n;
    else max=k;
    if (m<2)
    {
       printf("%d\n",sumi(k,n));
       return 0;
    }
    mid=(m-2)*n;
    for(color=1;color<=max;color++)
       for(com=0;com<=color;com++)
       {
          key=sumi(com,mid);
          key*=C(k,com),key%=mo;
          key*=C(k-com,color-com),key%=mo;
          key*=C(k-color,color-com),key%=mo;
          ans+=key,ans%=mo;
       }
    printf("%d\n",ans);
    return 0;
}

int C(int n,int m)
{
    int ret=1,i;
    for(i=n-m+1;i<=n;i++) ret*=i;
    for(i=1;i<=m;i++) ret/=i;
    return ret;
}

int sumi(int a,int b)
{
    int ret=1,i,k=a;
    for(i=1;i<=b;(i<<=1))
    {
       if ((b&i)>0) ret*=k,ret%=mo;
       k*=k,k%=mo;
    }
    return ret;
}
