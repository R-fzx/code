#include <algorithm>
#include <iostream>

using namespace std;
using LL = long long;

const int kN = 1e5 + 2;

struct E {
  LL l, r, h;
} b[kN];
int n, k, a[kN], c;
LL ans, s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  k = min((LL)k, s);
  sort(a + 1, a + n + 1, greater<int>());
  for (int i = 1; i <= n;) {
    int j = i;
    for (; j <= n && a[j] == a[i]; ++j) {
    }
    b[++c] = {a[j] + 1, a[i], j - 1}, i = j;
  }
  // for (int i = 1; i <= c; ++i) {
  //   cerr << b[i].l << " " << b[i].r << " " << b[i].h << endl;
  // }
  // cerr << k << endl;
  int i = 1;
  for (; i <= c && k >= (b[i].r - b[i].l + 1) * b[i].h; ++i) {
    ans += (b[i].l + b[i].r) * (b[i].r - b[i].l + 1) / 2 * b[i].h;
    k -= (b[i].r - b[i].l + 1) * b[i].h;
  }
  if (i <= c) {
    int x = k / b[i].h;
    // cerr << i << " " << x << endl;
    ans += (b[i].r - x + 1 + b[i].r) * x / 2 * b[i].h;
    k -= x * b[i].h;
    ans += (b[i].r - x) * k;
  }
  // for (int i = 1, j = 1; k--; ) {
  //   ans += a[j]--;
  //   if (!--j) {
  //     for (; a[i] == a[i + 1]; ++i) {
  //     }
  //     j = i;
  //   }
  // }
  cout << ans;
  return 0;
}
/*
1 2 3
*/