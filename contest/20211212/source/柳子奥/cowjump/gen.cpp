#include <bits/stdc++.h>

using namespace std;

int n;

int random (int n) {
  return 1ll * rand() * rand() % n + 1;
}

int main() {
  freopen("cowjump.in", "w", stdout);
  srand(time(NULL));
  n = 10000;
  cout << n << endl;
  for (int i = 1; i <= n; ++i) {
    cout << random(1000000000) << " " << random(1000000000) << " " << random(1000000000) << " " << random(1000000000) << endl;
  }
  // cerr << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
  return 0;
}