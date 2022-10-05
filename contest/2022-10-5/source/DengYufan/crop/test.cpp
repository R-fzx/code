#include <iostream>
#define LL long long

using namespace std;

LL n, a, b, c, d, m, ans;
pair<LL, LL> p[100001];

int main() {
  freopen("crop.in", "r", stdin);
  freopen("crop.ans", "w", stdout);
  cin >> n >> a >> b >> c >> d >> p[1].first >> p[1].second >> m;
  for (LL i = 2; i <= n; i++) {
    p[i].first = (a * p[i - 1].first + b) % m;
    p[i].second = (c * p[i - 1].second + d) % m;
  }
  for (LL i = 1; i <= n; i++) {
    for (LL j = i + 1; j <= n; j++) {
      for (LL k = j + 1; k <= n; k++) {
        if (!((p[i].first + p[j].first + p[k].first) % 3) && !((p[i].second + p[j].second + p[k].second) % 3)) {
          ans++;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
