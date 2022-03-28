#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 401;

int t, n, m, c;
string a;
deque<char> b;

void D(int x, deque<char> &&s) {
  if (x == n) {
    c += s == b;
    return;
  }
  if (a[x] == '-') {
    auto p = s;
    s.pop_front();
    D(x + 1, move(s));
    p.pop_back();
    D(x + 1, move(p));
  } else {
    s.push_back(a[x]);
    D(x + 1, move(s));
  }
}

int main() {
#define FILEIO(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout);
  FILEIO("string")
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    c = 0, b.clear();
    string x;
    cin >> n >> m >> a >> x;
    for (char c : x) {
      b.push_back(c);
    }
    D(0, deque<char>());
    cout << c << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}