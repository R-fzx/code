#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const long long maxlongint=(long long)1e18;

struct road
{
       int sum;
       long long A[201],B[201];
       road() { sum=0; }
       inline void insert(long long va,long long vb)
       {
                   sum++;
                   A[sum]=va,B[sum]=vb;
       }
}R[201][201];

struct node
{
       int num,in;
       long long val;
       node() { in=0; }
}low[210];

long long n,m,p,q,ans=0,est[201];

long long get(long long ea,long long eb,long long a,long long b)
{
     long long r1=0,r2=0;
     if (a>ea) r1=(a-ea)*p;
     if (b>eb) r2=(b-eb)*q;
     return (r1+r2);
}

long long Prim()
{
     long long ea=0,eb=0;
     low[1].val=0;
     low[1].in=1;
     for (int i=2; i<=n; i++)
     {
         if (R[1][i].sum==0)
         {
             low[i].val=maxlongint;
             est[i]=-1;
             continue;
         }
         long long mmin=maxlongint,numb;
         for (int k=1; k<=R[1][i].sum; k++)
             if (get(ea,eb,R[1][i].A[k],R[1][i].B[k])<mmin)
             {
                 mmin=get(ea,eb,R[1][i].A[k],R[1][i].B[k]);
                 numb=k;
             }
         low[i].val=mmin;
         low[i].num=numb;
         est[i]=1;
     }
     for (int i=1; i<n; i++)
     {
         long long mmin=maxlongint,pos;
         for (int j=1; j<=n; j++)
             if (low[j].in!=1 && mmin>low[j].val)
             {
                mmin=low[j].val;
                pos=j;
             }
         low[pos].in=1; ans+=mmin;
         ea=max(ea,R[est[pos]][pos].A[low[pos].num]); eb=max(eb,R[est[pos]][pos].B[low[pos].num]);
         for (int j=1; j<=n; j++)
             if (low[j].in!=1 && R[pos][j].sum!=0)
             {
                long long mmin=maxlongint,numb;
                for (int k=1; k<=R[pos][j].sum; k++)
                    if (get(ea,eb,R[pos][j].A[k],R[pos][j].B[k])<mmin)
                    {
                       mmin=get(ea,eb,R[pos][j].A[k],R[pos][j].B[k]);
                       numb=k;
                    }
                if (low[j].val>mmin)
                {
                   low[j].val=mmin;
                   low[j].num=numb;
                   est[j]=pos;
                }
             }
     }
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long u,v,a,b;
    scanf("%I64d%I64d",&n,&m);
    scanf("%I64d%I64d",&p,&q);
    for (int i=1; i<=m; i++)
    {
        scanf("%I64d%I64d%I64d%I64d",&u,&v,&a,&b);
        if (u==v) continue;
        R[u][v].insert(a,b);
        R[v][u].insert(a,b);
    }
    if (m>0)
       Prim();
    if (ans>0)
       printf("%I64d\n",ans);
    else
       printf("-1\n");
    return 0;
}
