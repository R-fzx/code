#include<stdio.h>
#include<stdlib.h>
#include<string.h>
unsigned long long a,b,ans,oo=1,mb[188],ma[188],maxk=60;
unsigned long long Big(unsigned long long x,unsigned long long k,unsigned long long goal)
{
         int i;
         unsigned long long tmp=1;
         for(i=1;i<=k;i++)
         {
          tmp*=x;
          if(tmp>goal)return 0;
         }
         if(tmp<=goal&&tmp>0)return 1;
         else return 0;
}
unsigned long long get_ans(unsigned long long x,int K)
{
     unsigned long long i=1,j=x;
     while(i<=j)
     {
      unsigned long long mid=(i+j)/2;
      if(Big(mid,K,x))i=mid+1;
      else j=mid-1;
     }
     while(!Big(i,K,x))i--;
     return i;
}
int main()
{
    freopen("t2.in","r",stdin);
    freopen("t2.out","w",stdout);
    int i,j,k;
    
    for(i=1;i<=maxk;i++)
    oo*=2;
    while(1)
{
    scanf("%I64u%I64u",&a,&b);
    if(a==0)break;
    ans=0;
    memset(mb,0,sizeof(mb));
    memset(ma,0,sizeof(ma));
    for(i=maxk;i>=1;i--)
    {
     mb[i]=get_ans(b,i);
     for(j=i+i;j<=maxk;j+=i)
     mb[i]-=mb[j];
     ans+=mb[i]*i;
     
     if(i==2)
     i=2;
     ma[i]=get_ans(a-1,i);
     for(j=i+i;j<=maxk;j+=i)
     ma[i]-=ma[j];
     ans-=ma[i]*i;
     //ans+=i;
    }
    printf("%I64u\n",ans);
}
    return 0;
}
