#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#define pass 114514
#endif

using namespace std;

int random(int n) {
  return 1ll * rand() * rand() * rand() % n + 1;
}
int random(int l, int r) {
  return random(r - l + 1) + (l - 1);
}

int main() {
  srand(time(NULL));
  freopen("perm.in", "w", stdout);
  cout << random(1000000) << endl;
  return 0;
}