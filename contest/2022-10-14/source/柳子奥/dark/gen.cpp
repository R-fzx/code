#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif

using namespace std;

map<pair<int, int>, bool> mp;

int random(int n) {
  return 1ll * rand() * rand() * rand() % n + 1;
}

int main() {
  freopen("dark.in", "w", stdout);
  srand(time(nullptr));
  int n = 20;
  cout << n << endl;
  for (int i = 1; i <= n; ++i) {
    int x = random(1000000), y = random(1000000);
    while (mp[make_pair(x, y)]) x = random(1000000), y = random(1000000);
    cout << x << ' ' << y << endl;
    mp[make_pair(x, y)] = 1;
  }
  return 0;
}