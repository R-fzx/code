#include <bits/stdc++.h>

#define db(x) cerr << #x << '=' << x << endl;
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define dbg debug("*** Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)

using namespace std;

const int kMod = 1e9;

int main() {
  freopen("maze.in", "w", stdout);
  srand(time(NULL));
  cout << 20 << ' ' << 20 << ' ' << 123333 << endl;
  for (int i = 1; i <= 20; ++i, putchar('\n')) {
    for (int j = 1; j <= 20; ++j) {
      cout << 1ll * rand() * rand() % kMod * rand() * rand() % kMod * rand() * rand() % kMod * rand() * rand() % kMod * rand() * rand() % kMod << ' ';
    }
  }
  return 0;
}