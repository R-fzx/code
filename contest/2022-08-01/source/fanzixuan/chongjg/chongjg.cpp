#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

int n, m;

int main() {
#define RF(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
  RF("chongjg");
  cin >> n >> m;
  if (n == m) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        cout << 'A';
      }
      cout << '\n';
    }
  } else {
    cout << "114514";
  }
  return 0;
}