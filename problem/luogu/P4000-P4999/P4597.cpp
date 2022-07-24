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

const int kN = 5e5 + 1;

int n, a[kN];
priority_queue<int> q;
LL ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  q.push(a[1]);
  for (int i = 2; i <= n; ++i) {
    int x = q.top();
    if (a[i] < x) {
      q.pop(), ans += x - a[i], q.push(a[i]), q.push(a[i]);
    } else {
      q.push(a[i]);
    }
  }
  cout << ans;
  return 0;
}
/*
abcabcabc
000123123
*/