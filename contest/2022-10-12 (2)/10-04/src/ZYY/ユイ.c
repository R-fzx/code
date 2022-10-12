#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Pi 3.1415926535897932384626433832795028841971693993

double r,a,string,arc;
double dis;

int main()
{
    freopen("•Ê•§.in","r",stdin);
    freopen("•Ê•§.out","w",stdout);
    
    scanf("%lf%lf",&r,&a);
    
    string=r*sin(a/2)*2;
    arc=r*a;
    
    dis=2*r*string/(3*arc);
    
    printf("%.6lf\n",dis);
    
    return 0;
}

//ans=2*r*œ“≥§/(3*ª°≥§) 
