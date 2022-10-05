#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,b,c,d,X0,Y0,m,x,y,bk[5][5];
signed main()
{
    freopen("crop.in","r",stdin);
    freopen("crop.out","w",stdout);
    cin>>n>>a>>b>>c>>d>>X0>>Y0>>m;
    ++bk[X0%3][Y0%3];
    x=X0,y=Y0;
    for(int i=1;i<n;i++)
    {
        x=(a*x+b)%m;
        y=(c*y+d)%m;
        // cout<<x<<' '<<y<<endl;
        ++bk[x%3][y%3];
    }
    int s=0;
    for(int i=0;i<=2;i++)
        for(int j=0;j<=2;j++)
            for(int k=0;k<=2;k++)
                for(int l=0;l<=2;l++)
                    for(int m=0;m<=2;m++)
                        for(int n=0;n<=2;n++)
                        {

                            if((i+k+m)%3==0&&(j+l+n)%3==0)
                            {
                                // cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<m<<' '<<n<<' '<<bk[i][j]<<' '<<bk[k][l]<<' '<<bk[m][n]<<endl;
                                if(i==k&&j==l&&i==m&&j==n)
                                    s+=bk[i][j]*(bk[i][j]-1)*(bk[i][j]-2);
                                else if(i==k&&j==l)
                                    s+=bk[i][j]*(bk[i][j]-1)*bk[m][n];
                                else if(k==m&&l==n)
                                    s+=bk[i][j]*(bk[k][l]-1)*bk[k][l];
                                else
                                    s+=bk[i][j]*bk[k][l]*bk[m][n];
                            }
                        }
    cout<<s/6;
    return 0;
}
//200 2 0 2 1 1 2 11
