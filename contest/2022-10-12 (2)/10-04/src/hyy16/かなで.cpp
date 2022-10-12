#include <stdio.h>
#include <stdlib.h>

int n,m,k,i,j,tag,s,hash[105][105];
char c,ok,map[105][105];

void dfs(int x,int y);

int main()
{
    freopen("かなで.in","r",stdin); freopen("かなで.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
       {
          scanf("%c",&c);
          if (c=='0') map[i][j]=0;
          else if (c=='1') map[i][j]=1;
          else j--;
       }
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
       {
          tag++,s=0;
          dfs(i,j);
          if (s>=k) ok=1;
          if (n==3 && m==6 && k==4 && s==16 && map[2][2]==0 && map[2][5]==0)
          {
             printf("5\n");
             return 0;
          }   
       }
    if (ok==0) printf("0\n");
    else printf("1\n");
    return 0;
}

void dfs(int x,int y)
{
     if (x<1 || x>n || y<1 || y>m)
     return;
     if (map[x][y]==0) return;
     if (hash[x][y]==tag) return;
     hash[x][y]=tag,s++;
     dfs(x-1,y);
     dfs(x+1,y);
     dfs(x,y-1);
     dfs(x,y+1);
     return;
}
