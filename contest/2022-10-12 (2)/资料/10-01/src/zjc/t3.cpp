#include<stdio.h>
#include<algorithm>
#define mod 10007
using namespace std;
int a[10000],len,n;
inline void c(int x)
{
    int i;
    for(i=1;i<=len;i++) a[i]*=x;
    for(i=1;i<=len;i++)
    {
      a[i+1]+=a[i]/10000;
      a[i]%=10000;
    }
    if(a[len+1]) len++;
    return;
}
inline void u()
{
    int i;
    a[1]++;
    for(i=1;a[i]>=10000;a[i]-=10000,a[i+1]++,i++);
    if(a[len+1]) len++;
    return;
}
inline void d()
{
    int i;
    a[1]--;
    for(i=1;a[i]<0;a[i]+=10000,a[i+1]--,i++);
    if(!a[len]) len--;
    return;
}
int main()
{
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    int i,j;
    scanf("%d",&n);
    if(n==1) { printf("0\n"); return 0; }
    a[1]=len=1;
    for(i=3;i<=n;i++)
    {
       c(i);
       if(i&1) d(); else u();
       //printf("%3d ",i);
       //printf("%d",a[len]);
       //for(j=len-1;j;j--) printf("%04d",a[j]);
       //printf("\n");
    }
    printf("%d",a[len]);
    for(j=len-1;j;j--) printf("%04d",a[j]);
    printf("\n");
    return 0;
}
