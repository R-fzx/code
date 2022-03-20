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

int n;
LL x;
vector<char> l;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    char ch;
    cin >> ch;
    if (ch == 'U' && !l.empty() && l.back() != 'U') {
      l.pop_back();
    } else {
      l.push_back(ch);
    }
  }
  for (char i : l) {
    // cout << i;
    if (i == 'U') {
      x /= 2;
    } else {
      x = x * 2 + (i == 'R');
    }
  }
  cout << x;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}