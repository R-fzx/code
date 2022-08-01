#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m;
struct node
{
    int v,nxt;
}e[maxn<<1];
int tot,head[maxn],d[maxn],f[maxn];
void add(int x,int y)
{
    e[++tot].v=y;
    e[tot].nxt=head[x];
    head[x]=tot;
}
int c[maxn];
int tuopu()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(!d[i])
        {
            q.push(i);
            f[i]=1;
        }  
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=head[x];i;i=e[i].nxt)
        {
            int v=e[i].v;
            f[v]+=f[x];
            --d[v];
            if(!d[v])
                q.push(v);
        }
    }
    int s=0;
    for(int i=1;i<=n;i++)
        if(!c[i])
            s+=f[i];
    return s;
}
int main()
{
    freopen("lyx.in","r",stdin);
    freopen("lyx.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        ++d[y],++c[x];
    }
    cout<<tuopu();
    return 0;
}