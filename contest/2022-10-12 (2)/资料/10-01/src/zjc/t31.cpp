#include<stdio.h>
#include<algorithm>
#define mod 10007
using namespace std;
long long f[21][1048576];
int main()
{
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    int i,j,k,n;
    scanf("%d",&n);
    for(f[0][0]=1,i=0;i<n;i++)
      for(j=0;j<=(1<<n);j++)
        if(f[i][j])
          for(k=0;k<n;k++)
            if((k!=i)&&(!((j>>k)&1)))
              f[i+1][j^(1<<k)]+=f[i][j];
    printf("%I64d\n",f[n][(1<<n)-1]);
    return 0;
}
