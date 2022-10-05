#include <bits/stdc++.h>
using namespace std;
long long a[805], b[805];
long long cmp(long long x, long long y)
{
    return x > y;
}
int main()
{
    freopen("crop.in", "r", stdin);
    freopen("crop.out", "w", stdout);
    long long n;
    cin >> n;
    if (n < 3 || n > 1000)
    {
        cout << 0;
    }
    else
    {
        cout << n * (n - 1) * (n - 2) / 6 << endl;
    }
}