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
#include <set>
#include <vector>
#include <iomanip>
#include <type_traits>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

int n;
basic_string<int> s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    s.push_back(x & 1);
  }
  for (int i = 0; i < n - 1; ++i) {
    if (i >= 0 && s[i] == s[i + 1]) {
      s.erase(i, 2), i -= 2, n -= 2;
    }
  }
  cout << (n <= 1 ? "YES" : "NO");
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}