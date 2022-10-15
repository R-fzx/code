#include <iomanip>
#include <iostream>

using namespace std;

int n, m, k, c[9];
double num, ans;
pair<int, double> a[9];

void T(int x, int s, int t, double p) {
  if (x > n) {
    if (s >= (n + 1) / 2) {
      num += p;
    } else {
      num += p * m / t;
    }
    return;
  }
  T(x + 1, s, t + a[x].first, p * (1.0 - min(a[x].second + 0.1 * c[x], 1.0)));
  T(x + 1, s + 1, t, p * min(a[x].second + 0.1 * c[x], 1.0));
}

void S(int x, int y) {
  if (x > n) {
    num = 0.0;
    T(1, 0, m, 1.0);
    ans = max(ans, num);
    return;
  }
  for (int i = 0; i + y <= k; i++) {
    c[x] = i;
    S(x + 1, y + i);
  }
}

int main() {
  freopen("assembly.in", "r", stdin);
  freopen("assembly.out", "w", stdout);
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    a[i].second /= 100.0;
  }
  S(1, 0);
  cout << fixed << setprecision(6) << ans;
  return 0;
}
