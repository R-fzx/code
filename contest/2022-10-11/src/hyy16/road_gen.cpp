#include <stdio.h>
#include <stdlib.h>

int n=20,m=1000,p=10000,q=10000,i;

int main()
{
    freopen("road.in","w",stdout);
    printf("%d %d\n%d %d\n",n,m,p,q);
    for(i=1;i<=m;i++)
       printf("%d %d %d %d\n",rand()%n+1,rand()%n+1,rand()%p+1,rand()%q+1);
    return 0;
}
