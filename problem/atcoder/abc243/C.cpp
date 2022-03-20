#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2e5 + 1;

struct E {
  Pii p;
  char d;
  
  bool operator<(const E& rhs) const {
    return p < rhs.p;
  }
} a[kN];
int n;

bool C() {
  for (int i = 1, j = 1; i <= n; i = j) {
    for (++j; j <= n && a[j].p.first == a[i].p.first; ++j) {
      if (a[j - 1].d == 'R' && a[j].d == 'L') {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].p.second >> a[i].p.first;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].d;
  }
  sort(a + 1, a + n + 1);
  cout << (C() ? "Yes" : "No");
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}