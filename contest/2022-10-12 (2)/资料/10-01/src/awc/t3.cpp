#include <stdio.h>
#include <stdlib.h>
int a[300][700],n,b[700];

void init()
{
     int i,j,k;
     scanf("%d",&n);
     for (i=0;i<n;++i) 
       for (j=0;j<n;++j)
         scanf("%d",&k);
}
void gj(int q[],int w[],int e[])
{
     int i,t;
     t=0;
     for (i=0;i<600;++i)
     {
         e[i]=q[i]+w[i]+t;
         t=e[i]/10;
         e[i]=e[i]%10;         
     }    
}
void work()
{
     int i,j;
     for (i=3;i<=n;++i)
     {
         gj(a[i-1],a[i-2],b);
         for (j=1;j<=i-1;++j)
           gj(b,a[i],a[i]);
     }
}
int main()
{
    int i;
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    a[1][0]=0;
    a[2][0]=1;
    init();
    work();
    for (i=600;i>0;--i)
      if (a[n][i]!=0) break;
    for (;i>=0;--i)
      printf("%d",a[n][i]);
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
