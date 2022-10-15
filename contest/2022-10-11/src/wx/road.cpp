//注意，边表i+M,i-M都有可能 
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int N,M,last[100500],next[100500],head[222];
long long ma,mb,ans=(long long)1E18,maxb,nex,G[222][222];
bool v[222];
struct pp
{
       long long A,B;
       int s,t;
}z[100050];
int cmp(pp a,pp b)
{
    if(a.A!=b.A)return a.A<b.A;
    else return a.B<b.B;
}
int sou(int x,int goal)
{
    int i,j,k;
    v[x]=1;
    if(x==goal)return 1;
    for(i=head[x];i!=0;i=next[i])
    if(!v[z[i].t])
    {
     if(sou(z[i].t,goal))
     {
      if(z[i].B>maxb)
      {
       maxb=z[i].B;
       nex=i;
      }
      return 1;
     }
    }
    return 0;
}
void link(int x)
{
     int i,j;
     v[x]=1;
     for(i=head[x];i!=0;i=next[i])
     if(!v[z[i].t])
     {
      link(z[i].t);
      if(z[i].B>maxb)
      maxb=z[i].B;
      }
}
void bian(int x)
{
     if(head[z[x].s]!=0){
                         last[head[z[x].s]]=x;
                         }
     next[x]=head[z[x].s];
     head[z[x].s]=x;
}
inline void del(int x)
{
     if(head[z[x].s]==x){
                         head[z[x].s]=next[x];
                         last[next[x]]=0;
                         if(last[x]!=0)
                         next[last[x]]=next[x];
                         }
     else {
           next[last[x]]=next[x];
           last[next[x]]=last[x];
           last[x]=next[x]=0;
           }
}
void insert(int x)
{
     if(z[x].s==z[x].t)return;
     if(G[z[x].s][z[x].t]!=0&&G[z[x].s][z[x].t]<z[x].B)return;
     G[z[x].s][z[x].t]=z[x].B;
     if(z[x].A*ma+z[x].B*mb>ans)return ;//给力优化啊。。 
     maxb=0;
     memset(v,0,sizeof(v));
     int i,j,flag=sou(z[x].s,z[x].t),x2,nex2;
     if(x>M)x2=x-M;
     else x2=x+M;
     if(nex>M)nex2=nex-M;
     else nex2=nex+M;
     if(flag!=0&&z[nex].B>z[x].B)
     {
      del(nex);
      del(nex2);
      bian(x);
      bian(x2);
      }
     else if(flag==0)
     {
      bian(x);
      bian(x2);
      }
      memset(v,0,sizeof(v));
      maxb=0;
       link(1);
       for(i=1;i<=N;i++)
       if(!v[i])break;
      if(i==N+1)
      {
       if(maxb*mb+z[x].A*ma<ans)
       ans=maxb*mb+z[x].A*ma;
       }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int i,j,k;
    scanf("%d%d",&N,&M);
    scanf("%I64d%I64d",&ma,&mb);
    for(i=1;i<=M;i++)
    {
     scanf("%d%d%I64d%I64d",&z[i].s,&z[i].t,&z[i].A,&z[i].B);
    
    }
    sort(z+1,z+1+M,cmp);
     for(i=1;i<=M;i++)
     {
      z[i+M]=z[i];
      z[i+M].s=z[i].t;
      z[i+M].t=z[i].s;
     }
    for(i=1;i<=M;i++)
    {
    insert(i);if(i==504)
    i=504;}
    printf("%I64d",ans);
    return 0;
}
