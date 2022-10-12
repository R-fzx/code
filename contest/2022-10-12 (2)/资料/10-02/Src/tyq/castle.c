#include<stdio.h>
#include<stdio.h>
int n,m;
int pre[1000000],last[1001],g[1000000],back[1000000],tot;
int c[1001],b[1001],s[5000000],zrp[1001][1001],a[1001];
long long sum;
int main()
{
    int h,i,j,u,v,e;
    freopen("Castle.in","r",stdin);
    freopen("Castle.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
     scanf("%d%d%d",&u,&v,&e);
     u--,v--;
     zrp[u][v]=e;
     zrp[v][u]=e;
    }
    
    for(i=0;i<n;i++)
    {
     for(j=i+1;j<n;j++)
     if(zrp[i][j])
     {
      tot++;pre[tot]=last[i];last[i]=tot;back[tot]=j;g[tot]=zrp[i][j];
      tot++;pre[tot]=last[j];last[j]=tot;back[tot]=i;g[tot]=zrp[j][i];
     }
    }
    for(i=0;i<n;i++)
     c[i]=2100000000;
    h=0;i=1;
    c[0]=0;
    s[0]=0;
    while(h<i)
    {
     for(j=last[s[h]];j;j=pre[j])
     if(c[back[j]]>c[s[h]]+g[j])
     {
      c[back[j]]=c[s[h]]+g[j];
      if(!b[back[j]])
      {
       b[back[j]]=1;
       s[i]=back[j];
       i++;
      }
     }
     b[s[h]]=0;
     h++;
    }
    for(i=0;i<n;i++)
    {
     for(j=last[i];j;j=pre[j])
     if(c[back[j]]==c[i]+g[j])
     {
      a[back[j]]++;
     }
    }
    //dfs(0);
    sum=1;
    for(i=1;i<n;i++)
     sum=(sum*a[i])%2147483647;
    printf("%I64d\n",sum);
    return 0;
}
