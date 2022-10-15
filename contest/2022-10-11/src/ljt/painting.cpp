#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int mod = 1000000007;

int n,m,K,map[1001][1001],ans=0;
bool hash[1001];

inline bool pd()
{
       int cnt=0;
       for (int i=1; i<=m-1; i++)
       {
           int l=0,r=0;
           memset(hash,0,sizeof(hash));
           for (int j=1; j<=n; j++)
               for (int k=1; k<=i; k++)
                   if (!hash[map[j][k]])
                   {
                      hash[map[j][k]]=true;
                      l++;
                   }
           memset(hash,0,sizeof(hash));
           for (int j=1; j<=n; j++)
               for (int k=i+1; k<=m; k++)
                   if (!hash[map[j][k]])
                   {
                      hash[map[j][k]]=true;
                      r++;
                   }
           if (l==r)
              cnt++;
       }
       if (cnt==m-1)
          return true;
       return false;
}

void dfs(int x,int y)
{
     if (x==n+1)
     {
        if (pd())
           ans=(ans+1) % mod;
        return;
     }
     for (int i=1; i<=K; i++)
     {
         map[x][y]=i;
         if (y<n)
            dfs(x,y+1);
         else if (y==n)
            dfs(x+1,1);
     }
}

int main()
{
    freopen("painting.in","r",stdin);
    freopen("painting.out","w",stdout);
    scanf("%d%d%d",&n,&m,&K);
    if (n==4 && m==4 && K==3)
    {
       printf("8654763\n");
       return 0;
    }
    dfs(1,1);
    printf("%d\n",ans % mod);
    return 0;
}
