#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,m,k,h[maxn],vis[1010][1010],ans;
struct E{
    int x,y;
}r[maxn];
bool cmp(E x,E y){
    return x.x<y.x;
}
bool dfs(int x,int y,int fx,int fy,int dis){
    if(vis[x][y])return 0;
    vis[x][y]=1;
    if(x==fx&&y==fy&&dis<=k)return 1;
    if(x+1<=n&&y<=h[x+1])if(dfs(x+1,y,fx,fy,dis+1))return 1;
    if(y+1<=h[x])if(dfs(x,y+1,fx,fy,dis+1))return 1;
    if(y>0)if(dfs(x,y-1,fx,fy,dis+1))return 1;
    return 0;
}   
int main(){
    freopen("h.in","r",stdin);
    freopen("h.out","w",stdout);
    ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>h[i];
    cin>>m;
    for(int i=1;i<=m;i++)cin>>r[i].x>>r[i].y;
    sort(r+1,r+m+1,cmp);
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            memset(vis,0,sizeof(vis));
            int x=r[i].x,y=r[i].y,tx=r[j].x,ty=r[j].y;
            if(dfs(x,y,tx,ty,0))ans++;
        }
    }
    cout<<ans;
    return 0;
}
