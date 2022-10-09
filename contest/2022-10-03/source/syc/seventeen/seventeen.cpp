#include<bits/stdc++.h>
using namespace std;
int f[2][40500*2],x[205],y[205],n,sx=0,sy=0;
int main()
{   
    freopen("seventeen.in","r",stdin);
    freopen("seventeen.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;sx+=x[i],sy+=y[i],i++)
        cin>>x[i]>>y[i];
    memset(f,0x7f,sizeof (f));
    f[0][sx]=0;
    int p=0;
    for(int i=1;i<=n;i++)
    {
        p^=1;
        memset(f[p],0x7f,sizeof f[p]);
        for(int i=sx*2;i>=0;i--)
            f[p][i]=f[p^1][i];
        for(int j=sx*2-x[i];j>=0;j--)
            f[p][j+x[i]]=min(f[p][j+x[i]],x[i]*(j-sx)+f[p^1][j]);
        for(int j=sx*2;j>=x[i];j--)
            f[p][j-x[i]]=min(f[p][j-x[i]],(-x[i])*(j-sx)+f[p^1][j]);
    }
    int mi=INT_MAX;
    for(int i=0;i<=sx*2;i++)
        mi=min(mi,f[p][i]);
    // cout<<mi<<endl;
    memset(f,0x7f,sizeof (f));
    f[0][sy]=0; 
    p=0;
    for(int i=1;i<=n;i++)
    {
        p^=1;
        memset(f[p],0x7f,sizeof f[p]);
        for(int i=sy*2;i>=0;i--)
            f[p][i]=f[p^1][i];
        for(int j=sy*2-y[i];j>=0;j--)
        {
            // cout<<i<<endl;
            f[p][j+y[i]]=min(f[p][j+y[i]],y[i]*(j-sy)+f[p^1][j]);
        }
    // cout<<"QWQ"<<endl;
        for(int j=sy*2;j>=y[i];j--)
            f[p][j-y[i]]=min(f[p][j-y[i]],(-y[i])*(j-sy)+f[p^1][j]);
    }
    int qwq=INT_MAX;
    for(int i=0;i<=sy*2;i++)
        qwq=min(qwq,f[p][i]);
    printf("%.2lf",double(qwq+mi));
    return 0;
}