#include <atcoder/all>
#include <cmath>
#include <functional>
#include <set>

using namespace std;
using Pii = pair<int, int>;

const int kN = 2.5e4 + 1, kM = 1.1e7 + 1;

struct E {
  int n[2];
  set<Pii, greater<Pii>> l;
} e[kM];
int n, m, c = 1, f[kN];
string s;

void M(int x, int v) {
  for (; x <= n; x += x & -x) {
    f[x] = max(f[x], v);
  }
}
int M(int x) {
  int s = 0;
  for (; x; x -= x & -x) {
    s = max(s, f[x]);
  }
  return s;
}
void D(int x) {
  if (x) {
    for (auto i : e[x].l) {
      M(i.second, M(i.first - 1) + 1);
    }
    D(e[x].n[0]), D(e[x].n[1]);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> s;
  s = " " + s;
  m = sqrt(2 * n + 0.25) + 0.5;
  for (int i = 1; i <= n; ++i) {
    for (int x = 1, j = i; j - i + 1 <= m && j <= n; ++j) {
      int &k = e[x].n[s[j] - '0'];
      if (!k) {
        k = ++c;
      }
      e[x = k].l.insert({i, j});
    }
  }
  D(1);
  cout << M(n);
  return 0;
}