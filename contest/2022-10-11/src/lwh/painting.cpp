#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const long long Mo = 1000000007;
const long long MAXN = 2100;
long long f[MAXN][MAXN];
long long N,M,K,P2[MAXN];
long long sum[1000002],Div[2000000];
long long Ans = 0;
inline long long Pow(  long long a,  long long b)
{
//         if (a == 0) return 1;
      long long x = 1,y = a;
      while(b)
      {
              if (b & 1) x = x * y % Mo;
              b /= 2;
              y = y * y % Mo;
      }
      return x;
}
inline long long C(long long N,long long M)
{
         return sum[N] * Div[M] % Mo * Div[N - M] % Mo;
}
void Work()
{
     f[1][1] = 1;
     for(int i = 1;i <= N;i++)
      for(int j = 1;j <= min(N,K);j++)
      {
              if (i == 1 && j == 1) continue;
              f[i][j] += f[i - 1][j] * j % Mo;
              f[i][j] += f[i - 1][j - 1] * j % Mo;
              f[i][j] %= Mo;
      }
     sum[0] = 1;
     Div[0] = 1;
     for(int i = 1;i <= K;i++)
      sum[i] = sum[i - 1] * i % Mo;
     for(int i = 0;i <= N;i++)
     P2[i] = Pow(i,(M - 2) * N);
     for(int i = max(K - N - M - M,0ll);i <= K;i++)
     Div[i] = Pow(sum[i],Mo - 2);
     for(int i = 1;i <= N;i++)
     Div[i] = Pow(sum[i],Mo - 2);
     long long MinNK = min(N,K);
     for(int i = 0;i <= MinNK;i++)
      for(int j = 0;j <= i;j++)
      {
              long long key = C(K,j) * C(K - j,i - j) % Mo * C(K - i,i - j) % Mo;
              key = (key * f[N][i]) % Mo;
              key = (key * f[N][i]) % Mo;
              key = key * P2[j] % Mo;
              Ans = (Ans + key) % Mo;
//              printf("%I64d\n",key);
      }
      
}
void Init()
{
     scanf("%I64d %I64d %I64d",&N,&M,&K);
     if (M < 2)
     {
           printf("%I64d\n",Pow(K,N));
           exit(0);
     }
}
int main()
{
    freopen("painting.in","r",stdin);
    freopen("painting.out","w",stdout);
    Init();
    Work();
    printf("%I64d\n",Ans);
    return 0;
}
