#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[25][25],f[25][25][1<<14+1],m,x;
signed main()
{ 
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    }
    f[1][1][a[1][1]]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==1)
                continue;
            if(a[i][j]<0)
                continue;
            for(int k=0;k<=(1<<14)-1;k++)
            {
                f[i][j][k]=f[i-1][j][k^a[i][j]]+f[i][j-1][k^a[i][j]];
            }
            
        }
    }
    // cout<<f[1][1][a[1][1]]<<' '<<f[2][1][3]<<endl;
    cout<<f[n][m][x];
    return 0;
}