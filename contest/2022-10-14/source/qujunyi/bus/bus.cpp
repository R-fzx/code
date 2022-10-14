#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("bus.in", "r", stdin);
  freopen("bus.out", "w", stdout);
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  long long sum = 0;
  long long p = 1e18;
  for(long long i = 1;i <= n;i++){
    long long x;
    cin >> x;
    if(x<p){
      p=x;
    }
    sum+=p;
  }
  cout << sum;
}