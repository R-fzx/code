#include<stdio.h>
#include<stdlib.h>
int n,m,s[100],gift,l[1000],b[1000],g[1000],A;
double pro[1025],ans;
int min(int a,int b)
{
    if(a<b)
     return a;
    else
     return b;
}
void dfs(int m)
{
     if(m>=n)
     {
      int i,j,k;
      double pos=1,tot=0;
      for(i=0;i<(1<<n);i++)
      {
       int to=0;
       pos=1;
       j=i;
       for(k=0;k<n;k++)
       {
        s[k]=j%2;
        to+=s[k];
        j=j/2;
       }
       for(k=0;k<n;k++)
       if(s[k])
       {
        pos*=l[k];
        pos/=100;
       }
       else
       {
        pos*=(100-l[k]);
        pos/=100;
       }
       if(to<=n/2)
        pos*=pro[i];
       tot+=pos;
      }
      if(tot>ans) ans=tot;
      return;
     }
     int i;
     for(i=g[m-1];i<=gift;i++)
     {
      int temp=l[m];
      g[m]=i;
      l[m]=min(l[m]+(g[m]-g[m-1])*10,100);
      dfs(m+1);
      l[m]=temp;
     }
}
int main()
{
    int i,j,k,tot,e=0,t[10];
    freopen("assembly.in","r",stdin);
    freopen("assembly.out","w",stdout);
    scanf("%d%d%d",&n,&gift,&A);
    for(i=0;i<n;i++)
    {
     scanf("%d%d",&b[i],&l[i]);
    }
    for(i=0;i<(1<<n);i++)
    {
     int to=0;
     j=i;tot=0;
     for(k=0;k<n;k++)
     {
      s[k]=j%2;
      to+=s[k];
      j=j/2;
     }//1为支持
     //0为不支持
     e=0;
     for(k=0;k<n;k++)
     if(s[k]==0)
     {
      t[e]=b[k];
      e++;
     }
     for(k=0;k<e;k++)
      tot+=t[k];
     tot+=A;
     pro[i]=A;
     pro[i]/=tot;
    }
    dfs(0);
    printf("%.6lf\n",ans);
    return 0;
}
