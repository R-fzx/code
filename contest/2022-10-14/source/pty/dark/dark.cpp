#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;
using Pdd = pair<double, double>;

ifstream fin("dark.in");
ofstream fout("dark.out");

const int kMaxN = 2e5 + 1;

Pdd a[kMaxN], b[kMaxN], c[kMaxN];
int n;

double D(Pdd a, Pdd b) { return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)); }

double W(int l, int r) {
  if (l == r) {
    return 1e9;
  }
  int m = (l + r) / 2, ln = 0, rn = 0;
  double x = a[m].first, ans = min(W(l, m), W(m + 1, r)), ans2 = ans;
  for (int i = l; i <= m; i++) {
    if (x - a[i].first <= ans) {
      b[++ln] = a[i];
    }
  }
  for (int i = m + 1; i <= r; i++) {
    if (a[i].first - x <= ans) {
      c[++rn] = a[i];
    }
  }
  for (int i = 1, p = 1, q = 1; i <= ln; i++) {
    for (; p <= rn && b[i].second - c[p].second > ans; p++) {
    }
    for (; q <= rn && c[q].second - b[i].second <= ans; q++) {
    }
    for (int j = p; j < q; j++) {
      ans2 = min(ans2, D(b[i], c[j]));
    }
  }
  for (int i = l, p = l, q = m + 1; i <= r; i++) {
    b[i] = q > r || p <= m && a[p].second < a[q].second ? a[p++] : a[q++];
  }
  copy(b + l, b + r + 1, a + l);
  return ans2;
}

int main() {
  fin >> n;
  for (int i = 1; i <= n; i++) {
    fin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + 1 + n);
  fout << setprecision(3) << fixed << W(1, n);
  return 0;
}
