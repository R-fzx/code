#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define pi 3.1415926535897932384626433832795028841971693993
int main(){
    freopen ("�楤.in", "r", stdin);
    freopen ("�楤.out", "w", stdout);
    
    double r, p, ans, s, l, l2;
    scanf ("%lf%lf", &r, &p);
    s = r * r * p / 2;
    l = r * sin(p/2) * 2;
    l2 = p * r;
    ans = 2 * r * l / (3*l2);
    printf("%.6lf\n", ans);
    //system("pause");
    return 0;
}
//ans = 2*r*�ҳ�/��3*������ 
