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
#include <random>
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

string x, y;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> x >> y;
  for (char &c : x) {
    c = tolower(c) - 'a';
  }
  for (int i = 0; i < y.size(); ++i) {
    int v = islower(y[i]) ? 'a' : 'A';
    cout << char(v + (y[i] - v - x[i % x.size()] + 26) % 26);
  }
  return 0;
}