#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
class People
{
      public : 
      double a,b;
}p[10];
int N,K;
double A;
double Ans = 0,w;
void Init()
{
     scanf("%d %d %lf",&N,&K,&A);
     for(int i = 1;i <= N;i++)
     {
             scanf("%lf %lf",&p[i].a,&p[i].b);
     }
}
void Cal(int deep,double g,double ai,int c)
{
     if (deep == N + 1)
     {
              if (c > N / 2) w += g;
              else 
              w += g * (A / (double)(A + ai));
              return;
     }
     // no choose
     Cal(deep + 1,g * ( (100.0 - p[deep].b) / 100.0),ai + p[deep].a,c);
     //choose
     Cal(deep + 1,g * (p[deep].b / 100.0),ai,c + 1);
}
void Dfs_K(int deep,int K)
{
     /*
     if (deep == N)
     {
              double y = p[deep].b;
              p[deep].b = min(p[deep].b +  K * 10,100.0);
              Dfs_K(deep + 1,0);
              p[deep].b = y;
     }
     */
     if (deep == N + 1)
     {
              w = 0;
              Cal(1,1,0,0);
              if (w > Ans) Ans = w;
              return;
     }
     for(int i = 0;i <= K;i++)
     {
             if (p[deep].b + i * 10 > 100) break;
             p[deep].b += i * 10;
             Dfs_K(deep + 1,K - i);
             p[deep].b -= i * 10;
     }
}
int main()
{
    freopen("assembly.in","r",stdin);
    freopen("assembly.out","w",stdout);
    Init();
    Dfs_K(1,K);
    printf("%lf",Ans);
    return 0;
}
