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

const int kN = 2e5 + 1;
const LL kM = 1e9 + 7;

int n, s, a[kN];
vector<Pii> e[kN];
vector<int> l;
bool v[kN], b[kN];
LL ans;

int D(int x, int f) {
  // cout << x << ' ' << f << '\n';
  if (v[x]) {
    return x;
  }
  v[x] = 1;
  for (Pii i : e[x]) {
    int y;
    if (i.second != f && (y = D(i.first, i.second))) {
      l.push_back(x);
      return x == y ? 0 : y;
    }
  }
  return 0;
}
void G(int x, int f) {
  if (b[x]) {
    return;
  }
  b[x] = 1, ++s;
  for (Pii i : e[x]) {
    if (i.first != f) {
      G(i.first, x);
    }
  }
}
LL P(int e) {
  LL s = 1;
  for (LL b = 2; e; e >>= 1, b = b * b % kM) {
    if (e & 1) {
      s = s * b % kM;
    }
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    e[i].emplace_back(a[i], i), e[a[i]].emplace_back(i, i);
  }
  ans = 1;
  for (int i = 1; i <= n; ++i) {
    if (!b[i]) {
      l.clear(), s = 0, D(i, 0), G(i, 0);
      ans = ans * (P(l.size()) - 2 + kM) % kM * P(s - l.size()) % kM;
    }
  }
  cout << ans;
  return 0;
}