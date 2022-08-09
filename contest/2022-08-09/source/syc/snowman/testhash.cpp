#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5,mod1=10000019,mod2=19260817,base1=1111,base2=1431;
int sum1[maxn],sum2[maxn],b[maxn],bk[mod1],bk1[mod2]; 
int sum[100005],a[100005];
int n;
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]; 
    for(int i=1;i<=n;i++)
    {
        sum1[i]=(sum1[i-1]*base1%mod1+a[i])%mod1;
        sum2[i]=(sum2[i-1]*base2%mod2+a[i])%mod2;
        cout<<sum1[i]<<' '<<b[i]<<endl;;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<sum1[i]<<' '<<a[i]<<endl;;
    }
    return 0;
}
/*
10
100000001 100000001 100000001 100000001 100000001 100000001 100000001 100000001 100000001 100000001
*/