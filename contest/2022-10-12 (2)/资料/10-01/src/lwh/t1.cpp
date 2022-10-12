#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std ; 
#define MAXN 1005
const int Mod = 10007;
int N;
int f[MAXN][MAXN];
int father[MAXN];
int Hash[MAXN];
int Path[MAXN];
int Child[MAXN][2],Size[MAXN];
long long Ni[MAXN],Dp[MAXN];
long long Ans = 0;
void Link(int x,int y)
{
     f[x][++f[x][0]] = y;
}
long long Pow(long long x,long long y)
{
     if (y == 0) return 1;
     if (y == 1) return x;
     long long P = Pow(x,y/2);
     if (y & 1) return P * P % Mod * x % Mod;
     return P * P % Mod;
}
void Init()
{
     scanf("%d",&N);
     for(int i = 1;i <= N;i++)
     {
             f[i][0] = 0;
             Child[i][0] = Child[i][1] = 0;
     }
     for(int i = 1;i <= N;i++)
     {
             int Num = 0;
             int last = 0;
             scanf("%d",&Num);
             if (Num == 0) continue;
             for(int j = 1;j <= Num;j++)
             {
                     int x;
                     scanf("%d",&x);
                     Link(i,x);
             }
     }
}
void Dfs(int x)
{
     if (f[x][0] == 0) return;
     for(int i = 1;i <= f[x][0];i++)
     Dfs(f[x][i]);
     Child[x][0] = f[x][1];
     int Now = Child[x][0];
     for(int i = 2;i <= f[x][0];i++)
     {
      Child[Now][1] = f[x][i];
      Now = f[x][i];
     }
}
long long C(long long n,long long m)
{
     long long P = 1;
     for(int i = m + 1;i <= n;i++)
     {
             P = P * i % Mod;
             P = P * Ni[i - m] % Mod;
     }
     return P;
}
void DD(int x)
{
     if (x == 0) return;
     int Lc = Child[x][0],Rc = Child[x][1];
     DD(Lc); DD(Rc);
     if (Lc == 0 && Rc == 0)
     {
            Dp[x] = 1;
            Size[x] = 1;
            return;
     }
     if (Lc == 0)
     {
            Dp[x] = Dp[Rc];
            Size[x] = Size[Rc] + 1;
            return;
     }
     else
     if (Rc == 0)
     {
            Dp[x] = Dp[Lc];
            Size[x] = Size[Lc] + 1;
            return;
     }
     
     long long P = C(Size[Rc] + Size[Lc],Size[Rc]);
     Dp[x] = (Dp[Rc] * Dp[Lc]) % Mod * P % Mod;
     Size[x] = Size[Rc] + Size[Lc] + 1;
}
int main()
{
    freopen("t1.in","r",stdin);
    freopen("t1.out","w",stdout);
    int T;
    for(int i = 1;i <= 1001;i++)
    {
            Ni[i] = Pow(i,Mod - 2);
    }
    scanf("%d",&T);
    for(int i = 1;i <= T;i++)
    {
     Init();
     Dfs(1);
//     for(int j = 1;j <= N;j++)
//     printf("%d %d\n",Child[j][0],Child[j][1]);
     DD(1);
     printf("%I64d\n",Dp[1]);
    }
    return 0;
}
