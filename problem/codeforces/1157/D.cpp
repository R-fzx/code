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
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 1;

LL n, k, a[kN];

bool C() {
  if (k == 1) {
    a[1] = n;
    return 1;
  }
  n -= 1LL * k * (k + 1) / 2;
  if (n < 0) {
    return 0;
  }
  for (int i = 1; i <= k; ++i) {
    a[i] = n / k + (k + 1 - i <= n % k) + i;
  }
  if (n != k - 1) {
    return 1;
  } else if (k <= 3) {
    return 0;
  } else {
    --a[2], ++a[k];
    return 1;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  if (C()) {
    cout << "YES\n";
    for (int i = 1; i <= k; ++i) {
      cout << a[i] << " ";
    }
  } else {
    cout << "NO";
  }
  return 0;
}
/*
1 2 3 4 5
    +
0 0 1 1 1

1 3 4 5 6

1 3
1 3 4

1 3 4 5
1 2 4 6
*/