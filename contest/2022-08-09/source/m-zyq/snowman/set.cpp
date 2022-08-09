#include <bits/stdc++.h>
using namespace std;
int n, v[500009] ,ans=1;
inline int read() {
  int r(0);
  char ch(getchar());
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') r = (r << 1) + (r << 3) + ch - '0', ch = getchar();
  return r;
}
struct node{
  queue<int>q;
  int num;
  inline const bool operator<(const node b)const{
    return q<b.q;
  }
};
inline bool check(int len){
  set<node>s;s.clear();
  queue<int>q;
  for(int i(2); i<= n;i++){
    q.push(v[i-1]-v[i]);
    if(q.size()>len)q.pop();
    //cout<<i<<' '<<q.size()<<'\n';
    if(q.size()>=len){
      //cout<<i<<'\n';
      if(s.count({q,i})&&i-s.find({q,i})->num>=len-1)return true;
      s.insert({q,i});
    }
  }
  return false;
}
int main() {
  freopen("snowman.in", "r", stdin), freopen("set.out", "w", stdout);
  cout.tie(0);
  n = read();
  for (int i(1); i <= n; i++) {
    v[i] = read();
  }
  int l(1),r(n-1),mid;
  for(;l<r;){
    mid=((l+r+1)>>1);
    if(check(mid)){
      l=mid;
      ans=max(ans,mid);
    }else{
      r=mid-1;
    }
  }
  cout<<ans;
  return 0;
}
