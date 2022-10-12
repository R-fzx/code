#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e3+5,maxm=1e6+5;
struct node
{
    int v,nxt,w;
}e[maxm<<1];
int head[maxn],tot;
void add(int x,int y,int w)
{
    e[++tot].v=y;
    e[tot].nxt=head[x];
    head[x]=tot;
    e[tot].w=w;
}
int n,m;
struct diji
{
    int x,di;
    bool operator<(diji s2)const
    {
        return di>s2.di;
    }
};
priority_queue<diji> q;
int dis[maxn],bk[maxn],f[maxn];
void dij()
{
    memset(dis,0x7f,sizeof dis);
    dis[1]=0;
    f[1]=1;
    q.push((diji){1,0});
    while(!q.empty())
    {
        int x=q.top().x;
        q.pop();
        if(bk[x])
            continue;
        bk[x]=1;
        for(int i=head[x];i;i=e[i].nxt)
        {
            int v=e[i].v;
            if(dis[v]>dis[x]+e[i].w)
            {
                f[v]=1;
                dis[v]=dis[x]+e[i].w;
                q.push((diji){v,dis[v]});
            }
            else if(dis[v]==dis[x]+e[i].w)
                ++f[v];
        }
    }
    return;
}
signed main()
{
    freopen("Castle.in","r",stdin);
    freopen("Castle.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        add(x,y,w);
        add(y,x,w);
    }
    dij();
    int s=1;
    for(int i=1;i<=n;i++)
        s*=f[i];
    cout<<s;
    return 0;
}