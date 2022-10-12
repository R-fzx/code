#include <stdio.h>
#include <stdlib.h>

int n,i,c[1005],f[205][1005];

void add(int a,int b);
void cheng(int x);
void copy(int x);

int main()
{
    freopen("t3.in","r",stdin); freopen("t3.out","w",stdout);
    scanf("%d",&n);
    f[2][0]=f[2][1]=1;
    for(i=3;i<=n;i++)
    {
       add(i-1,i-2);
       cheng(i-1);
       copy(i);
    }
    printf("%d",f[n][f[n][0]]);
    for(i=f[n][0]-1;i>=1;i--)
    {
       if (f[n][i]>999) printf("%d",f[n][i]);
       else if (f[n][i]>99) printf("0%d",f[n][i]);
       else if (f[n][i]>9) printf("00%d",f[n][i]);
       else printf("000%d",f[n][i]);
       //printf("%d",f[n][i]);
    }
    printf("\n");
    return 0;
}

void add(int a,int b)
{
     int i,max;
     if (f[a][0]>f[b][0]) max=f[a][0];
     else max=f[b][0];
     for(i=1;i<=max;i++)
     c[i]=f[a][i]+f[b][i];
     c[0]=max;
     for(i=1;i<=max;i++)
     if (c[i]>9999) c[i+1]+=c[i]/10000,c[i]%=10000;
     i=max+1;
     while (c[i]>0)
     {
           if (c[i]>9999) c[i+1]+=c[i]/10000,c[i]%=10000;
           i++;
     }
     c[0]=i-1;
     return;
}

void cheng(int x)
{
     int i;
     for(i=1;i<=c[0];i++) c[i]*=x;
     for(i=1;i<=c[0];i++)
     if (c[i]>9999) c[i+1]+=c[i]/10000,c[i]%=10000;
     i=c[0]+1;
     while (c[i]>0)
     {
           if (c[i]>9999) c[i+1]+=c[i]/10000,c[i]%=10000;
           i++;
     }
     c[0]=i-1;
     return;
}

void copy(int x)
{
     int i;
     f[x][0]=c[0];
     for(i=1;i<=c[0];i++)
     f[x][i]=c[i],c[i]=0;
     c[0]=0;
     return;
}
