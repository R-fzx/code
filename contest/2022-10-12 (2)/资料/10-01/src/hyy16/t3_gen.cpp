#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n,i,j,k,ok[205],map[205][205];

int main()
{
    freopen("t3.in","w",stdout);
    srand(time(NULL));
    n=rand()%20+1;
    printf("%d\n",n);
    for(i=1;i<=n;i++)
    {
       k=rand()%n+1;
       while (ok[k]==1) k=rand()%n+1;
       ok[k]=1;
       map[i][k]=1;
    }
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
       printf("%d ",map[i][j]);
       printf("\n");
    }
    return 0;
}
