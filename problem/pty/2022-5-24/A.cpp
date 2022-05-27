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

const int kN = 2e5 + 2;

int n, k;
set<Pii> s;
vector<int> l;
vector<Pii> a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1, l, r; i <= n; ++i) {
    cin >> l >> r;
    a[l].emplace_back(r, i);
  }
  for (int i = 1; i < kN; ++i) {
    for (auto &i : a[i]) {
      s.emplace(i);
    }
    for (; !s.empty() && s.begin()->first < i; s.erase(s.begin())) {
    }
    for (decltype(s.begin()) p; s.size() > k; p = --s.end(), l.push_back(p->second), s.erase(p)) {
    }
  }
  sort(l.begin(), l.end());
  cout << l.size() << endl;
  for (int i : l) {
    cout << i << " ";
  }
  return 0;
}