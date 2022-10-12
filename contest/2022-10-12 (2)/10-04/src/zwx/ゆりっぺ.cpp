#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
    long long sa,sb,sc;   
};
node folk[500005];
long long na,nb,nc,i,j,k,sum,n,sum2;
inline void init()
{
     scanf("%ld%ld%ld%ld",&n,&na,&nb,&nc);
     for (i=1;i<=n;i++)
      scanf("%ld%ld%ld",&folk[i].sa,&folk[i].sb,&folk[i].sc);
}
inline void qiu()
{
       return ;
         
}
int main()
{
      freopen("ゆりっぺ.in","r",stdin);
      freopen("ゆりっぺ.out","w",stdout);
      init();
      if ((na+nb+nc)>n)
      {
         printf("I am a godlike cowcowcow");
         return 0;
      }
      qiu();
      return 0;
}
