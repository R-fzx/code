#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <iterator>

using namespace std;
using Pii = pair<int, int>;

const int kN = 2e5 + 1;

int n, d, c = 1;
Pii a[kN];

int main() {
  cin >> n >> d;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + n + 1, [](Pii x, Pii y) { return x.second < y.second; });
  for (int i = 2, p = a[1].second + d - 1; i <= n; ++i) {
    if (a[i].first > p) {
      ++c, p = a[i].second + d - 1;
    }
  }
  cout << c;
  return 0;
}