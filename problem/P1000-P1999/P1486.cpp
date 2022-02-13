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

int q, m, k, c, p;
char o;
vector<int> l;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> q >> m;
  while (q--) {
    cin >> o >> k;
    if (o == 'I') {
      if (k >= m) {
        l.insert(lower_bound(l.begin(), l.end(), p - k), p - k);
      }
    } else if (o == 'A') {
      p += k;
    } else if (o == 'S') {
      p -= k;
      int i = 0;
      for (; i < l.size() && p >= m + l[i]; ++i) {
      }
      c += l.size() - i, l.resize(i);
    } else {
      cout << (k > l.size() ? -1 : p - l[k - 1]) << '\n';
    }
    // for (int i : l) {
    //   cerr << i << " ";
    // }
    // cerr << endl;
  }
  cout << c;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}