#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
using LL = long long;

LL n, s, i;

int main() {
  cin >> n;
  for (i = 1; i * i <= n; ++i) {
    s += n / i;
  }
  // LL x = ceil(sqrt(n));
  cout << (s + i) * 2 - i * i - 1;
  return 0;
}
/*
1 n
2 [n/2]
3 [n/3]
...
n-1 [n/(n-1)]
n 1
[n/i] = 1
n/2+1 ~ n
[n/i] = 2
n/3+1 ~ n/2
...
[n/i] = n
1
*/