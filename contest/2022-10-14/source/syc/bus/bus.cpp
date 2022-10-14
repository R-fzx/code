#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int n,a[maxn],nx[maxn];
int s=0;
signed main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int j;
        for(j=i;j<=n&&a[j]>=a[i];++j);
        if(j==n+1)
            s+=a[i]*(n-i+1);
        else
            s+=a[i]*(j-i);
        // cout<<i<<' '<<j<<endl;
        i=j-1;
    }
    cout<<s;
    return 0;
}