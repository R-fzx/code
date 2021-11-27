#include <iostream>
#include <queue>

using namespace std;
using LL = long long;

const int kN = 31;

int h, w, k;
LL a[kN][kN];

int main() {
  cin >> h >> w >> k;
  for (int i = 1; i <= h; ++i)
    for (int j = 1; j <= w; ++j) cin >> a[i][j];
  
  return 0;
}