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
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

string a, b;
int s[2], c[2][26];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 0; i < 3; ++i) {
    string s;
    cin >> s;
    a += s;
  }
  for (int i = 0; i < 3; ++i) {
    string s;
    cin >> s;
    b += s;
  }
  for (int i = 0; i < 9; ++i) {
    if (a[i] == b[i]) {
      ++s[0];
    } else {
      ++c[0][a[i] - 'A'], ++c[1][b[i] - 'A'];
    }
  }
  for (int i = 0; i < 26; ++i) {
    s[1] += min(c[0][i], c[1][i]);
  }
  cout << s[0] << endl
       << s[1];
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}