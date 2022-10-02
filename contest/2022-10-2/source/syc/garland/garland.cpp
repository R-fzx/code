#include<bits/stdc++.h>
#define int long long
using namespace std; 
int l[505][505],a[505][505],r[505][505],n,mi,ma;
struct node
{
    int x,y,k;
    bool operator<(node s1)const
    {
        return k<s1.k;
    }
};
priority_queue<node> q; 
signed main()
{
    freopen("garland.in","r",stdin);
    freopen("garland.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>l[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>r[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            l[i][j]=l[j][i]=max(l[i][j],l[j][i]);
            r[i][j]=r[j][i]=min(r[i][j],r[j][i]);
            mi+=l[i][j];
            ma+=r[i][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            q.push((node){i,j,a[i][j]});
    int s=0;
    while(!q.empty())
    {
        node qwq=q.top();
        q.pop();
        if(qwq.k==0)
            break;
        int x=0,ans=min(abs(mi),(r[qwq.x][qwq.y]-l[qwq.x][qwq.y]));
        mi+=ans; 
        ma+=ans;
        s+=qwq.k*(l[qwq.x][qwq.y]+ans);
        
    }
    cout<<s<<endl;
    return 0;
}