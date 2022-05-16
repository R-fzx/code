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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  set<Pii> s;
  s.insert({1, 2});
  s.insert({2, 1});
  s.insert({2, 3});
  s.insert({3, 2});
  auto i = s.lower_bound({2, 2});
  cout << i->first << " " << i->second;
  return 0;
}
/*
(i,j) to (4,4)
(j-4)*(j-4)+(i-4)*(i-4)<=4*4
*/