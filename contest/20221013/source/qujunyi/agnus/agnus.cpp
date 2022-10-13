#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
int main(){
  freopen("agnus.in","r",stdin);
  freopen("agnus.out","w",stdout);
  ios::sync_with_stdio(false);
  string a;
  cin >> a;
  string b = "agnus";
  for(long long i = 0;i+4 < a.size();i++){
    long long p = 0;
    bool u = 0;
    for(long long j = i;j <= i+4;j++){
      if(a[j]!=b[p]){
        u = 1;
        break;
      }
      p++;
    }
    if(u==0){
      v.push_back(i);
    }
  }
  long long sum = 0;
  for(long long i = 0;i < a.size();i++){
    bool u = 0;
    long long l = 0,r = v.size()-1;
    while(l <= r){
      long long mid = (l+r)/2;
      if(v[mid]>=i){
        r = mid-1;
        u=1;
      }else{
        l= mid+1;
      }
    }
    if(u==1){
      sum+=a.size()-(v[r+1]+4);
    }
  }
  cout << sum;
}