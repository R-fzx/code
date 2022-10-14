#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif

using namespace std;


int main() {
  freopen("wave.in", "w", stdout);
  mt19937 mt_rand(std::chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<long long> gen(1, 1000);//740742376475050ll
  int T = 100;
  cout << T << endl;
  while(T--) {
    long long n = 10, c = gen(mt_rand);
    cout << n << ' ' << c << endl;
  }
  // cout << gen(mt_rand) << endl;
  return 0;
}