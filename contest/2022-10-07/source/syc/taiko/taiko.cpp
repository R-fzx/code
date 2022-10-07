#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+5;
struct node
{
    int v,nxt;
}e[maxn<<2];
int n,a[maxn],tot,head[maxn];
void add(int x,int y)
{
    e[++tot].v=y;
    e[tot].nxt=head[x];
    head[x]=tot;
}
int bk[maxn];
stack<int> q;
void dfs(int x)
{
    bk[x]=1;
    for(int i=head[x];i;i=e[i].nxt)
    {
        int v=e[i].v;
        // cout<<x<<' '<<v<<endl;
        if(!bk[v])
            dfs(v);
    }
    q.push(x);
}
int main()
{   
    freopen("taiko.in","r",stdin);
    freopen("taiko.out","w",stdout);
    cin>>n;
    for(int i=0;i<(1<<n);i++)
    {
        if((((i<<1)+1)&(1<<n)-1)!=i)
            add(i,((i<<1)+1)&(1<<n)-1);
        if(i!=(i<<1)&(1<<n)-1)
            add(i,(i<<1)&(1<<n)-1);
    }
    dfs(0);
    cout<<(1<<n)<<' ';
    int tp=0;
    for(int i=1;i<=n;i++)
        cout<<0;
    tp=n;
    q.pop();
    while(!q.empty())
    {
        if(tp<(1<<n))
            cout<<(q.top()&1);
        ++tp;
        q.pop();
    }
    return 0;
}