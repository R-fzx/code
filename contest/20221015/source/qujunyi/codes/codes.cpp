#include <bits/stdc++.h>
using namespace std;
int n;
string a[25];
bool b[25];
bool bb[25];
vector<string> v,vv;
map<string,bool> m;
bool cmp(string x,string y){
  if(x.size()==y.size()){
    return x< y;
  }
  return x.size()< y.size();
}
void Dfs(int x,string u){
  if(x==v.size()+1){
    if(m[u]==1){
      vv.push_back(u);
    }
    m[u]=1;
    return;
  }
  for(int i = 0;i < v.size();i++){
    if(!bb[i]){
      string f = u+v[i];
      bb[i]=1;
      Dfs(x+1,f);
      bb[i]=0;
    }
  }
}
void dfs(int x) {
  if(x==n+1){ 
    v.clear();
    for(int i = 1;i <= n;i++){
      if(b[i]==1){
        v.push_back(a[i]);
      }
    }
    string qq;
    Dfs(1,qq);
    return;
  }
  b[x] = 1;
  dfs(x + 1);
  b[x] = 0;
  dfs(x + 1);
}
int main() {
  freopen("codes.in", "r", stdin);
  freopen("codes.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dfs(1);
  sort(vv.begin(),vv.end(),cmp);
  cout << vv[0].size()<< endl;
  cout << vv[0];
  return 0;
}