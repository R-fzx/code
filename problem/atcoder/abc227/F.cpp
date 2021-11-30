#include <iostream>
#include <queue>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;

const int kN = 31;

int h, w, k;
Pii a[kN][kN];
LL f[kN][kN], ans;

LL S(int x, int y) {
  
}

int main() {
  cin >> h >> w >> k;
  for (int i = 1, c = 0; i <= h; ++i)
    for (int j = 1; j <= w; ++j) cin >> a[i][j].first, a[i][j].second = ++c;
  for (int i = 1; i <= h; ++i)
    for (int j = 1; j <= w; ++j) ans = min(ans, S(i, j));
  return 0;
}