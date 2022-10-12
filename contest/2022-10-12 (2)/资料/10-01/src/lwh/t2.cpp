#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long L,R;
unsigned long long Ans = 0;
long long f[70];
long long Pow(long long x,long long y,long long Limit)
{
     long long s = x,a = 1;
     while(y)
     {
             if (y & 1) 
             {
                   if (a > Limit / s) return 1;
                   a = a * s;
             }
             y /= 2;
             if (s > Limit / s && y) return 1;
             s = s * s;
             if (a > Limit) return 1;
     }
     return 0;
}
long long Work(long long x)
{
     memset(f,0,sizeof(f));
     f[1] = x;
     for(int i = 2;i <= 60;i++)
     {
             if (i == 4)
             i = 4;
             long long l = 1,r = 1000000000ll;
             while(l < r)
             {
                     long long mid = (l + r) / 2 + 1;
                     long long P = Pow(mid,i,x);
                     if (P) r = mid - 1;
                     else l = mid;
             }
             f[i] = l;
     }
     for(int i = 60;i >= 1;i--)
     {
             for(int j = i - 1;j >= 1;j--)
             if (i % j == 0)
             {
                     f[j] -= f[i];
             }
     }
     long long Ans = 0;
     for(int i = 1;i <= 60;i++)
     {
             Ans += f[i] * i;
     }
     return Ans;
}
void Init()
{
     while(1)
     {
             scanf("%I64d %I64d",&L,&R);
             if(L + R == 0) break;
             printf("%I64u\n",Work(R) - Work(L - 1));
     }
}
int main()
{
    freopen("t2.in","r",stdin);
    freopen("t2.out","w",stdout);
    Init();
    return 0;
}
