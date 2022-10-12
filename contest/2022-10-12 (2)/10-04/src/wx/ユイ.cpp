#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
double R=0,D=0,Pi=3.1415926535897932384626433832795;
double S_shan,S_angle,S_extra,S_goal,xa,xb,ya,yb,a,h;
double get_shan()
{
       return ((R*R)/2.0)*D;
}
double get_angle()
{
       return R*R*sin(D)/2.0;
}
double cha(double x0,double y0,double xg,double yg,double xs,double ys)
{
    double x1=xg-x0,x2=xs-x0;
    double y1=yg-y0,y2=ys-y0;
    return x1*y2-x2*y1;
}
void work()
{
     int i,j,k;
     double l=-10020,r=10020,DD2=D/2.0;
     while(l<r)
     {
      double x=(l+r)/2.0;
      double y=x*tan(DD2);
      if(cha(xb,yb,x,y,xa,ya)>0)r=x-1E-7;
      else l=x+1E-7;
     }
     double ans=sqrt(l*l+(l*(tan(DD2))*(l*tan(DD2))));
     printf("%.6lf",ans);
     exit(0);
}
int main()
{
    freopen("ユイ.in","r",stdin);
    freopen("ユイ.out","w",stdout);
    int i,j,k;
    scanf("%lf%lf",&R,&D);
    if(D>Pi)
    D-=Pi;
    S_shan=get_shan();
    S_angle=get_angle();
    S_extra=S_shan-S_angle;
    
    S_goal=(S_shan/2.0);
    h=S_angle*2.0/R;
    a=S_goal*2.0/h;
    xa=a*cos(D);
    ya=xa*tan(D);
    xb=R;
    yb=0;
    if(S_angle>S_extra)
    {
    work();
    }
    else{
         printf("%.6lf",R/2.0);
         }
    return 0;
}
