#include <stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

int b[9],l[9];
double s,ans=0;
int n,k,A;

void dfs2(int now,int num,double p,int B)
{
   if (now>n)
      s+=((2*num>n)?1:1.0*A/(A+B))*p;
   else
   {
      dfs2(now+1,num+1,p*l[now]/100.0,B);
      dfs2(now+1,num,p*(1-l[now]/100.0),B+b[now]);
   }
}

void dfs(int now,int p)
{
   int i;
   if (now>k)
   {
      s=0;
      dfs2(1,0,1,0);
      ans=max(ans,s);
   }
   else
      for (i=p;i<=n;i++)
         if (l[i]<100)
         {
            l[i]+=10;
            dfs(now+1,i);
            l[i]-=10;
         }
}

int main()
{
   freopen("assembly.in","r",stdin);
   freopen("assembly.out","w",stdout);
   int i,a=0;
   scanf("%d%d%d",&n,&k,&A);
   for (i=1;i<=n;i++)
   {
      scanf("%d%d",&b[i],&l[i]);
      a+=(100-l[i])/10;
   }
   k=min(k,a);
   dfs(1,1);
   printf("%.6lf\n",ans);
   return 0;
}
