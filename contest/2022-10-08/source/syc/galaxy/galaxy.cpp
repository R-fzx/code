#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
int n,m,k,X0,Y0,x[maxn],y[maxn],dx[10]={0,0,0,1,1,1,-1,-1,-1},dy[10]={0,1,-1,-1,1,0,-1,1,0},bk[maxn],a[maxn][maxn],tpx,tpy,id;
int check(int x,int y,int nx,int ny)
{
    for(int i=1;i<=8;i++)
    {
        int tx=x+dx[i],ty=y+dy[i],ttx=x-dx[i],tty=y-dy[i];
        if(ttx>n||ttx<1||tty>m||tty<1||a[ttx][tty]!=id&&a[ttx][tty]!=0)
            continue;
        if(tx>n||tx<1||ty>m||ty<1||a[tx][ty]!=id&&a[tx][ty]!=0)
            continue;
        // cout<<x<<' '<<y<<' '<<tx<<' '<<ty<<endl;
        if(tx%3==nx&&ty%3==ny)
        {
            tpx=(x-dx[i])%3;
            tpy=(y-dy[i])%3;
            return 1;
        }
    }
    // cout<<
    // cout<<x<<' '<<y<<' '<<nx<<' '<<ny<<endl;
    return 0;
}
int ans=0;
void dfs(int st,int nx,int ny)
{
    if(ans)
        return;
    if(st==k+1)
    {
        // cout<<"QWQ"<<nx<<' '<<ny<<endl;
        if(X0%3==nx&&Y0%3==ny)
            ans=1;
        return;
    }
    for(int i=1;i<=k;i++)
    {
        if(!bk[i]&&check(x[i],y[i],nx,ny))
        {
            bk[i]=1;
            dfs(st+1,tpx,tpy);
            bk[i]=0;
        }
    }
}
int main()
{
    freopen("galaxy.in","r",stdin);
    freopen("galaxy.out","w",stdout);
    while(cin>>k>>n>>m>>X0>>Y0)
    {
        ans=0;
        memset(a,0,sizeof(a));
        for(int i=1;i<=k;a[x[i]][y[i]]=i,i++)
            cin>>x[i]>>y[i];
        for(int i=1;i<=k;i++)
        {
            bk[i]=1;
            id=i;
            dfs(2,x[i]%3,y[i]%3);
            bk[i]=0;
        }
        puts(ans?"Yes":"No");
    }
    return 0;
}