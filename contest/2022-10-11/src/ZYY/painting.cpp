#include <stdio.h>
#include <stdlib.h>
int n,m,k;

int mi(int a,int b)
{
    int s=1,i;
    
    for (i=1; i<=b; i++)
        s*=a;
    
    return s;
}

int main()
{
    freopen("painting.in","r",stdin);
    freopen("painting.out","w",stdout);
    
    scanf("%d%d%d",&n,&m,&k);
    
    if (n==1)
    {
       if (m!=2)
          printf("%d\n",k);
       else
           printf("%d\n",k*k);
    }
    else
        if (n==2)
        {
           if (m==1)
              printf("d\n",k*k);
           else
           if (m==2)
              printf("d\n",k*k+k*(k-1)*2);
           else
           if (m==3)
              printf("%d\n",k+k*(k-1)*2+k*(k-1)*2*mi(2,(m-2)*2));
           else
           if (m==4)
              printf("%d\n",k+k*(k-1)*4+k*(k-1)*2*mi(2,(m-2)*2));
        }
    return 0;
}
