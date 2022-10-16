#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

constexpr ll N = 7e5 + 5;

ll n, res = 1, a[N], s[N], ans[N], size[N];

vector<pll> e[N];

void dfs1(ll x, ll f) {
  size[x] = 1;
  ans[1] += s[x];
  for (auto&& i : e[x]) {
    if (i.first != f) {
      s[i.first] = s[x] + i.second - a[x];
      dfs1(i.first, x);
      size[x] += size[i.first];
    }
  }
}

void dfs2(ll x, ll f) {
  ans[x] < ans[res] && (res = x);
  for (auto&& i : e[x]) {
    if (i.first != f) {
      ans[i.first] = ans[x] - size[i.first] * (i.second - a[x]) +
                     (n - size[i.first]) * (i.second - a[i.first]);
      dfs2(i.first, x);
    }
  }
}

int main() {
  freopen("yggdrasil.in", "r", stdin);
  freopen("yggdrasil.out", "w", stdout);
  fill(s, s + N, 1e9);
  cin >> n;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (ll i = 1, x, y, z; i < n; i++) {
    cin >> x >> y >> z;
    e[x].push_back({y, z});
    e[y].push_back({x, z});
  }
  s[1] = 0;
  dfs1(1, -1);
  dfs2(1, -1);
  cout << res << '\n' << ans[res];
  return 0;
}