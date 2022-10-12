#include <stdio.h>
#include <math.h>

int n,sum=0,lim=0,a[205][205];

void find(int row,int step)
{
     int pos,p,cnt;
     if (row<lim)
     {
        pos=lim & (~row);
        while (pos)
        {
              p=pos & -pos;
              pos-=p;
              cnt=(int)log2((double)p)+1;
              if (a[cnt][step]==1)
                 continue;
              find(row+p,step+1);
        }
     }
     else
        sum++;
}

int main()
{
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            scanf("%d",&a[i][j]);
    lim=(1<<n)-1;
    find(0,1);
    printf("%d\n",sum);
    return 0;
}
