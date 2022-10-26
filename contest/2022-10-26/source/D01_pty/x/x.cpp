#include <algorithm>
#include <fstream>
#include <map>

using namespace std;
using Pii = pair<int, int>;

ifstream fin("x.in");
ofstream fout("x.out");

const int kMaxN = 1e5 + 1;

map<int, int> m;
Pii a[kMaxN];
int f[kMaxN], t[kMaxN * 2], n, ans, s;

void U(int x, int v) {
  for (; x <= s; x += x & -x) {
    t[x] = max(t[x], v);
  }
}

int C(int x) {
  int r = 0;
  for (; x; x -= x & -x) {
    r = max(r, t[x]);
  }
  return r;
}

int main() {
  fin >> n;
  for (int i = 1; i <= n; i++) {
    fin >> a[i].first >> a[i].second;
    m[a[i].first - a[i].second] = m[a[i].first + a[i].second] = 0;
  }
  for (auto &i : m) {
    i.second = ++s;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    f[i] = C(m[a[i].first - a[i].second] - 1) + 1;
    ans = max(ans, f[i]);
    U(m[a[i].first + a[i].second], f[i]);
  }
  fout << ans;
  return 0;
}