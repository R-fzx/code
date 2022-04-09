#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;

const int kN = 1e6 + 1;

int n, r[kN], d[kN], sa[kN], ht[kN], t;
LL ans[kN];
string s;
Pii a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> s;
  s = " " + s;
  iota(d + 1, d + n + 1, 1);
  stable_sort(d + 1, d + n + 1, [](int i, int j) { return s[i] < s[j]; });
  for (int i = 1; i <= n; ++i) {
    r[d[i]] = r[d[i - 1]] + (s[d[i]] != s[d[i - 1]]);
  }
  for (int l = 1; l <= n; l <<= 1) {
    for (int i = 1; i <= n; ++i) {
      a[i] = {r[i], i + l <= n ? r[i + l] : 0};
    }
    iota(d + 1, d + n + 1, 1);
    stable_sort(d + 1, d + n + 1, [](int i, int j) { return a[i] < a[j]; });
    for (int i = 1; i <= n; ++i) {
      r[d[i]] = r[d[i - 1]] + (a[d[i]] != a[d[i - 1]]);
    }
    if (r[d[n]] == n) {
      break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    sa[r[i]] = i;
  }
  for (int i = 1, j = 0; i <= n; ++i) {
    for (j -= !!j; s[i + j] == s[sa[r[i] - 1] + j]; ++j) {
    }
    ht[r[i]] = j;
  }
  for (int i = 1; i <= n; ++i) {
    ans[i] = n - i + 1;
  }
  LL s = 0;
  for (int i = n - 1; i >= 1; --i) {
    int l = 0;
    for (; t && a[t].first >= ht[i + 1]; --t) {
      s -= 1LL * a[t].first * a[t].second, l += a[t].second;
    }
    a[++t] = {ht[i + 1], l + 1}, s += 1LL * ht[i + 1] * (l + 1);
    ans[sa[i]] += s;
  }
  t = s = 0;
  for (int i = 2; i <= n; ++i) {
    int l = 0;
    for (; t && a[t].first >= ht[i]; --t) {
      s -= 1LL * a[t].first * a[t].second, l += a[t].second;
    }
    a[++t] = {ht[i], l + 1}, s += 1LL * ht[i] * (l + 1);
    ans[sa[i]] += s;
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}