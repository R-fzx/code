#include <iostream>

using namespace std;

long long n, a[100001], R, ans;

pair<long long, long long> tree[400001], tmp;

pair<long long, long long> Build(long long x, long long l, long long r) {
  if (l == r) {
    tree[x] = {a[l], l};
  } else {
    tree[x] = min(Build(x * 2, l, l + r >> 1), Build(x * 2 + 1, (l + r >> 1) + 1, r));
  }
  return tree[x];
}

pair<long long, long long> Find(long long x, long long l, long long r) {
  if (1 <= l && r <= R) {
    return tree[x];
  } else if (R < l || r < 1) {
    return {1e18 + 7, 1e18 + 7};
  }
  return min(Find(x * 2, l, l + r >> 1), Find(x * 2 + 1, (l + r >> 1) + 1, r));
}

int main() {
  freopen("bus.in", "r", stdin);
  freopen("bus.out", "w", stdout);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  Build(1, 1, n);
  R = n;
  while (R) {
    tmp = Find(1, 1, n);
    ans += (R - tmp.second + 1) * tmp.first;
    R = tmp.second - 1;
  }
  cout << ans << endl;
  return 0;
}