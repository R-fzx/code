#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif

using namespace std;


int main() {
  srand(time(nullptr));
  freopen("bus.in", "w", stdout);
  int n = 5000;
  cout << n << endl;
  for (int i = 1; i <= n; ++i) {
    cout << abs(rand() * rand()) % 1000000001 << ' ';
  }
  return 0;
}