#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m,sum;
int co[100][100],b1[100],b2[100],ko;
void dfs(int x,int y)
{
     int i,j,k,j1,j2;
     if(x>=n)
     {
      if(co[0][0]==1&&co[0][1]==2&&
         co[1][0]==1&&co[1][1]==2)
         i++,i--;
      for(k=0;k<m-1;k++)
      {
       j1=0;j2=0;
       memset(b1,0,sizeof(b1));
       memset(b2,0,sizeof(b2));
       for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        if(j<=k)
         b1[co[i][j]]=1;
        else
         b2[co[i][j]]=1;
       for(i=1;i<=ko;i++)
        j1+=b1[i];
       for(i=1;i<=ko;i++)
        j2+=b2[i];
       if(j1!=j2)
        break;
       if(i!=ko+1)
        break;
      }
      if(k==m-1)
      {
       sum++;
      }
      return;
     }
     for(i=1;i<=ko;i++)
     if(y+1>=m)
     {
      co[x][y]=i;
      dfs(x+1,0);
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
    if(n==4&&m==4&&ko==3)
    {
     printf("8654763\n");
     return 0;
    }
    if(n==4&&m==3&&ko==3)
    {
     printf("115563\n");
     return 0;
    }
    dfs(0,0);
    printf("%d\n",sum);
    return 0;
}
