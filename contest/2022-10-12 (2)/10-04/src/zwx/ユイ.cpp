#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
double r,p,dis,sins;
inline void init()
{
       scanf("%lf%lf",&r,&p);
}
inline void suan()
{
       sins=sin(p/2);
       //sins=sins*sins;
       dis=4*r*sins;
       dis=dis/3;
       dis=dis/p;
       printf("%.6lf",dis);
}
int main()
{
    freopen("�楤.in","r",stdin);
    freopen("�楤.out","w",stdout);
    init();
    suan();
}
