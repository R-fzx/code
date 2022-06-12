#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using Pii = pair<int, int>;

const int kN = 2e5 + 1;

int n, d[kN], x, y, z, s, p[kN];
vector<int> e[kN], l;

void D(int x, int f) {
  d[x] = d[f] + 1, p[x] = f;
  for (int i : e[x]) {
    if (i ^ f) {
      D(i, x);
    }
  }
}
Pii U(Pii x) { return {x.first + 1, x.second}; }
Pii S(int x, int f) {
  Pii d = {0, x};
  for (int i : e[x]) {
    if (i ^ f) {
      d = max(d, U(S(i, x)));
    }
  }
  return d;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  D(1, 0), x = max_element(d + 1, d + n + 1) - d, D(x, 0), y = max_element(d + 1, d + n + 1) - d, s += d[y] - 1;
  for (int i = y; i != x; l.push_back(i), i = p[i]) {
  }
  l.push_back(x);
  Pii ans = {0, 0};
  for (int i = 0; i < l.size(); ++i) {
    Pii d = {0, -1};
    for (int j : e[l[i]]) {
      if ((!i || j != l[i - 1]) && (i + 1 == l.size() || j != l[i + 1])) {
        d = max(d, U(S(j, l[i])));
      }
    }
    ans = max(ans, d);
  }
  printf("%d\n%d %d %d", s + ans.first, x, y, ans.second ? ans.second : l[1]);
  return 0;
}