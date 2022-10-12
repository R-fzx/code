#include<stdio.h>
#include<iostream>
using namespace std;
double ans,x1,x2,y1,y2;
inline double get(double x) { if(x>0) return x; return 0; }
void find(double a,double x1,double y1,double x2,double y2,double z)
{
    if((y2<=0)||(y1>=z)||(x2*3+z<=0)||(x1*3>=z)) return;
    if((y1<=0)&&(y2>=z)&&(x1*3+z<=0)&&(x2*3>=z)) { ans+=z+z*(a-1)*2.0/3.0; return; }
    if((y1<=0)&&(y2>=z)&&(x1*3+z<=0)&&(x2==0)) { ans+=z+z*(a-1)/3.0; return; }
    if((y1<=0)&&(y2>=z)&&(x1==0)&&(x2*3>=z)) { ans+=z+z*(a-1)/3.0; return; }
    if((x1<=0)&&(x2>=0)) ans+=get(min(z*2.0/3.0,y2)-max(0.0,y1));
    find(a-1,y1-z*2.0/3.0,-x2,y2-z*2.0/3.0,-x1,z/3.0);
    find(a-1,x1,y1-z*2.0/3.0,x2,y2-z*2.0/3.0,z/3.0);
    find(a-1,z*2.0/3.0-y2,x1,z*2.0/3.0-y1,x2,z/3.0); return;
}
int main()
{
    freopen("Metamorphosis.in","r",stdin);
    freopen("Metamorphosis.out","w",stdout);
    int i,j;
    double k;
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    find(500.0,x1,y1,x2,y2,81.0);
    printf("%.1lf\n",ans);
    return 0;
}
