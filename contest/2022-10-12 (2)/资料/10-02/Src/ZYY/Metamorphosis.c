#include <stdio.h>
#include <stdlib.h>

int x1,x2,x3,x4;

int main()
{
    freopen("Metamorphosis.in","r",stdin);
    freopen("Metamorphosis.out","w",stdout);
    
    scanf("%d%d%d%d",&x1,&x2,&x3,&x4);
    
    if (x1<0 && x3>0)
       printf("%.1lf\n",(double)x4);
    else
       printf("0.0\n");
    
    return 0;
}
