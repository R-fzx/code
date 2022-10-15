#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m,sum;
int co[100][100],b1[100],b2[100],ko;
void dfs(int x,int y)
{
     int i,j,k;
     if(x>=n)
     {
      for(k=0;k<m-1;k++)
      {
       memset(b1,0,sizeof(b1));
       memset(b2,0,sizeof(b2));
       for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        if(j<=k)
         b1[co[i][j]]=1;
        else
         b2[co[i][j]]=1;
       for(i=1;i<=ko;i++)
       if(b1[i]!=b2[i])
        break;
       if(i!=ko+1)
        break;
      }
      if(k==m-1)
       sum++;
      return;
     }
     for(i=1;i<=k;i++)
     if(y+1>=m)
     {
      co[x][y]=i;
      dfs(x+1,y);
      co[x][y]=0;
     }
     else
     {
      co[x][y]=i;
      dfs(x,y+1);
      co[x][y]=0;
     }
}
int main()
{
    int i,j;
    freopen("painting.in","r",stdin);
    freopen("painting.out","w",stdout);
    scanf("%d%d%d",&n,&m,&ko);
    if(ko>n)
    {
     printf("%d\n",0);
     return 0;
    }
    dfs(0,0);
    printf("%d\n",sum);
    return 0;
}
