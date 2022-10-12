#include <stdio.h>
#include <stdlib.h>
#define N 10000097

long long a,b;
long long hash[N+1]={0};

long long f(long long x)
{
     int i,m;
     long long j,sum=x;
     
     i=2;
     while (i*i<=x)
     {
           if (hash[i%N]==i)
              i++;
           else
           {
             j=i;
             m=0;
             while (j*i<=x)
             {
                 m++;
                 sum+=m;
                 j*=i;
                 hash[j%N]=j;
             }
             i++;
           }
     }
     
     return sum;
}


int main()
{
    freopen("t2.in","r",stdin);
    freopen("t2.out","w",stdout);
    
    scanf("%I64d%I64d",&a,&b);
    while (a!=0)
    {
          printf("%I64d\n",f(b)-f(a-1));
          scanf("%I64d%I64d",&a,&b);
    }
    
    return 0;
}
