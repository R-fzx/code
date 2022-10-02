#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;
using Pii = pair<int, int>;
using LL = long long;

const int kMaxN = 501 * 501;

ifstream fin("garland.in");
ofstream fout("garland.out");

vector<Pii> v[2];
int a[kMaxN], l[kMaxN], r[kMaxN], n, p0, p1;
LL ans, t;

int main() {
  fin >> n, n *= n;
  for (int i = 1; i <= n; i++) {
    fin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    fin >> l[i];
  }
  for (int i = 1; i <= n; i++) {
    fin >> r[i];
  }
  for (int i = 1; i <= n; i++) {
    if (l[i] > 0) {
      ans += l[i] * a[i];
      t += l[i];
      v[0].push_back({a[i], r[i] - l[i]});
    } else if (r[i] < 0) {
      ans += r[i] * a[i];
      t += r[i];
      v[1].push_back({a[i], r[i] - l[i]});
    } else {
      v[0].push_back({a[i], r[i]});
      v[1].push_back({a[i], -l[i]});
    }
  }
  sort(v[0].begin(), v[0].end()), sort(v[1].begin(), v[1].end());
  p0 = v[0].size() - 1, p1 = 0;
  while (t > 0) {
    LL c = min(t, (LL)v[1][p1].second);
    t -= c, ans -= c * v[1][p1].first;
    p1 += !v[1][p1].second;
  }
  while (t < 0) {
    LL c = min(-t, (LL)v[0][p0].second);
    t += c, ans += c * v[0][p0].first;
    p0 -= !v[0][p0].second;
  }
  while (p0 >= 0 && p1 < v[1].size() && v[0][p0].first > v[1][p1].first) {
    LL c = min(v[0][p0].second, v[1][p1].second);
    ans += c * (v[0][p0].first - v[1][p1].first);
    v[0][p0].second -= c, v[1][p1].second -= c;
    p0 -= !v[0][p0].second, p1 += !v[1][p1].second;
  }
  fout << ans;
  return 0;
}