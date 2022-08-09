#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5,mod1=10000019,mod2=10000019,base1=1124,base2=1124;
int sum1[maxn],sum2[maxn],a[maxn],b[maxn],n,bk[mod1],bk1[mod2]; 
int check(int x)
{ 
    --x;
    if(x==0)
        return 1;
    memset(bk,0,sizeof bk);
    memset(bk1,0,sizeof bk1);
    for(int i=1;i<=n;i++)
    {
        sum1[i]=(sum1[i-1]*base1%mod1+b[i])%mod1;
        sum2[i]=(sum2[i-1]*base2%mod2+b[i])%mod2;
        // cout<<b[i]<<' '<<sum1[i]<<endl;
    }
    // cout<<endl;
    // puts("");
    int k1=1,k2=1;
    for(int i=1;i<=x;i++)   
        k1*=base1,k2*=base2;
    // cout<<x<<endl;
    // if(x==4)
    // for(int i=4;i<=n;i++)
    //     cout<<(sum1[i]-sum1[i-x]*k1%mod1+mod1)%mod1<<' '<<(sum2[i]-sum2[i-x]*k2%mod2+mod2)%mod2<<endl;
    // puts("");
    for(int i=n-x-1;i>=x+1;i--)
    {
        // cout<<i<<endl;
        int t1=(sum1[i+x+1]-sum1[i+1]*k1%mod1+mod1)%mod1,t2=(sum2[i+x+1]-sum2[i+1]*k2%mod2+mod2)%mod2;
        int x1=(sum1[i]-sum1[i-x]*k1%mod1+mod1)%mod1,x2=(sum2[i]-sum2[i-x]*k2%mod2+mod2)%mod2;
        // if(x==4)
        // cout<<i<<' '<<x1<<' '<<x2<<' '<<t1<<' '<<t2<<endl;
        bk[t1]=1,bk1[t2]=1;
        if(bk[x1]&&bk1[x2])
        {
            // if(x==2)
            //     cout<<i<<endl;
            return 1;
        }
    }
    return 0;
}
signed main()
{   
    freopen("snowman.in","r",stdin);
    freopen("snowman.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i]-a[i-1];
        b[i]+=100000000;
        // cout<<b[i]<<' ';
    }
    int l=1,r=n,ans=1;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(check(mid))
            l=mid+1,ans=mid;
        else
            r=mid-1;
    }
    cout<<ans;
    return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 10
*/