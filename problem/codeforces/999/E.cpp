#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using Pii = pair<int, int>;

const int kN = 5001;

int n, m, s, c, _c;
vector<int> e[kN];
bool v[kN], u[kN];
vector<Pii> p;

void D(int x) {
  if (v[x]) return;
  v[x] = 1;
  for (int i : e[x]) D(i);
}
void M(int x) {
  if (v[x] || u[x]) return;
  u[x] = 1, ++_c;
  for (int i : e[x]) M(i);
}

int main() {
  // freopen("E.in", "r", stdin);
  // freopen("E.out", "w", stdout);
  cin >> n >> m >> s;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].push_back(y);
  }
  D(s);
  for (int i = 1; i <= n; ++i) {
    if (!v[i]) {
      _c = 0, fill(u + 1, u + n + 1, 0), M(i), p.push_back({_c, i});
    }
  }
  sort(p.rbegin(), p.rend());
  for (Pii x : p) {
    if (!v[x.second]) {
      D(x.second), ++c;
    }
  }
  cout << c;
  return 0;
}