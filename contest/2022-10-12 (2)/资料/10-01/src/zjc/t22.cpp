#include<stdio.h>
#include<algorithm>
int h[100000000],m,n,ans,k;
int main()
{
    freopen("t2.in","r",stdin);
    freopen("t22.out","w",stdout);
    int i,j;
    for(i=2;i<=1000;i++)
      for(k=i,j=1;j<=30,k<=10000000;k*=i,j++)
        if(!h[k]) h[k]=j;
    while(1)
    {
      scanf("%d%d",&n,&m); if(!(m|n)) return 0;
      for(ans=0,i=n;i<=m;i++) 
       ans+=h[i];
      printf("%d\n",ans);
    }
    return 0;
}
    
