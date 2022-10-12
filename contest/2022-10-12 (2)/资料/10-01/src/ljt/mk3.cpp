#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("t3.in","w",stdout);
    int a[200][200];
    for (int i=1; i<=8; i++)
        for (int j=1; j<=8; j++)
        {
            if (i==j)
               a[i][j]=1;
            else
               a[i][j]=0;
            if (j>1) printf(" ");
            printf("%d",a[i][j]);
            if (j==8) printf("\n");
        }
    return 0;
}
