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
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const LL kM = 998244353;
const int kN = 5e4 + 1;

int n, c[kN];
unordered_map<int, int> a;
vector<int> l;
LL f[kN] = {1}, fi[kN] = {1};

LL P(LL b, LL e = kM - 2) {
  LL s = 1;
  for (; e; e >>= 1, b = b * b % kM) {
    if (e & 1) {
      s = s * b % kM;
    }
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    ++a[x], fi[i] = P(f[i] = f[i - 1] * i % kM);
  }
  for (auto i : a) {
    if (!c[i.second]++) {
      l.push_back(i.second);
    }
  }
  for (int k = 1; k <= n; ++k) {
    LL v = f[n] * fi[k] % kM * fi[n - k] % kM, iv = P(v), s = 0;
    for (int i : l) {
      s = (s + (v - (n - i - k >= 0 ? f[n - i] * fi[k] % kM * fi[n - i - k] % kM : 0) + kM) % kM * iv % kM * c[i] % kM) % kM;
    }
    cout << s << endl;
  }
  return 0;
}
/*
1 2 2

a: 1 2
c: 1 1
l: 1 2
*/