#include <stdio.h>
#define oo 2100000000000000000LL
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

struct case1
{
   int a,b,x,y;
}r[50001];
int e[100202],next[100202],last[100202],num[100202],hash[201],v[201];
int totm,flag=0;

void add(int a,int b,int c)
{
   e[++totm]=b;
   num[totm]=c;
   next[totm]=next[a];
   last[totm]=a;
   next[last[totm]]=last[next[totm]]=totm;
}

void del(int a)
{
   last[next[a]]=last[a];
   next[last[a]]=next[a];
}

void qs(int x,int y)
{
   int i=x,j=y;
   struct case1 t=r[(x+y)>>1];
   if (x>=y)
      return;
   r[(x+y)>>1]=r[x];
   while (i<j)
   {
      while (i<j&&r[j].x>t.x)
         j--;
      if (i<j)
         r[i++]=r[j];
      while (i<j&&r[i].x<t.x)
         i++;
      if (i<j)
         r[j--]=r[i];
   }
   r[i]=t;
   qs(x,i-1);
   qs(i+1,y);
}

int find(int x,int y)
{
   int i,t;
   if (x==y)
      return -1;
   hash[x]=flag;
   for (i=next[x];i;i=next[i])
      if (hash[e[i]]!=flag&&(t=find(e[i],y)))
         return (t==-1||r[num[t]].y<r[num[i]].y)?i:t;
   return 0;
}

int main()
{
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
   int i,j,n,m,p,q,t,s=0;
   long long ans=oo;
   scanf("%d%d%d%d",&n,&m,&p,&q);
   totm=n+!(n&1);
   for (i=1;i<=m;i++)
      scanf("%d%d%d%d",&r[i].a,&r[i].b,&r[i].x,&r[i].y);
   qs(1,m);
   for (i=1;i<=m;i++)
   {
      flag++;
      t=find(r[i].a,r[i].b);
      if (!t)
      {
         add(r[i].a,r[i].b,i);
         add(r[i].b,r[i].a,i);
         v[++s]=i;
      }
      else if (t>0&&r[num[t]].y>r[i].y)
      {
         for (j=1;v[j]!=num[t];j++);
         v[j]=i;
         del(t);
         del(t^1);
         add(r[i].a,r[i].b,i);
         add(r[i].b,r[i].a,i);
      }
      if (s==n-1)
      {
         t=0;
         for (j=1;j<=s;j++)
            t=max(t,r[v[j]].y);
         ans=min(ans,(long long)r[i].x*p+(long long)t*q);
      }
   }
   printf("%I64d\n",(ans==oo)?-1:ans);
   return 0;
}
