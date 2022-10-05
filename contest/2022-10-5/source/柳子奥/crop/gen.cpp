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
  freopen("crop.in", "w", stdout);
  int n, a, b, c, d, m, xx, yy;
  n = random(3, 300), m = random(1000000000), a = random(1000000000);
  b = random(1000000000), c = random(1000000000), d = random(1000000000);
  xx = random(1000000000), yy = random(1000000000);
  cout << n << ' ' << a << ' ' << b << ' ' << c << ' ' << d << ' ' << xx << ' ' << yy << ' ' << m << endl;
  return 0;
}