#include<bits/stdc++.h>
#define int long long
using namespace std;
double l,r;
double eps;
int check(int x)
{
    int tl=1,tr=x,ans=0;
    while(tl<=tr)
    {
        int mid=tl+tr>>1;
        if(double(mid)/double(x)<l)
            tl=mid+1;
        else
            ans=mid,tr=mid-1;
    }
    // cout<<x<<' '<<ans<<endl;
    return double(ans)/double(x)<r;
}
signed main()
{
    freopen("baseball.in","r",stdin);
    freopen("baseball.out","w",stdout);
    int n;
    while(cin>>n)
    {
        double x;
        cin>>x;
        double t=1;
        for(int i=1;i<=n;i++)
            t*=10;
        t*=10;
        t=5.0/t;

        for(int i=1;i<=1000;i++)
        {
            int l=1,r=i,ans=INT_MAX;
            while(l<=r)
            {
                int mid=l+r>>1;
                if(double(mid)/double(i)<x-t)
                    l=mid+1;
                else
                    r=mid-1,ans=mid;
            }
            if(ans==INT_MAX)
                continue;
            if(double(ans)/double(i)<=x+t)
            {
                cout<<i<<endl;
                break;
            }
        }
        // int t=1;
        // for(int i=1;i<=n;i++)
        //     t*=10;
        // x*=t;
        // eps/=t*100;
        // int tl=1,tr=1e16;
        // l=double(x*10-5)/double(t*10);
        // // lm=t*10;
        // r=double(x*10+5)/double(t*10);
        // // rm=t*10;
        // int ans=0;
        // // while(tl<=tr)
        // // {
        // //     int mid=tl+tr>>1;
        // //     cout<<mid<<endl;
        // //     if(check(mid))
        // //         tr=mid-1,ans=mid;
        // //     else
        // //         tl=mid+1;
        // // }
        // cout<<check(71)<<endl;
    }
    return 0;
}