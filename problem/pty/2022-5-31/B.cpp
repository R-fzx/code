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

int n, a[kN], c[kN];
priority_queue<int, vector<int>, greater<int>> q;

void R(int x) {
  if (!c[x]) {
    q.push(x);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for_each(a + 1, a + n, [](int &x) { cin >> x, ++c[x]; });
  for (int i = 1; i <= n; R(i++)) {
  }
  cout << a[1] << endl;
  for (int i = n - 1; i >= 1; --i) {
    int x = q.top();
    q.pop();
    cout << x << " " << a[i] << endl;
    --c[a[i]], R(a[i]);
  }
  return 0;
}