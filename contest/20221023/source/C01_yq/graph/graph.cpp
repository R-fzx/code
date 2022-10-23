#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int n,a[maxn];
bool g[maxn][maxn],vis[maxn];
int ans;
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(!(a[i]&a[j]))g[i][j]=1;
        }
    }for(int i=1;i<=n;i++){
        if(!vis[i])vis[i]=1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&g[i][j])ans+=a[i],vis[j]=1;
        }
    }
    cout<<ans;
    return 0;
}