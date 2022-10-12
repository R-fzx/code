#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max_m 1000005
#define mo 1048575

long long n,m,i,dis[1005],du[1005],ans,x,map[1005][1005];
long long e[max_m],succ[max_m],last[max_m],v[max_m],sum;
long long zl[2000005],h,t;
char str[1005],hash[1005];

class E
{
      public:
          //public_begin
          
          long long s,t,val;          
          
          void read()
          {
               gets(str);
               sscanf(str,"%I64d %I64d %I64d",&s,&t,&val);
               return;
          }
          
          void make()
          {
               if (map[s][t]==0)
               {
                  e[++sum]=t,succ[sum]=last[s],last[s]=sum,v[sum]=val;
                  e[++sum]=s,succ[sum]=last[t],last[t]=sum,v[sum]=val;
                  map[s][t]=sum-1,map[t][s]=sum;
               }
               else
               {
                   if (val<v[map[s][t]]) v[map[s][t]]=val;
                   if (val<v[map[t][s]]) v[map[t][s]]=val;
               }
               return;
          }
          
          friend bool operator < (E a,E b)
          {
              if (a.val<b.val) return 1;
              else return 0;
          }
          
          friend bool operator > (E a,E b)
          {
              if (a.val>b.val) return 1;
              else return 0;
          }
                     
          //public_end
};

E a[max_m];

int main()
{
    freopen("Castle.in","r",stdin); freopen("Castle.out","w",stdout);
    scanf("%I64d %I64d\n",&n,&m);
    for(i=1;i<=m;i++)
    {
       a[i].read();
       a[i].make();
    }
    
    zl[1]=1;
    for(i=1;i<=n;i++)
    dis[i]=16161616;
    dis[1]=0;
    for(h=t=mo+2;h<=t;h++)
    {
       x=zl[h&mo];
       hash[x]=0;
       for(i=last[x];i!=0;i=succ[i])
       {
          if (dis[x]+v[i]<dis[e[i]])
          {
             dis[e[i]]=dis[x]+v[i];
             if (hash[e[i]]==1) continue;
             if (dis[e[i]]<dis[zl[(h+1)&mo]])
             {
                zl[h&mo]=e[i];
                h--;
             }
             else
             {
                 t++;
                 zl[t&mo]=e[i];
             }
             hash[e[i]]=1;
          }
       }
    }
    du[1]=ans=1;
    for(i=1;i<=m;i++)
    {
       if (dis[a[i].s]+a[i].val==dis[a[i].t])
       du[a[i].t]++;
       if (dis[a[i].t]+a[i].val==dis[a[i].s])
       du[a[i].s]++;
    }
    for(i=1;i<=n;i++)
    ans*=du[i],ans%=((1<<31)-1);
    printf("%I64d\n",ans);
    return 0;
}
