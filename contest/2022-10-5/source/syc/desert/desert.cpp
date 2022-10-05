#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
char a[maxn][maxn];
struct node
{
    int x,y,di;
    bool operator<(node s2)const
    {
        return di>s2.di;
    }
};
int dx[10]={0,1,1,1,-1,-1,-1,0,0},dy[10]={0,0,-1,1,0,1,-1,1,-1},dis[maxn][maxn],bk[maxn][maxn];
int n;
int bfs(int x,int y)
{
    priority_queue<node> q;
    memset(dis,0x7f,sizeof(dis));
    dis[x][y]=0;
    q.push((node){x,y,0});
    while(!q.empty())
    {
        int t=0,x=q.top().x,y=q.top().y;
        // cout<<x<<
        if(a[x][y]=='*')
            return dis[x][y];
        q.pop();
        if(bk[x][y])
            continue;
        for(int i=1;i<=8;i++)
        {
            int tx=dx[i]+x,ty=dy[i]+y;
            if(tx>n||tx<1||ty>n||ty<1||a[tx][ty]=='X')
                continue;
            ++t;
        }
        int w=1;
        if(t==1)
            w=3;
        for(int i=1;i<=8;i++)
        {
            int tx=dx[i]+x,ty=dy[i]+y;
            if(tx>n||tx<1||ty>n||ty<1||a[tx][ty]=='X')
                continue;
            if(dis[tx][ty]>dis[x][y]+w)
                dis[tx][ty]=dis[x][y]+w,q.push((node){tx,ty,dis[x][y]});
        }
    }

}
int main()
{
    freopen("desert.in","r",stdin);
    freopen("desert.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]=='@')
            {
                cout<<bfs(i,j);
                return 0;
            }
        }   
    cout<<-1;
    return 0;
}