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
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

int a, b, e[100];
LL k;
vector<int> l;
bitset<100> v;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      e[i * 10 + j] = j * 10 + i * j % 10;
    }
  }
  cin >> a >> b >> k;
  l.push_back(a * 10 + b);
  for (; !v[l.back()]; v[l.back()] = 1, l.push_back(e[l.back()])) {
  }
  l.pop_back();
  for (int i : l) {
    debug("%d %d\n", i / 10, i % 10);
  }
  cout << l[(k - 1) % l.size()] / 10;
  return 0;
}