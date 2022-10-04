#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
int f[maxn][maxn][maxn][maxn][2],dp[maxn],n,a[maxn],num[maxn];
int solve(int l,int r)
{
    // cout<<l<<' '<<r<<endl;
    memset(f,0,sizeof(f));
    memset(num,0,sizeof num);
    int n=1,sm=r-l+1;
    num[n]=1;
    for(int i=l+1;i<=r;i++)
        if(a[i]!=a[i-1])
            ++num[++n];
        else
            ++num[n];
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++)
        cout<<"###"<<num[i]<<endl;
    // cout<<"QWQ"<<endl;
    if(num[3]>=num[2]&&num[2]>=num[1])
    {
        dp[3]=dp[4]=dp[5]=num[1];
        cout<<num[1]<<endl;
    }
    for(int i=5;i<=n;i++)
    {
        if(num[i]>=num[i-1]&&num[i-4]>=num[i-3]&num[i-1]+num[i-3]>=num[i-2])
        {
            dp[i]=num[i-2];
            dp[i]+=dp[i-5];
        }
        else
        {
            dp[i]=dp[i-1];
        }
    }
    int s=dp[n];
    if(num[n-2]>=num[n-1]&&num[n-1]>=num[n])
        s=max(s,dp[n-3]+num[n]);
    cout<<s<<endl;
    return s;
    // for(int i=1;i<=n;i++)
    // { 
    //     f[i][i][0][0][0]=f[i][i][0][0][1]=1;
    // }
    // for(int len=2;len<=n;len++)
    //     for(int i=1;i<=n-len+1;i++)
    //     {
    //         int j=i+len-1;
    //         f[i][j][0][0][0]=f[i][j][0][0][1]=1;
    //         for(int k=0;k<=sm;k++)
    //             for(int l=0;l<=num[i];l++)
    //             {
    //                 for(int k1=0;k1<=k;k1++)
    //                 {
    //                     f[i][j][k][l][0]|=f[i+1][j][k1][max(k-k1+l,0)][0];
    //                 }
    //                 for(int k1=0;k1<=k;k1++)
    //                     f[i][j][k][l][1]|=f[i][j-1][k1][max(k-k1+l,0)][1];
    //                     // cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<f[i][j][k][l][0]<<' '<<f[i][j][k][l][0]<<endl;
    //             }
    //     }
    // int s=0;
    // for(int i=1;i<=n;i++)
    //     for(int j=0;j<=sm;j++)
    //         for(int l=0;l<=num[i];l++)
    //             if(f[i][n][j][l][0])
    //                 s=max(s,j);
    // for(int i=1;i<=n;i++)
    //     for(int j=0;j<=sm;j++)
    //         for(int l=0;l<=num[i];l++)
    //             if(f[1][i][j][l][1])
    //                 s=max(s,j);
    // return s;
}
int main()
{
    freopen("puppet.out","w",stdout);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        int l=1,r=1,ans=0;
        // for(int i=1;i<=n;i++)
        //     cout<<a[i]<<' ';
        // puts(""); 
        // int l=1,r=1,ans=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]-a[i-1]<=1)
                r=i;
            else
            {
                ans+=solve(l,r);
                l=r=i;
            }
        }
        ans+=solve(l,r);
        cout<<ans<<endl;
    }
    return 0;
}
/* 
15
9 10 9 9 5 6 9 6 9 1 5 7 4 5 10
2
15
7 8 9 5 10 1 3 5 3 1 1 1 7 2 6
3
15
9 10 10 8 1 5 9 6 5 3 9 3 6 1 6
3
15
6 3 3 4 7 5 7 10 5 1 8 8 6 7 4
2
15 6 1 3 7 7 8 5 10 6 10 8 2 5 1 5
*/