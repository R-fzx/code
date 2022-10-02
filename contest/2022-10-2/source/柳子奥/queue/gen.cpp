#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#endif

using namespace std;

int main() {
  freopen("queue.in", "w", stdout);
  int n = 9;
  cout << n << endl;
  for (int i = 1; i <= n; ++i) {
    cout << rand() % 1000 + 1 << ' ';
  }
  return 0;
}