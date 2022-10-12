#include<stdio.h>
#include<stdlib.h>
int n,a[10000],l,j,k,ii,jj,kk;
inline void plus(int x)
{
    int i;
    a[1]++;
    for (i=1;i<=l;i++)
    {
        if (a[i]>=10000)
        {
           a[i+1]++;
           a[i]=a[i]-10000;
        }
    }
    if (a[l+1]!=0)
      l++;
    return;
       
}
inline void minus(int x)
{
      int i;
      a[1]--;
      for (i=1;i<=l;i++)
      {
          if (a[i]<0)
          {
             a[i]+=10000;
             a[i+1]--;
          }
      }
      if (!a[l])
        l--;
      return;
} 
inline void mul(int x)
{
     int i;
     for (i=1;i<=l;i++)
       a[i]=a[i]*x;
     for (i=1;i<=l;i++)
     {
       a[i+1]+=a[i]/10000;
       a[i]=a[i]%10000;
     }
     if (a[l+1]!=0)
       l++;
     return;   
}
int main()
{
    int i,j;  
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    scanf("%d",&n);
    if (n==1)
    {
       printf("0\n");
       return 0;
    }
    l=1;
    a[1]=1;
    for (i=3;i<=n;i++)
    {
        mul(i);
        if (i%2==1)
          minus(i);
        else plus(i);
    }
    printf("%d",a[l]);
    for (i=l-1;i>0;i--)
      printf("%04d",a[i]);
    printf("\n");
    return 0;
    
}
