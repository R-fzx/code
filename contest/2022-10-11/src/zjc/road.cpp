#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define oo 0x7fffffff
struct road { long long a,b; int s,t; }p[100000];
int n,m,hash,f[200000];
long long v1,v2,t1,t2,ans,a[200000],b[200000],h[200000];
inline bool cmp(road x,road y) { return x.a<y.a; }
inline int find(int x) { if(!f[x]) return x; return find(f[x]); }
inline void turn(int x,int y) { if(f[x]==y) return; turn(f[x],y); f[f[x]]=x,a[f[x]]=a[x],b[f[x]]=b[x]; }
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int i,j,k,x,y,t;
    long long s;
    scanf("%d%d%I64d%I64d",&n,&m,&v1,&v2);
    for(i=1;i<=m;i++)
    {
      scanf("%d%d%I64d%I64d",&p[i].s,&p[i].t,&p[i].a,&p[i].b);
      if(p[i].s>p[i].t) swap(p[i].s,p[i].t);
    }
    ans=(1LL<<60LL);
    sort(p+1,p+1+m,cmp);
    for(i=1;i<=m;i++)
    {
      if(p[i].s==p[i].t) continue;
      x=p[i].s,y=p[i].t,t1=find(x),t2=find(y);
      if(t1>t2) turn(x,0),f[x]=y,a[x]=p[i].a,b[x]=p[i].b;
      else if(t1<t2) turn(y,0),f[y]=x,a[y]=p[i].a,b[y]=p[i].b;
      else
      {
        for(j=x;j;j=f[j]) h[j]=i;
        for(k=y;(h[k]!=i);k=f[k]);
        if(x==k) t=y,hash=1;
        else for(hash=0,t=j=x;j!=k;j=f[j]) if(b[t]<b[j]) t=j;
        for(j=y;j!=k;j=f[j]) if(b[t]<b[j]) t=j,hash=1;
        if((!hash)&&(b[t]>p[i].b)) turn(x,f[t]),f[x]=y,a[x]=p[i].a,b[x]=p[i].b;
        if((hash)&&(b[t]>p[i].b)) turn(y,f[t]),f[y]=x,a[y]=p[i].a,b[y]=p[i].b;
      }
      for(t1=t2=0,j=2;j<=n;j++) { if(!f[j]) break; if(t1<a[j]) t1=a[j]; if(t2<b[j]) t2=b[j]; }
      if((j>n)&&(ans>v1*t1+v2*t2)) ans=v1*t1+v2*t2;
    }
    if(ans==(1LL<<60LL)) printf("-1\n");
    else printf("%I64d\n",ans);
}
