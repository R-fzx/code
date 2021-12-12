#include <iostream>
#include <vector>
#include <map>
#include <ctime>

using namespace std;
using LL = long long;

const int kV = 1e6 + 1;
const LL kM = 998244353;

LL n, k, r, c = 1;
int m[kV];
vector<int> p[kV];
map<LL, int> _c;

int main() {
  // freopen("G.in", "r", stdin);
  // freopen("G.out", "w", stdout);
  cin >> n >> k;
  r = n - k + 1;
  for (int i = 2; i < kV; ++i) {
    if (!m[i]) {
      for (int j = i; j < kV; j += i) m[j] = i;
      for (LL j = (n - k + i) / i * i; j <= n; j += i) p[j - r].push_back(i);
    }
  }
  for (int i = 2; i <= k; ++i) {
    for (int x = i; x > 1; x /= m[x]) --_c[m[x]];
  }
  for (LL i = max(2LL, r); i <= n; ++i) {
    LL x = i;
    for (int j : p[i - r]) {
      for (; x % j == 0; x /= j) ++_c[j];
    }
    if (x > 1) ++_c[x];
  }
  for (auto x : _c) c = c * (x.second + 1) % kM;
  cout << c;
  return 0;
}