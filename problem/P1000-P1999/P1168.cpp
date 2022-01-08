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
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 1e5 + 3;

int n, a[kN], v;
priority_queue<int> q[2];
auto A = [](LL x) { q[x > v].push(x * (x > v ? -1 : 1)); };

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  q[0].push(a[1]);
  for (int k = 1; k <= (n + 1) / 2; ++k) {
    for (; q[0].size() > k; q[1].push(-q[0].top()), q[0].pop()) {
    }
    for (; q[0].size() < k; q[0].push(-q[1].top()), q[1].pop()) {
    }
    cout << (v = q[0].top()) << endl;
    A(a[k * 2]), A(a[k * 2 + 1]);
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}