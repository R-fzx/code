#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
int n,k,l,n1,n2,v2[maxn],v[maxn];
double a[maxn],f[maxn][maxn],g[maxn][3005][maxn],a1[maxn],a2[maxn],v1[maxn];
int main()
{
    // freopen("guard.in","r",stdin);
    // freopen("guard.out","w",stdout);
    cin>>n>>l>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]/=100.0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        if(v[i]==-1)    
            a1[++n1]=a[i],v1[n1]=v[i];
        else
            a2[++n2]=a[i],v2[n2]=v[i];
    }
    f[0][0]=1;
    for(int i=1;i<=n1;i++)
        for(int j=0;j<=i;j++)
            f[i][j]=f[i-1][j]*(1-a1[i])+a1[i]*f[i-1][j-1];
    g[0][k][0]=1;
    for(int i=1;i<=n2;i++)
    {
        for(int j=0;j<=7;j++)
            for(int k=0;k<=i;k++)
            {
                if(j>=v2[i]&&k>=1)
                    g[i][j][k]=a2[i]*g[i-1][j-v2[i]][k-1]+(1-a2[i])*g[i-1][j][k];
                else
                    g[i][j][k]=(1-a[i])*g[i-1][j][k];
                cout<<i<<' '<<j<<' '<<k<<' '<<g[i][j][k]<<endl;
            }
    }
    double s=0;
    for(int i=0;i<=n1;i++)
    {
        for(int j=i;j<=3000;j++)
            for(int k=max(l-i,0);k<=n2;k++)
                s+=f[n1][i]*g[n2][j][k];
    }
    printf("%.6lf",s);
    return 0;
}