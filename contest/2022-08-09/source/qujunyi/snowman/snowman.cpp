#include<bits/stdc++.h>
using namespace std;
int a[500005];
int s[500005];
map<vector<int>,int> m;
int main(){
  freopen("snowman.in","r",stdin);
  freopen("snowman.out","w",stdout);
  int n;
  cin>> n;
  for(int i = 1;i <= n;i++){
    cin >> a[i];
  }
  for(int i = 1;i < n;i++){
    s[i]=a[i+1]-a[i];
  }
  n--;
  for(int i = 1;i <= n;i++){
    vector<int> v;
    for(int j = i;j<= n;j++){
      v.push_back(s[i]);
      m[v]=max(m[v],i);
    }
  }
  int maxn = 0;
  for(int i = 1;i <= n;i++){
    vector<int> v;
    for(int j = i;j<= n;j++){
      v.push_back(s[i]);
      int sw= m[v];
      if(sw==0){
        break;
      }
      int ss = v.size()+1;
      maxn = max(maxn,min(ss,abs(i-sw)));
    }
  }
  cout << maxn;
}
  