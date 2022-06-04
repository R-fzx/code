#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2049;

int n, m;
char ch;
struct T {
  int b[kN][kN];

  void Add(int x, int y, int v) {
    for (; x <= n; x += x & -x) {
      for (int i = y; i <= m; i += i & -i) {
        b[x][i] += v;
      }
    }
  }
  int Query(int x, int y) {
    int s = 0;
    for (; x; x -= x & -x) {
      for (int i = y; i; i -= i & -i) {
        s += b[x][i];
      }
    }
    return s;
  }
} a[4];

void Add(int x, int y, int v) {
  // cerr << "Add(" << x << ", " << y << ", " << v << ")\n";
  a[0].Add(x, y, v), a[1].Add(x, y, v * x), a[2].Add(x, y, v * y), a[3].Add(x, y, v * x * y);
}
int Query(int x, int y) {
  // cerr << "Query(" << x << ", " << y << ")\n";
  return a[0].Query(x, y) * (x * y + x + y + 1) - a[1].Query(x, y) * (y + 1) - a[2].Query(x, y) * (x + 1) + a[3].Query(x, y);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> ch >> n >> m;
  for (int v, x0, y0, x1, y1; cin >> ch >> x0 >> y0 >> x1 >> y1;) {
    if (ch == 'L') {
      cin >> v;
      ++x1, ++y1;
      Add(x0, y0, v), Add(x0, y1, -v), Add(x1, y0, -v), Add(x1, y1, v);
    } else {
      --x0, --y0;
      cout << Query(x1, y1) - Query(x0, y1) - Query(x1, y0) + Query(x0, y0) << '\n';
    }
  }
  // for (int k = 0; k < 4; ++k) {
  //   for (int i = 1; i <= n; ++i) {
  //     for (int j = 1; j <= m; ++j) {
  //       cerr << a[k].b[i][j] << " ";
  //     }
  //     cerr << endl;
  //   }
  //   cerr << endl;
  // }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
2 2 0 0
2 3 0 1
0 0 0 0
0 1 0 1

2 2 0 0
2 4 0 2
0 0 0 0
-6 -4 0 2

2 2 0 -6
2 4 0 -4
0 0 0 0
0 2 0 2

2 2 0 -6
2 6 0 -2
0 0 0 0
-6 -2 0 22


2 2 0 0
0 1 0 1
0 0 0 0
-2 -2 0 0

2 2 0 0
0 2 0 2
0 0 0 0
-8 -8 0 0

2 2 0 -6
0 2 0 2
0 0 0 0
-2 -2 0 6

2 2 0 -6
0 4 0 4
0 0 0 0
-8 -8 0 24


my:
Add(1, 1, 2)
Add(1, 4, -2)
Add(4, 1, -2)
Add(4, 4, 2)
Add(2, 2, 1)
Add(2, 5, -1)
Add(5, 2, -1)
Add(5, 5, 1)
Query(3, 3)
Query(3, 1)
Query(1, 3)
Query(1, 1)

std:
Add(1, 1, 2)
Add(1, 4, -2)
Add(4, 1, -2)
Add(4, 4, 2)
Add(2, 2, 1)
Add(2, 5, -1)
Add(5, 2, -1)
Add(5, 5, 1)
Query(3, 3)
Query(1, 3)
Query(3, 1)
Query(1, 1)
*/