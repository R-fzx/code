#include<stdio.h>
#include<stdlib.h>
int cost1,cost2,e,sum,co[1001],max1,max2;
int n,m,tot,pre[100001],last[100001],need1[100001],need2[100001],back[100001];
void flood(int v)
{
    int i;
    co[v]=1;
    for(i=last[v];i;i=pre[i])
    if(need1[i]<=e&&!co[back[i]])
    {
     flood(back[i]);
    }
}
int ok()
{
    int i,j;
    memset(co,0,sizeof(co));
    flood(0);
    for(i=0;i<n;i++)
    if(!co[i])
     return 0;
    return 1;
}
void flood1(int v)
{
    int i;
    co[v]=1;
    for(i=last[v];i;i=pre[i])
    if(need2[i]<=e&&!co[back[i]])
    {
     flood1(back[i]);
    }
}
int ok1()
{
    int i,j;
    memset(co,0,sizeof(co));
    flood1(0);
    for(i=0;i<n;i++)
    if(!co[i])
     return 0;
    return 1;
}
int main()
{
    int ll,rr,u,v,i,j,k;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%d%d",&cost1,&cost2);
    for(i=0;i<m;i++)
    {
     scanf("%d%d%d%d",&u,&v,&j,&k);
     u--,v--;
     if(j>max1)
      max1=j;
     if(k>max2)
      max2=k;
     tot++;pre[tot]=last[u];last[u]=tot;back[tot]=v;need1[tot]=j;need2[tot]=k;
     tot++;pre[tot]=last[v];last[v]=tot;back[tot]=u;need1[tot]=j;need2[tot]=k;
    }
    ll=0;rr=max1+1;
    while(ll!=rr)
    {
     int mid=(ll+rr)/2;
     e=mid;
     if(ok())
      rr=mid;
     else
      ll=mid+1;
    }
    if(rr==max1+1)
    {
     printf("-1\n");
     return 0;
    }
    sum+=cost1*ll;
    ll=0;rr=max2+1;
    while(ll!=rr)
    {
     int mid=(ll+rr)/2;
     e=mid;
     if(ok1())
      rr=mid;
     else
      ll=mid+1;
    }
    if(rr==max2+1)
    {
     printf("-1\n");
     return 0;
    }
    sum+=cost2*ll;
    printf("%d\n",sum);
    return 0;
}
