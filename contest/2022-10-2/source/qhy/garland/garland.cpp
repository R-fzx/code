#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
using ll = long long;

const int kMaxN = 2.5e5 + 1;

int n, maxn;
struct node {
  int num, l, r;
  bool operator<(node &y) { return num > y.num; }
} a[kMaxN];
ll ans, now;

int main() {
  ifstream cin("garland.in");
  ofstream cout("garland.out");
  cin >> n;
  n *= n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].num;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].l;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].r;
  }
  sort(a, a + n);
  int i;
  for (i = 0; i < n && a[i].num; i++) {
    ans += a[i].r * a[i].num, now += a[i].r, maxn = i;
  }
  for (; i < n; i++) {
    now += a[i].l;
  }
  if (now < 0) {
    cout << ans << endl;
    return 0;
  }
  for (int i = maxn; i >= 0; i--) {
    if (now <= a[i].r - a[i].l) {
      cout << (ans - a[i].num * now) << endl;
      return 0;
    } else {
      now -= a[i].r - a[i].l, ans -= a[i].num * (a[i].r - a[i].l);
    }
  }
  return 0;
}