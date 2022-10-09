#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("baseball.in","r",stdin);
    freopen("baseball.out","w",stdout);
        long long n;
    while (cin >> n)
    {

        long long m=0;
        string a;
        cin>> a;
        for(int i = 2;i < a.size();i++){
            m*=10;
            m+=(a[i]-'0');
        }
        long long p = 1;
        for (int i = 1; i <= n + 1; i++)
        {
            p *= 10;
        }
        m *= 10;
        //cout <<p << " "<< m << endl;
        long long x = m + 5, y = m - 5;
        //cout << x << " "<< y << endl;
        for (long long i = 1; i <= 1000; i++)
        {
            //cout << i << endl;
            long long e = i * p, xx = e / x, yy = e / y;
            if (e % x != 0)
            {
                xx = e / x + 1;
            }
            //cout << xx << " "<<yy << endl;
            if (xx <= yy)
            {
                cout << xx<< endl;
                break;
            }
        }
    }
}