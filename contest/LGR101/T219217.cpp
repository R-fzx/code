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

unsigned long long x;
bool f = 0;

string ten2hex(unsigned long long x) {
  string res;
  while (x) {
    res += (x % 16 < 10 ? x % 16 + '0' : x % 16 - 10 + 'A');
    x /= 16;
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (char ch; cin >> ch;) {
    if (ch == '{') {
      cout << ch;
    } else if (ch == ',' || ch == '}') {
      if (f) {
        if (to_string(x).size() >= ten2hex(x).size() + 2) {
          cout << "0x" + ten2hex(x);
        } else {
          cout << x;
        }
      }
      x = 0;
      cout << ch;
    } else {
      x = x * 10 + ch - '0', f = 1;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}