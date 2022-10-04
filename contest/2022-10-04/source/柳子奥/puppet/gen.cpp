#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#endif

using namespace std;

void work() {
  cout << 10 << endl;
  for (int i = 1; i <= 10; ++i) cout << rand() % 10 + 1 << ' ';
  cout << endl;
}

int main() {
  srand(114514);
  freopen("puppet.in", "w", stdout);
  for (int i = 1; i <= 50; ++i) work();
  return 0;
}