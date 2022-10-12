#include <stdio.h>
#include <stdlib.h>
#define MOD 2147483647

int len[1001][1001]={0};
int dis[1001]={0};
int f[1001]={0};
int n,m,i,j,x,y,z;
int p[1000001][2]={0};
long long ans=1;
char hash[1001];

void sw(int a,int b)
{
     int t;
     t=p[a][0];
     p[a][0]=p[b][0];
     p[b][0]=t;
     
     t=p[a][1];
     p[a][1]=p[b][1];
     p[b][1]=t;
}
void in(int a,int b)
{
     p[0][0]++;
     int k=p[0][0];
     p[k][0]=a;
     p[k][1]=b;
     while (k>1 && p[k][1]<p[k/2][1])
     {
           sw(k,k/2);
           k=k/2;
     }
}

void out(void)
{
     int k=1;
     p[1][0]=p[p[0][0]][0];
     p[1][1]=p[p[0][0]][1];
     p[0][0]--;
     while (k*2<=p[0][0])
     {
           if (k*2+1<=p[0][0]
              && p[k*2+1][1]<p[k*2][1]
              && p[k*2+1][1]<p[k][1])
           {
                 sw(k,k*2+1);
                 k=k*2+1;
           }
           else
           if (p[k*2][1]<p[k][1])
           {
              sw(k,k*2);
              k=k*2;
           }
           else
               k=p[0][0]+1;
     }
} 

int main()
{
    freopen("Castle.in","r",stdin);
    freopen("Castle.out","w",stdout);
    
    scanf("%d%d",&n,&m);
    for (i=1; i<=m; i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if (len[x][y]==0 || len[x][y]>z)
           len[x][y]=len[y][x]=z;
    }
    
    hash[1]='Y';
    f[1]=1;
    for (i=2; i<=n; i++)
    {
        f[i]=1;
        if (len[1][i]>0)
           in(i,len[1][i]);
    }
    
    for (i=2; i<=n; i++)
    {
        x=p[1][0];
        while (hash[x]=='Y')
        {
              if (p[1][1]==dis[x])
                 f[x]++;
              out();
              x=p[1][0];
        }
        
        y=p[1][1];
        out();
        hash[x]='Y';
        dis[x]=y;
        for (j=1; j<=n; j++)
        {
            if (len[x][j]!=0 && hash[j]!='Y')
               in(j,y+len[x][j]);
        }
    }
    
    while (p[0][0]>0)
    {
          if (p[1][1]==dis[p[1][0]])
             f[p[1][0]]++;
          out();
    }
    
    for (i=2; i<=n; i++)
    {
        ans*=f[i];
        ans%=MOD;
    }
    
    printf("%I64d\n",ans);
    
    //system("pause");
    return 0;
}
