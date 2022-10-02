#include <iostream>
#include <algorithm>
#include <cstring>

#define file(x) freopen (x".in", "r", stdin), freopen (x".out", "w", stdout)
#define put(x) cout << x << '\n'
using namespace std;
const int kN = 555;

struct Node {
  int x, y, z;
} p[int (3e5 + 5)];
int n;
int E (int i, int j) {
  return (i - 1) * n + j;
}
int main () {
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> p[E (i, j)].x;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> p[E (i, j)].y;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> p[E (i, j)].z;
    }
  }
  return 0;
}