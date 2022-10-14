#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=4e5+5;
double ans=0;
struct node
{
    int x,y;
}a[maxn];
double dis(node x,node y)
{
    return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
// int x[maxn],y[maxn];
void solve(int l,int r)
{
    if(l==r)
        return;
    int mid=l+r>>1;
    // cout<<l<<' '<<r<<endl;
    solve(l,mid);
    solve(mid+1,r);
    for(int i=mid+1;i<=r;i++)
    {
        for(int j=mid;j>=l;j--)
            if(a[i].x-a[j].x>=ans)
                break;
            else
                ans=min(ans,dis(a[i],a[j]));
    }
}
int cmp(node s1,node s2)
{
    return s1.x<s2.x;
}
map<int,map<int,int> >bk;
signed main()
{
    freopen("dark.in","r",stdin);
    freopen("dark.out","w",stdout);
    int n;
    cin>>n;
    ans=maxn*2;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        if(bk[a[i].x][a[i].y])
            ans=0;
        bk[a[i].x][a[i].y]=1;
    }
    sort(a+1,a+n+1,cmp);
    // cout<<qwq<<endl;
    solve(1,n);
    printf("%.3lf",ans/1.0);
    return 0;
}
/*
3
0 0
0 1
1 0
*/
