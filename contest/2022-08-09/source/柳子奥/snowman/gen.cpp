#include <bits/stdc++.h>

#define db(x) cerr << #x << '=' << x << endl;
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define dbg debug("*** Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)

using namespace std;

int main() {
  srand(114514);
  freopen("snowman.in", "w", stdout);
  cout << 500000 << endl;
  for (int i = 1; i <= 500000; ++i) {
    cout << abs(rand() * rand()) % 100000000 + 1 << endl;
  }
  return 0;
}