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
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

int n, k;
vector<Pii> l;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; n && i <= k; ++i) {
    for (int j = i + 1; n && j <= k; ++j) {
      l.emplace_back(i, j);
      --n && (l.emplace_back(j, i), --n);
    }
  }
  if (n) {
    cout << "NO";
  } else {
    cout << "YES" << endl;
    for (Pii i : l) {
      cout << i.first << " " << i.second << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
1 2
2 1
1 3
3 1
1 4
4 1
...
1 k
k 1
2 3
3 2
2 4
4 2
...
2 k
k 2
3 4
*/