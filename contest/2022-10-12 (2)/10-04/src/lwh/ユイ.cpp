#include <cmath>
#include <cstdio>
#include <cstdlib>
double R,P;
void Init()
{
     scanf("%lf %lf",&R,&P);
}
double Work(double P)
{
     if (P < 1e-8)
     {
           return R * 2 / 3;
     }
     double Tmp = Work(P / 2);
     return Tmp * cos(P / 4);
}
int main()
{
    freopen("ユイ.in","r",stdin);
    freopen("ユイ.out","w",stdout);
    Init();
    printf("%.6lf",Work(P));
    return 0;
}
