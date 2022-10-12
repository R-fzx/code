#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<map>
#define ll unsigned long long 
using namespace std;
ll A,B;
ll js=1;
int p=0;
inline ll find(ll x)
{
       int i,j,k,l;
       ll ans=0;
       ll m[101]={0};
       if(x<=1)
         return(0);
       m[1]=x-1;
       for(i=2;(ll)((ll)(1)<<(ll)(i))<=x;i++)
       {
         if(i==31)
           i=31;
         int dq=2;
         j=2;
         k=(ll)sqrt(x);
         if(i>=9)
           k=100;
         if(i>=18)
           k=10;
         while(j<k)
         {
           js=1;
           l=(j+k)/2;
           for(p=1;p<=i;p++)
           {
             js*=l;
             if((p<i && js>x/l)||js>x)
             {
               k=l-1;
               js=x+1;
               break;
               }
             }
           if(js==x)
           {
             dq=l;
             j=l;
             k=l;
             break;
             }
           if(js<x)
           {
             j=l+1;
             dq=l;
             }
           }
         js=1;
         for(p=1;p<=i;p++)
           {
             js*=j;
             if((p<i && js>x/j)||js>x)
               break;
             }
         if(p==i+1)
           dq=j;
         m[i]=dq-1;
         }
       l=i-1;
       for(i=l;i>=1;i--)
         for(j=2;i*j<=l;j++)
           m[i]-=m[i*j];
       for(i=1;i<=l;i++)
         ans+=i*m[i];
       return(ans);
       }
int main()
{
    ll i,j,k,l;
    freopen("t2.in","r",stdin);
    freopen("t2.out","w",stdout);
    while(1)
    {
      scanf("%I64d%I64d",&A,&B);
      if(A==0 && B==0)
        return(0);
      i=find(B);
      j=find(A-1);
      printf("%I64d\n",i-j);
      }
    return(0);
}
