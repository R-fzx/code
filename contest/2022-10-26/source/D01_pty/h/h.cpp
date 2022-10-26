#include <algorithm>
#include <fstream>

using namespace std;
using Pii = pair<int, int>;

ifstream fin("h.in");
ofstream fout("h.out");

const int kMaxN = 2e5 + 2;

Pii p[kMaxN];
int h[kMaxN], n, m, k;
long long ans;

int main() {
  ios::sync_with_stdio(0), fin.tie(0);
  fin >> n >> k;
  for (int i = 1; i <= n; i++) {
    fin >> h[i];
  }
  fin >> m;
  for (int i = 1; i <= m; i++) {
    fin >> p[i].first >> p[i].second;
  }
  sort(p + 1, p + 1 + m);
  for (int i = 1; i <= m; i++) {
    for (int j = i - 1, t = p[i].first, mn = h[t]; j >= 1; j--) {
      for (; t >= p[j].first; t--) {
        mn = min(mn, h[t]);
      }
      if (!mn || p[i].second - min(p[i].second, mn) + p[i].first - p[j].first > k) {
        break;
      }
      int d = min(min(mn, p[i].second), p[j].second);
      ans += p[i].second + p[j].second + p[i].first - p[j].first - 2 * d <= k;
    }
  }
  fout << ans;
  return 0;
}