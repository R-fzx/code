#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long e[1000005],succ[1000005],next[1000005],val[1000005],last[1000005],sum;

class road
{
      public:
          
          unsigned long long s,t,a,b;
          
          void make()
          {
               e[++sum]=t,next[last[s]]=sum,succ[sum]=last[s],last[s]=sum;
               e[++sum]=s,next[last[t]]=sum,succ[sum]=last[t],last[t]=sum;
               val[sum]=val[sum-1]=a;
               return;
          }
               
          inline friend bool operator < (road a,road b)
          {
              if (a.b<b.b) return 1;
              else return 0;
          }
          
          inline friend bool operator > (road a,road b)
          {
              if (a.b>b.b) return 1;
              else return 0;
          }
};

unsigned long long fa,fb,n,m,i,j,x,amax,l,r,mid,s,p,q,f[205];
unsigned long long max,mm,ans,maxb,maxa;
unsigned long long tag,m1,m2,hash[205];

road a[50005];

void sort(unsigned long long l,unsigned long long r);
unsigned long long find(unsigned long long i);
unsigned long long check(unsigned long long ans);
void dfs(unsigned long long i,unsigned long long t,unsigned long long m1,unsigned long long m2);

int main()
{
    freopen("road.in","r",stdin); freopen("road.out","w",stdout);
    scanf("%I64u %I64u",&n,&m);
    scanf("%I64u %I64u",&p,&q);
    for(i=1;i<=m;i++)
       scanf("%I64u %I64u %I64u %I64u",&a[i].s,&a[i].t,&a[i].a,&a[i].b);
    for(i=1;i<=n;i++) f[i]=i;
    for(i=1;i<=m;i++)
    {
       fa=find(a[i].s);
       fb=find(a[i].t);
       if (fa!=fb) s++,f[fa]=fb;
    }
    if (s<n-1)
    {
       printf("-1\n");
       return 0;
    }
    ans=(1<<30);
    ans*=ans;
    sort(1,m);
    s=0;
    sum=1;
    for(i=1;i<=n;i++) f[i]=i;
    for(i=1;i<=m;i++)
    {
       if (a[i].s==a[i].t) continue;
       fa=find(a[i].s);
       fb=find(a[i].t);
       if (fa!=fb)
       {
          s++;
          a[i].make();
          f[fa]=fb;
          maxb=a[i].b;
       }
       else
       {
           max=mm=0;
           tag++;
           dfs(a[i].s,a[i].t,0,0);
           m1=mm;
           m2=(mm^1);
           if (max>a[i].a)
           {
              if (next[m1]==0) last[e[m2]]=succ[m1],next[succ[m1]]=0;
              else succ[next[m1]]=succ[m1],next[succ[m1]]=next[m1];
              if (next[m2]==0) last[e[m1]]=succ[m2],next[succ[m2]]=0;
              else succ[next[m2]]=succ[m2],next[succ[m2]]=next[m2];
              a[i].make();
              maxb=a[i].b;
           }
       }
       if (maxb*q>ans) break;
       if (s==n-1)
       {
          maxa=0;
          for(j=1;j<=n;j++)
             for(x=last[j];x!=0;x=succ[x])
                if (val[x]>maxa) maxa=val[x];
          if (maxa*p+maxb*q<ans) ans=maxa*p+maxb*q;
       }
    }
    printf("%I64u\n",ans);      
    return 0;
}

void sort(unsigned long long l,unsigned long long r)
{
     unsigned long long i=l,j=r;
     road k,mid;
     mid=a[(l+r)>>1];
     while (i<=j)
     {
           while (i<=j && a[i]<mid) i++;
           while (i<=j && a[j]>mid) j--;
           if (i<=j)
           {
              k=a[i],a[i]=a[j],a[j]=k;
              i++,j--;
           }
     }
     if (l<j) sort(l,j);
     if (i<r) sort(i,r);
     return;
}

unsigned long long find(unsigned long long i)
{
    if (f[i]==i) return i;
    f[i]=find(f[i]);
    return f[i];
}

void dfs(unsigned long long i,unsigned long long t,unsigned long long m1,unsigned long long m2)
{
     unsigned long long x;
     if (hash[i]==tag) return;
     hash[i]=tag;
     if (i==t) 
        max=m1,mm=m2;
     for(x=last[i];x!=0;x=succ[x])
     {
        if (val[x]>m1) dfs(e[x],t,val[x],x);
        else dfs(e[x],t,m1,m2);
     }
     return;
}
