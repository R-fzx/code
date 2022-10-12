#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int dat_Len = 1000;
const int Mod = 10000;
class big_num
{
      public :
      int dat[dat_Len];
      big_num()
      {
               memset(dat,0,sizeof(dat));
               dat[0] = 1;
      }
      friend big_num operator +(big_num a,big_num b)
      {
             big_num res;
             int Len = max(a.dat[0],b.dat[0]);
             for(int i = 1;i <= Len;i++)
             {
                     res.dat[i] += a.dat[i] + b.dat[i];
                     if (res.dat[i] >= Mod)
                     {
                                    res.dat[i + 1] ++;
                                    res.dat[i] -= Mod;
                     }
             }
             if (res.dat[Len + 1]) Len++;
             res.dat[0] = Len;
             return res;
      }
      friend big_num operator *(big_num a,int b)
      {
             big_num res;
             int Len = a.dat[0];
             for(int i = 1;i <= Len;i++)
             {
                     res.dat[i] += a.dat[i] * b;
                     if (res.dat[i] >= Mod)
                     {
                                res.dat[i + 1] += res.dat[i] / Mod;
                                res.dat[i] %= Mod;
                     }
             }
             res.dat[0] = Len;
             for(res.dat[0]++;res.dat[ res.dat[0] ];res.dat[0]++)
             {
                       res.dat[ res.dat[0] + 1] += res.dat[ res.dat[0] ] / Mod;
                       res.dat[ res.dat[0] ] %= Mod;
             }
             res.dat[0]--;
             return res;
      }
      friend big_num operator -(big_num a,big_num b)
      {
             big_num res;
             int Len = a.dat[0];
             for(int i = 1;i <= Len;i++)
             {
              res.dat[i] += a.dat[i] - b.dat[i];
              if (res.dat[i] < 0)
              {
                             res.dat[i + 1]--;
                             res.dat[i] += Mod;
              }
             }
             res.dat[0] = Len;
             for(;res.dat[ res.dat[0] ] == 0 && res.dat[0] > 1;res.dat[0]--);
             return res;
      }
      void print()
      {
           printf("%d",dat[ dat[0] ]);
           for(int i = dat[0] - 1;i >= 1;i--)
           printf("%04d",dat[i]);
           printf("\n");
      }
};
int N;
big_num f[2000];
void Init()
{
     scanf("%d",&N);
}
int main()
{
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    Init();
    big_num Ans;
    f[1].dat[1] = 1;
    f[2].dat[1] = 2;
    for(int i = 3;i <= N - 1;i++)
    {
            f[i] = (f[i - 1] + f[i - 2]) * i;
    }
    f[N - 1].print();
    return 0;
}
