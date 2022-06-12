#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

const int kN = 2e5 + 1;

struct E {
  int a, b, t;
  bool operator<(const E& x) const { return a > x.a || a == x.a && t > x.t; }
} e[kN << 1];
int n, m;
multiset<int> s;

bool S() {
  sort(e + 1, e + n + m + 1);
  for (int i = 1; i <= n + m; ++i) {
    if (e[i].t) {
      s.insert(e[i].b);
    } else {
      auto x = s.lower_bound(e[i].b);
      if (x != s.end()) {
        s.erase(x);
      } else {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> e[i].a;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> e[i].b;
  }
  for (int i = n + 1; i <= n + m; ++i) {
    cin >> e[i].a, e[i].t = 1;
  }
  for (int i = n + 1; i <= n + m; ++i) {
    cin >> e[i].b;
  }
  cout << (S() ? "Yes" : "No");
  return 0;
}