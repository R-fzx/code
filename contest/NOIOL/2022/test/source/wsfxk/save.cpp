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

int n, c;
string s, x;
vector<string> l;

int main() {
  freopen("save.in", "r", stdin);
  freopen("save.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  while (n--) {
    cin >> s >> x;
    int _c = 0;
    for (int i = 0; i + 2 < x.size(); ++i) {
      if (x[i] == 's' && x[i + 1] == 'o' && x[i + 2] == 's') {
        ++_c;
      }
    }
    if (_c > c) {
      l.clear(), l.push_back(s), c = _c;
    } else if (_c == c) {
      l.push_back(s);
    }
  }
  for (string &i : l) {
    cout << i << " ";
  }
  cout << endl << c;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}