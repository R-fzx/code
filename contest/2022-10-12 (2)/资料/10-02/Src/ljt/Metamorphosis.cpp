#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
    freopen("Metamorphosis.in","r",stdin);
    freopen("Metamorphosis.out","w",stdout);
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if (max(y1,y2)<=0)
    {
       printf("0.0\n");
       return 0;
    }
    if (0<=min(y1,y2) && min(y1,y2)<=55 && 0<=max(y1,y2) && max(y1,y2)<=55)
    {
       if (min(x1,x2)<=0 && max(x1,x2)>=0)
       {
          printf("%d.0\n",y2-y1);
          return 0;
       }
       else if (max(x1,x2)<0 || min(x1,x2)>0)
       {
          printf("0.0\n");
          return 0;
       }
    }
    if (min(x1,x2)<=-27 && max(x1,x2)>=27 && min(y1,y2)<=45 && max(y1,y2)>=81)
    {
       int cnt = 27 * 1001 - max(0,min(y1,y2));
       printf("%d.0\n",cnt);
    }
    return 0;
}
