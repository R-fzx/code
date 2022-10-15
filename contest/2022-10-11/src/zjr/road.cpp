#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,sum,p,q,f[201],bian[201],lj[201][201],uu,vv,mmm;
bool hash[201],hash1[201],solve;
long long ans;
struct node
{
       int u,v,a,b;
}d[100001];
inline void add(int u,int v,int a,int b)
{
       sum++;
       d[sum].u=u;
       d[sum].v=v;
       d[sum].a=a;
       d[sum].b=b;
}
inline bool cmp(node a,node b)
{
       return a.a<b.a;
}
int gf(int k)
{
    if(f[k]==k)return k;
    f[k]=gf(f[k]);
    return f[k];
}
void search(int now,int end)
{
     if(now==end)
     {
       solve=1;
       return;
     }
     int i;
     for(i=1;i<=n;i++)
       if(lj[now][i]>0)
         if(hash[i]==0)
         {
           hash[i]=1;
           search(i,end);
           if(solve)
           {
             if(lj[now][i]>mmm)
             {
               mmm=lj[now][i];
               uu=now;
               vv=i;
             }
             return;
           }
           hash[i]=0;
         }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int i,x,y,aa,bb;
    bool ok;
    scanf("%d%d%d%d",&n,&m,&p,&q);
    for(i=1;i<=m;i++)
    {
      scanf("%d%d%d%d",&x,&y,&aa,&bb);
      add(x,y,aa,bb);
    }
    sort(&d[1],&d[m]+1,cmp);
    for(i=1;i<=n;i++)f[i]=i;
    sum=0;
    ans=-1;
    for(i=1;i<=m;i++)
    {
      aa=gf(d[i].u);
      bb=gf(d[i].v);
      if(aa!=bb)
      {
        f[f[aa]]=bb;
        lj[aa][bb]=d[i].b;
        lj[bb][aa]=d[i].b;
        sum++;
        if(sum!=n-1)continue;
        mmm=0;
        for(x=1;x<=n;x++)for(y=1;y<=n;y++)if(lj[x][y]>mmm)mmm=lj[x][y];
        if((long long)d[i].a*(long long)p+(long long)mmm*(long long)q<ans||ans==-1)
        ans=(long long)d[i].a*(long long)p+(long long)mmm*(long long)q;
      }
      else
      {
        solve=0;
        mmm=0;
        memset(hash,0,sizeof(hash));
        search(d[i].u,d[i].v);
        if(mmm<d[i].b)continue;
        lj[uu][vv]=0;
        lj[vv][uu]=0;
        lj[d[i].u][d[i].v]=d[i].b;
        lj[d[i].v][d[i].u]=d[i].b;
        if(sum!=n-1)continue;
        mmm=0;
        for(x=1;x<=n;x++)for(y=1;y<=n;y++)if(lj[x][y]>mmm)mmm=lj[x][y];
        if((long long)d[i].a*(long long)p+(long long)mmm*(long long)q<ans||ans==-1)
        ans=(long long)d[i].a*(long long)p+(long long)mmm*(long long)q<ans;
      }
    }
    printf("%I64d\n",ans);
    return 0; 
}
