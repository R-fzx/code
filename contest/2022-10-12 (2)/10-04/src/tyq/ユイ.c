#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double ss,r,thita,pi;
double check(double a)
{
       if(a>0)
        return a;
       return -a;
}
int deng(double a,double b)
{
    if(check(a-b)<0.000000001)
     return 1;
    return 0;
}
double get(double x)
{
       double angle,sss,s;
       angle=2*acos(x/r);
       sss=(angle/2)*r*r;
       s=sin(angle/2)*r*x;
       return sss-s;
}
double get1(double x)
{
       return x*sqrt(r*r-x*x);
}
int main()
{
    int i,j,sum=0;
    double ll,rr,bi;
    pi=3.1415926535897932384626;
    freopen("ユイ.in","r",stdin);
    freopen("ユイ.out","w",stdout);
    scanf("%lf%lf",&r,&thita);
    ss=(thita/2)*r*r;
    bi=(2*cos(thita/2)*sin(thita/2))/(thita/2);
    if(thita>pi-0.000000000000000001||bi<0.5)
    {
     ll=0;rr=r;
     
     while(!deng(ll,rr))
     {
      double mid=(ll+rr)/2;
      if(ss>2*get(mid))
       rr=mid;
      else
       ll=mid;
       sum++;
     }
    }
    else
    {
     ll=0;rr=r;
     
     while(!deng(ll,rr))
     {
      if(sum==12)
      i++,i--;
      double mid=(ll+rr)/2;
      if(ss>2*get1(mid))
       ll=mid;
      else
       rr=mid;
       sum++;
     }
    }
    printf("%.6lf",ll);
    return 0;
}
