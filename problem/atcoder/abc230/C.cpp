#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

LL n, a, b, p, q, r, s;
LL A(LL x) { return max(x, -x); }

int main() {
  cin >> n >> a >> b >> p >> q >> r >> s;
  for (LL i = p; i <= q; ++i) {
    for (LL j = r; j <= s; ++j) {
      cout << (i - j == A(a - b) || i + j == a + b ? '#' : '.');
    }
    cout << endl;
  }
  return 0;
}