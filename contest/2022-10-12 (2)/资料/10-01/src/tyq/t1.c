#include<stdio.h>
#include<stdlib.h>
int n,l[1001],r[1001],f[1001],size[1001];
int c[2001][2001];
void dfs(int v)
{
     if(!l[v]&&!r[v])
     {
      f[v]=1,size[v]=1;
      return;
     }
     if(v==5)
      v++,v--;
     if(l[v])
      dfs(l[v]);
     if(r[v])
      dfs(r[v]);
     size[v]=size[l[v]]+size[r[v]];
     if(size[v]>100)
      v++,v--;
     f[v]=(c[size[v]][size[r[v]]]*f[l[v]])%10007*f[r[v]]%10007;
     size[v]++;
}
int main()
{
    int i,j,k,ber,w,q,last;
    freopen("t1.in","r",stdin);
    freopen("t1.out","w",stdout);
    scanf("%d",&ber);
    f[0]=1;
    for(i=0;i<=2000;i++)
     for(j=1,c[i][0]=1;j<=i;j++)
     c[i][j]=(c[i-1][j]+c[i-1][j-1])%10007;
    for(w=0;w<ber;w++)
    {
     memset(l,0,sizeof(l));
     memset(r,0,sizeof(r));
     memset(f,0,sizeof(f));
     f[0]=1;
     memset(size,0,sizeof(size));
     scanf("%d",&n);
     for(i=1;i<=n;i++)
     {
      scanf("%d",&k);
      if(k==0)
      continue;
      scanf("%d",&last);
      if(i==3)
       i++,i--;
      r[i]=last;
      for(j=1;j<k;j++)
      {
       scanf("%d",&q);
       l[last]=q;
       last=q;
      }
     }
     dfs(1);
     printf("%d\n",f[1]);
    }
    return 0;
}
