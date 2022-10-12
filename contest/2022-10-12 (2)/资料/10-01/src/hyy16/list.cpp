#include <stdio.h>
#include <stdlib.h>

int i,j;

int main()
{
    freopen("list.txt","w",stdout);
    printf("{0");
    for(i=1;i<=10007;i++)
    {
       for(j=1;j<=10007;j++)
       {
          if (i*j%10007==1) 
          {
             printf(",%d",j);
             break;
          }
       }
    }
    printf("}");
    return 0;
}
