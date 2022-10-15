#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e3+5,maxk=1e6+5,mod=1e9+7;
int f[maxk],ny[maxk],n,m,k;
int ksm(int x,int y)
{
    int s=1;
    while(y)
    {
        if(y&1)
            s*=x,s%=mod;
        x*=x;
        x%=mod;
        y>>=1;
    }
    return s;
}
int C(int n,int m)
{
    return f[n]%mod*ny[m]%mod*ny[n-m]%mod;
}
int p[maxn];
signed main()
{
    freopen("painting.in","r",stdin);
    freopen("painting.out","w",stdout);
    cin>>n>>m>>k;
    f[0]=1;
    ny[0]=1;
    for(int i=1;i<=maxk-1;i++)
        f[i]=f[i-1]*i%mod,ny[i]=ksm(f[i],mod-2);
    int s=0;
    for(int i=1;i<=min(n,k);i++)
    {
        int ts=0;
        for(int j=0;j<i;j++) 
            ts+=ksm(-1,j)*ksm(i-j,n)%mod*C(i,j)%mod,ts%=mod;  
        p[i]=ts;
    } 
    for(int i=1;i<=min(n,k);i++)
        for(int j=0;j<=i;j++)
        {       
            if(i*2-j>k)
                continue;
            // cout<<i<<' '<<j<<' '<<C(k,j)%mod*C(k-j,i-j)%mod*C(k-i,i-j)<<' '<<p[i]<<' '<<ksm(j,(m-2)*n)<<endl;
            s+=p[i]*p[i]%mod*C(k,j)%mod*C(k-j,i-j)%mod*C(k-i,i-j)%mod*ksm(j,(m-2)*n)%mod;
            s%=mod;
        }
    cout<<s;
    return 0;
}