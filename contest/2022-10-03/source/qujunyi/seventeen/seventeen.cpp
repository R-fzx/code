#include <bits/stdc++.h>
using namespace std;
struct node
{
    long long x, y;
} a[205];
long long dp[205];
int main()
{
  freopen("seventeen.in","r",stdin);
  freopen("seventeen.out","w",stdout);
    long long n;
    cin >> n;
    long long sumx = 0, sumy = 0,ans = 0;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        sumx += a[i].x, sumy += a[i].y;
        ans -= a[i].x*a[i].x+a[i].y*a[i].y;
    }
    dp[0] = 1;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = sumx / 2; j >= a[i].x; j--)
        {
            dp[j] |= dp[j - a[i].x];
        }
    }
    long long p = 0;
    for (long long i = 1; i <= sumx / 2; i++)
    {
        if (dp[i] == 1)
        {
            p = i;
        }
        dp[i] = 0;
    }
    ans += (sumx-2*p)*(sumx-2*p);
    dp[0] = 1;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = sumy / 2; j >= a[i].y; j--)
        {
            dp[j] |= dp[j - a[i].y];
        }
    }
    p = 0;
    for (long long i = 1; i <= sumy / 2; i++)
    {
        if (dp[i] == 1)
        {
            p = i;
        }
        dp[i] = 0;
    }
    ans += (sumy-2*p)*(sumy-2*p);
    printf("%.2lf",((double)ans)*0.5);
}