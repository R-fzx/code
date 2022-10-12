#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
const double eps = 0.00000001;
using namespace std;
struct node
{
       double x,y;
};
double dou[600];
int x1,yy1,x2,yy2;
double Ans = 0;
void Init()
{
     scanf("%d %d %d %d",&x1,&yy1,&x2,&yy2);
}
double Dis(node a,node b)
{
       return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void Cal(node a,node b)
{
     double P = 0;
     if (fabs(a.x - b.x) < eps)
     {
                  if (a.x < x1 || a.x > x2) return;
                  if (a.y > b.y) swap(a,b);
                  if (a.y > yy2 || b.y < yy1) return;
                  P += min(b.y,(double)yy2) - max(a.y,(double)yy1);
     }
     else 
     {
                  if (a.y < yy1 || a.y > yy2) return;
                  if (a.x > b.x) swap(a,b);
                  if (a.x > x2 || b.x < x1) return;
                  P += min(b.x,(double)x2) - max(a.x,(double)x1);
     }    
     Ans += P;
}
int In(node a,node b,node c,node d)
{ 
    int x = floor(a.x - eps);
    int y = floor(a.y - eps);
    int xx = floor(b.x - eps);
    int yy = floor(b.y - eps);
    if (x != xx || y != yy) return 0;
    xx = floor(c.x - eps);
    yy = floor(c.y - eps);
    if (x != xx || y != yy) return 0;
    xx = floor(d.x - eps);
    yy = floor(d.y - eps);
    if (x != xx || y != yy) return 0;
    return 1;
}
void Dfs(node a,node b,int deep)
{
     double d = Dis(a,b) / 3.0;
     node c,d1,d2;
     if (deep >= 501) return;
//     printf("%d %lf %lf\n",deep,a.x,a.y);
     if (fabs(a.x - b.x) < eps)
     {
                  c.x = a.x;
                  c.y = (b.y - a.y) / 3.0 * 2 + a.y;
                  d1.x = c.x - d; d1.y = c.y;
                  d2.x = c.x + d; d2.y = c.y;
                  Cal(a,c);
                  if (In(c,b,d1,d2))
                  {
                                    int x = floor(c.x);
                                    int y = floor(c.y);
                                    if (x >= x1 && x < x2 && y >= yy1 && y < yy2)
                                    {
                                          double D = Dis(a,b);
                                          Ans += D * (500 - deep - 1) * 2.0 / 3 + D;
                                    }
                                    return;
                  }
                  Dfs(c,d1,deep + 1);
                  Dfs(c,d2,deep + 1);
                  Dfs(c,b,deep + 1);
     }
     else 
     {
                  c.y = a.y;
                  c.x = (b.x - a.x) / 3.0 * 2 + a.x;
                  d1.x = c.x; d1.y = c.y + d;
                  d2.x = c.x; d2.y = c.y - d;
                  Cal(a,c);
                  if (In(c,b,d1,d2))
                  {
                                    int x = floor(c.x);
                                    int y = floor(c.y);
                                    if (x >= x1 && x < x2 && y >= yy1 && y < yy2)
                                    {
                                          double D = Dis(a,b);
                                          Ans += D * (500 - deep - 1) * 2.0 / 3 + D;
                                    }
                                    return;
                  }
                  Dfs(c,d1,deep + 1);
                  Dfs(c,d2,deep + 1);
                  Dfs(c,b,deep + 1);
     }
}
int main()
{
    freopen("Metamorphosis.in","r",stdin);
    freopen("Metamorphosis.out","w",stdout);
    Init();
    node a,b;
    a.x = a.y = 0;
    b.x = 0,b.y = 81;
    Dfs(a,b,1);
    printf("%.1lf\n",Ans);
    return 0;
}
