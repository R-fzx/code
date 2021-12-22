// #define TIME
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;
using Tll = tuple<LL, LL, LL>;

const int kN = 2e5 + 2;

int n, m, _c, c[kN], a[kN], t = -1;
vector<int> e[kN];
bool v[kN];
set<int> q;

void R(int x) {
  if (!v[x] && !c[x]) {
    v[x] = 1, ++_c, q.insert(x);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    ++c[y], e[x].push_back(y);
  }
  for (int i = 1; i <= n; ++i) {
    ++c[i], e[0].push_back(i);
  }
  for (R(0); !q.empty();) {
    int x = *q.begin();
    a[++t] = x;
    q.erase(q.begin());
    for (int i : e[x]) {
      --c[i], R(i);
    }
  }
  if (t < n) {
    cout << -1;
  } else {
    for (int i = 1; i <= n; ++i) {
      cout << a[i] << " ";
    }
  }
#ifdef TIME
  double t = clock() * 1.0 / CLOCKS_PER_SEC;
  cerr << "\n\nTIME: " << t << "s\n";
#endif
  return 0;
}