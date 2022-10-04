#include <bits/stdc++.h>
using namespace std;
int a[55];
int t[105];
 int main()
{
    freopen("puppet.in","r",stdin);
    freopen("puppet.out","w",stdout);
    int n;
    while (cin >> n)
    {
        fill(t,t+104,0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            t[a[i]]++;
        }
        int maxn = 0;
        for(int i = 1;i <= 102;i++){
            if(t[i-1]+t[i+1]>t[i]){
                maxn = max(maxn,t[i]);
            }
        }
        cout << maxn<< endl;
    }
}
