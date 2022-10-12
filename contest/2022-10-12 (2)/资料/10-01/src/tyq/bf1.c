#include<stdio.h>
#include<stdlib.h>
long long a,b,sum,max;
long long f[1000][20];
int main()
{
    long long u,i,j,k,q=0;
    long long w;
    freopen("t2.in","r",stdin);
    freopen("t2.out","w",stdout);
    
    
    scanf("%I64d%I64d",&a,&b);
    if(a-b>10000)
    {
     printf("%d\n",a-b+1);
     return 0;
    }
    
    
    while(a!=0&&b!=0)
    {
     max=0;q=0;
     
     j=sqrt(b)+0.000001;
     for(w=sqrt(a-1)+1;w<=sqrt(b)+0.000001;w++)
     {
      q++;
      i=w*w;
      u=0;
      for(j=2;j<=sqrt(i);j++)
      {
       k=i;
       sum=0;
       while(k%j==0)
       {
        k/=j;
        sum++;
       }
       if(k==1)
       {
        u=1;
        break;
       }
      }
      if(u==0)
       sum=1;
      max+=sum;
     }
     printf("%I64d\n",max+b-a+1-q);
     scanf("%I64d%I64d",&a,&b);
    }
    return 0;
}
