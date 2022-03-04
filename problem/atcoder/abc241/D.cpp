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

const int kN = 2e5 + 1;

int q, o, k;
LL x;
vector<LL> l;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> o >> x;
    if (o == 1) {
      l.insert(lower_bound(l.begin(), l.end(), x), x);
    } else if (o == 2) {
      cin >> k;
      int i = lower_bound(l.begin(), l.end(), x) - l.begin() - 1;
      // cerr << i << endl;
      if (i - k + 1 < 0) {
        cout << -1 << endl;
      } else {
        cout << l[i - k + 1] << endl;
      }
    } else {
      cin >> k;
      int i = upper_bound(l.begin(), l.end(), x) - l.begin();
      // cerr << i << " " << l[i] << endl;
      if (i + k - 1 >= l.size()) {
        cout << -1 << endl;
      } else {
        cout << l[i + k - 1] << endl;
      }
    }
    // for (int i : l) {
    //   cerr << i << " ";
    // }
    // cerr << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}