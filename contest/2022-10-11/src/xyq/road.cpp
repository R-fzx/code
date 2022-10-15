#include<stdio.h>
#include<stdlib.h>

int n,m,p,q;
long long ok[210][210],ans,f[210][210],f1[210][210],suidao,qiaoliang,hash[210],jilu1,jilu,panduan[210][210];

long long  max(long long a,long long  b)
{
    if(a>b) return a;
    else return b;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&m);
    scanf("%d %d",&p,&q);
    int u,v,a,b;
    for(int i=1;i<=m;i++)
    {
            scanf("%d %d %d %d",&u,&v,&a,&b);
            if(ok[u][v]==1)
            {
                           if(f[u][v]*p+f1[u][v]*q>a*p+b*q)
                           {
                                                           f[u][v]=a;
                                                           f[v][u]=a;
                                                           f1[v][u]=b;
                                                           f1[u][v]=b;
                                                           break;
                           }
            }
            else 
            {
                 panduan[u][v]=1;
                 panduan[v][u]=1;
                 ok[u][v]=1;
                 ok[v][u]=1;
                 f[u][v]=a;
                 f1[u][v]=b;
                 f[v][u]=a;
                 f1[v][u]=b;
            }
    }
    suidao=0;
    qiaoliang=0;
    if(m<=0)
    {
            printf("-1\n");
            return 0;
    }
    if(m==1)
    {
            ans=a*p+b*q;
            printf("%d\n",ans);
            return 0;
    }
    for(int k=1;k<=n;k++)
     for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
      {
              if(ok[i][k] && ok[k][j])
              {
                         ok[i][j]=1;
              }
      }
      for(int i=2;i<=n;i++)
      {
              if(!ok[1][i])
              {
                           printf("-1\n");
                           return 0;
              }
      }
      hash[1]=1;
      for(int i=1;i<=n-1;i++)
      {
              long long min=(long long)(1e18);
              for(int j=1;j<=n;j++)
              if(hash[j]==1)
               for(int k=1;k<=n;k++)
               if(hash[k]==0 && panduan[j][k]==1 && min>(max(0,f[j][k]-suidao)*p+max(0,f1[j][k]-qiaoliang)*q))
               {
                             jilu=k;
                             jilu1=j;
                             min=max(0,f[j][k]-suidao)*p+max(0,f1[j][k]-qiaoliang)*q;
               }
               ans=ans+min;
               hash[jilu]=1;
               suidao=max(suidao,f[jilu1][jilu]);
               qiaoliang=max(qiaoliang,f1[jilu1][jilu]);
      }
      printf("%I64d\n",ans);
      return 0;
}
    
    
