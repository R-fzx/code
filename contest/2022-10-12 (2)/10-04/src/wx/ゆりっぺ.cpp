#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long max(long long x,long long y)
{
    if(x>y)return x;
    return y;
}
long long n,A,B,C,num;
long long f[111][111][111],g[111][111][111]={0},sum[500500];
bool ok[500500];
struct pp
{
       long long a,b,c;
       long long pos;
}z[500200];
struct heap
{
       long long x,pos;
}h[500200];
void insert(long long now,long long from)
{
     long long t=++num;
     while(t>1)
     {
      if(now<h[t>>1].x)break;
      h[t]=h[t>>1];
      t>>=1;
     }
     h[t].x=now;
     h[t].pos=from;
}
void del()
{
     heap now=h[num--];
     long long t=1;
     while(t+t<=num)
     {
      long long nex=t+t;
      if(nex<num&&h[nex+1].x>h[nex].x)nex++;
      if(now.x>h[nex].x)break;
      h[t]=h[nex];
      t=nex;
     }
     h[t]=now;
}
int cmpa(pp x,pp y)
{return x.a>y.a;}
int cmpb(pp x,pp y)
{return x.b>y.b;}
int cmpc(pp x,pp y)
{return x.c>y.c;}
void wx_sort(long long x)
{
     num=0;
     long long i,j,k;
     for(i=1;i<=n;i++)
     if(x==1)insert(z[i].a,z[i].pos);
     else if(x==2)insert(z[i].b,z[i].pos);
     else if(x==3)insert(z[i].c,z[i].pos);
     for(i=1;i<=A+B+C;i++)
     {
      ok[h[1].pos]=1;
      del();
     }
}
int main()
{
    freopen("ゆりっぺ.in","r",stdin);
    freopen("ゆりっぺ.out","w",stdout);
    long long i,j,k,p;
    scanf("%I64d%I64d%I64d%I64d",&n,&A,&B,&C);
    if(A+B+C>n){
                 printf("I am a godlike cowcowcow");
                 return 0;
                 }
    for(i=1;i<=n;i++)
    {
     scanf("%I64d%I64d%I64d",&z[i].a,&z[i].b,&z[i].c); 
     z[i].pos=i;
    }
     wx_sort(1);wx_sort(2);wx_sort(3);
    /* sort(z+1,z+1+n,cmpa);
     for(i=1;i<=A+B+C;i++)
     ok[z[i].pos]=1;
     
     sort(z+1,z+1+n,cmpb);
     for(i=1;i<=A+B+C;i++)
     ok[z[i].pos]=1;
     
     sort(z+1,z+1+n,cmpc);
     for(i=1;i<=A+B+C;i++)
     ok[z[i].pos]=1;
     */
     long long num=0;
     for(i=1;i<=n;i++)
     if(ok[z[i].pos])
     {
     z[++num]=z[i];
     sum[num]=z[i].a+z[i].b+z[i].c;//fuck!!!!!!!!!!!!!!!!!!!!
     }
     n=num;
     for(j=0;j<=A;j++)
     for(k=0;k<=B;k++)
     for(p=0;p<=C;p++)
     f[j][k][p]=g[j][k][p]=-200000000000000000LL;
     f[0][0][0]=g[0][0][0]=0;
    for(i=1;i<=n;i++)
    for(j=A;j>=0;j--)
    for(k=B;k>=0;k--)
    for(p=C;p>=0;p--)
    {
     if(j>0)
     if(f[j-1][k][p]+z[i].a>f[j][k][p] || (f[j-1][k][p]+z[i].a==f[j][k][p]
     && g[j-1][k][p]+sum[i]>g[j][k][p]))
     {
        f[j][k][p]=f[j-1][k][p]+z[i].a;
        g[j][k][p]=g[j-1][k][p]+sum[i];
     }
     if(k>0)
     if(f[j][k-1][p]+z[i].b>f[j][k][p] || (f[j][k-1][p]+z[i].b==f[j][k][p]
     && g[j][k-1][p]+sum[i]>g[j][k][p]))
     {
        f[j][k][p]=f[j][k-1][p]+z[i].b;
        g[j][k][p]=g[j][k-1][p]+sum[i];
     }
     if(p>0)
     if(f[j][k][p-1]+z[i].c>f[j][k][p] || (f[j][k][p-1]+z[i].c==f[j][k][p]
     && g[j][k][p-1]+sum[i]>g[j][k][p]))
     {
        f[j][k][p]=f[j][k][p-1]+z[i].c;
        g[j][k][p]=g[j][k][p-1]+sum[i];
     }
     
    }
    printf("%I64d\n",f[A][B][C]);
    printf("%I64d",g[A][B][C]);
    return 0;
}
