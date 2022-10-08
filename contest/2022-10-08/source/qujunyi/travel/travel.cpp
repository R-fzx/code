#include<bits/stdc++.h>
using namespace std;
vector<int> v[205];
bool b[205],bb[205];
void dfs(int x){
    bb[x]=1;
    for(int i = 0;i < v[x].size();i++){
            dfs(v[x][i]);
    }
}
bool p = 0;
int sum = 0;
void DFS(int x){
    if(b[x]==1){
        p = 1;
        return;
    }
    for(int i = 0;i < v[x].size();i++){
            DFS(v[x][i]);
    }
}
vector<int> vv;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    cin >> n >> m;
    while(m--){
        int x,y;
        cin>> x >> y;
        v[x].push_back(y);
    }
    for(int i = 1;i <= n;i++){
        p=0;
        DFS(i);
        if(p==0&&bb[i]==0){
            b[i]=1;
            sum++;
            dfs(i);
        }
    }
    cout << sum<< endl;
    for(int i = 1;i <= n;i++){
        if(b[i]==1){
            cout << i <<" ";
        }
    }
}