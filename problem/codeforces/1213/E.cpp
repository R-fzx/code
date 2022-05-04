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
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

int n;
string a, b, s = "abc";

bool S1() {
  string s = "abc";
  bool f = 0;
  do {
    string _s = s;
    _s += _s;
    if (_s.find(a) == string::npos && _s.find(b) == string::npos) {
      f = 1;
      break;
    }
  } while (next_permutation(s.begin(), s.end()));
  if (f) {
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
      cout << s;
    }
  }
  return f;
}
bool S2() {
  string s = "abc";
  bool f = 0;
  do {
    if (s.find(a) == string::npos && s.find(b) == string::npos) {
      f = 1;
      break;
    }
  } while (next_permutation(s.begin(), s.end()));
  if (f) {
    cout << "YES\n"
         << string(n, s[0]) << string(n, s[1]) << string(n, s[2]);
  }
  return f;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> a >> b;
  if (!S1() && !S2()) {
    cout << "NO";
  }
  return 0;
}
/*
acb
aa
bb
cc
*/