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
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

int x, kT[256];

int T(int x, int y, int z) {
  return x * 9 + y * 3 + z;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  char ch;
  for (int i = 0; i < 3; ++i) {
    cin >> ch;
    kT[ch] = i;
  }
  for (int i = 0; i < 3; ++i) {
    cin >> ch;
    x = x * 3 + kT[ch];
  }
  if (x == T(0, 1, 2)) {
    cout << "Yes";
  } else if (x == T(0, 2, 1)) {
    cout << "No";
  } else if (x == T(1, 0, 2)) {
    cout << "No";
  } else if (x == T(1, 2, 0)) {
    cout << "Yes";
  } else if (x == T(2, 0, 1)) {
    cout << "Yes";
  } else {
    cout << "No";
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
0 1 2 Yes
0 2 1 No
*/