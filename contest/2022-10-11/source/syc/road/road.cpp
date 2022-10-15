#include<bits/stdc++.h>
using namespace std;
const int maxn=205,maxm=5e4+5;
int n,m,fa[maxn],x[maxm],y[maxm],p,q,a[maxm],b[maxm],ta[maxn],tb[maxn],l,r;
int getfa(int x)
{
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int check()
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
        if(a[i]<=ta[l]&&b[i]<=tb[r])
        {
            int fx=getfa(x[i]),fy=getfa(y[i]);
            fa[fx]=fy;
        }
    int x=getfa(1);
    for(int i=2;i<=n;i++)
    {
        if(getfa(i)!=x)
            return 0;
    }
    return 1;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>p>>q;
    for(int i=1;i<=m;ta[i]=a[i],tb[i]=b[i],i++)
        cin>>x[i]>>y[i]>>a[i]>>b[i];
    sort(ta+1,ta+m+1);
    sort(tb+1,tb+m+1);
    r=m;
    int s=INT_MAX;
    for(int i=1;i<=m;i++)
    {
        l=i;
        while(r--)
        {
            if(!check())
                break;
        }
        ++r; 
        // cout<<l<<' '<<r<<endl;
        if(check())
            s=min(s,ta[l]*p+tb[r]*q);
    }
    if(!check())
        cout<<-1;
    else
        cout<<s;
    return 0;   
}