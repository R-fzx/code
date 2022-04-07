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

const int kN = 2e5 + 3;

int n, a[kN], v[kN];
vector<int> u, d;

bool C() {
  cin >> n;
  a[0] = INT32_MAX, a[1] = INT32_MIN, u.push_back(1), d.push_back(0);
  for (int i = 2; i <= n + 1; ++i) {
    cin >> a[i];
    if (a[i] > a[u.back()]) {
      u.push_back(i);
    } else if (a[i] <= a[u[u.size() - 2]]) {
      if (a[u.back()] < a[d.back()]) {
        d.push_back(u.back()), u.pop_back(), d.push_back(i);
      } else if (a[i] < a[d.back()]) {
        d.push_back(i);
      } else {
        return 0;
      }
    } else {
      if (a[u.back()] < a[d.back()]) {
        d.push_back(u.back()), u.pop_back(), u.push_back(i);
      } else {
        if (a[i] < a[d.back()]) {
          d.push_back(i);
        } else {
          return 0;
        }
      }
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  if (C()) {
    cout << "YES\n";
    for (int i : d) {
      v[i - 1] = 1;
    }
    for (int i = 1; i <= n; ++i) {
      cout << v[i] << " ";
    }
  } else {
    cout << "NO";
  }
  return 0;
}