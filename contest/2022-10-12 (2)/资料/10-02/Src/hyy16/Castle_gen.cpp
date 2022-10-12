#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n=1000,m=500000,i;

int main()
{
    freopen("Castle.in","w",stdout);
    srand(time(NULL));
    printf("%d %d\n",n,m);
    for(i=1;i<=m;i++)
    printf("%d %d %d\n",rand()%n+1,rand()%n+1,rand()%10+1);
    return 0;
}
