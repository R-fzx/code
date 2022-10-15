#include<bits/stdc++.h>
using namespace std;
struct node{
    long long x,y,z;
};
long long n,m,p,q;
vector<node> v[205];
vector<long long> a,b;
bool vis[205];
void dfs(long long x,long long y,long long z){
    vis[x]=1;
    for(long long i = 0;i < v[x].size();i++){
        if(v[x][i].y <= y&&v[x][i].z <= z&&vis[v[x][i].x]==0){
            dfs(v[x][i].x,y,z);
        }
    }
}
bool check(long long x,long long y){
    fill(vis,vis+203,0);
    dfs(1,x,y);
    for(long long i = 1;i <= n;i++){
        if(vis[i]==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> p >> q;
    for(long long i = 1;i <= m;i++){
        long long x,y,z,vv;
        cin >> x >> y >> z >> vv;
        a.push_back(z);
        b.push_back(vv);
        node p;
        p.x=y,p.y=z,p.z=vv;
        v[x].push_back(p);
        p.x=x;
        v[y].push_back(p);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    long long maxn = 2e18;
    for(long long i = 0;i < a.size();i++){
        long long x = a[i];
        long long l = 0,r = b.size()-1;
        bool u  = 0;
        while(l <= r){
            long long mid=(l+r)/2;
            if(check(x,b[mid])==1){
                r = mid-1;
                u=1;
            }else{
                l =mid+1;
            }
        }
        if(u==1){
            maxn=min(maxn,a[i]*p+b[r+1]*q);
        }
    }
    if(maxn!=2e18){
        cout << maxn;
    }else{
        cout << -1;
    }
}
