#include<bits/stdc++.h>
using namespace std;
int dp[200005];
int h[200005];
struct node
{
    int x,y;
}room[200005];
bool cmp(node a,node b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int q[200005],l=1,r=0,n,k,m;
int getdis(node a,node b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
int main()
{
    freopen("h.in","r",stdin);
    freopen("h.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>room[i].x>>room[i].y;
    }
    sort(room+1,room+m+1,cmp);
    int mini=1e9,ans=0;
    for(int i=1;i<=m;i++)
    {
        int cx=room[i].x;
        mini=min(mini,h[cx]);
        while(l<=r&&getdis(room[q[l]],(node){cx,mini})>k)
        {
            l++;
        }
        int k=l;
        while(k<=r&&getdis(room[q[k]],(node){cx,mini})+abs(room[i].y-min)>k)
        {
            k++;
        }
        ans+=(r-k+1);
        q[++r]=i;
    }
    cout<<ans;
    return 0;
}