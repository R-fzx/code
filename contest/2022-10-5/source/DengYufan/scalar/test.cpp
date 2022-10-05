#include <iostream>
#define LL long long

using namespace std;

const LL kInf = 1e18;
LL n, ans = kInf;
bool b[801];
pair<LL, LL> a[801];

void S(LL x, LL s) {
  if (x > n) {
    ans = min(ans, s);
    return;
  }
  for (LL i = 1; i <= n; i++) {
    if (!b[i]) {
      b[i] = 1;
      S(x + 1, s + a[x].first * a[i].second);
      b[i] = 0;
    }
  }
}

int main() {
  freopen("scalar.in", "r", stdin);
  freopen("scalar.ans", "w", stdout);
  cin >> n;
  for (LL i = 1; i <= n; i++) {
    cin >> a[i].first;
  }
  for (LL i = 1; i <= n; i++) {
    cin >> a[i].second;
  }
  S(1, 0);
  cout << ans;
  return 0;
}
