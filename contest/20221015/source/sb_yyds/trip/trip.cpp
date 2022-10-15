#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

constexpr ll N = 5005, M = 50005;

ll n, m, s, t, l, r, ra, __t, x[N], b[M], v[M], _r[M];

vector<pii> e[M];

bool check(ll x, ll y) {
  queue<ll> q;
  bool f = 0;
  fill(v, v + M, 0);
  fill(_r, _r + M, 1e9);
  _r[s] = 0;
  for (q.push(s); q.size(); q.pop()) {
    f |= q.front() == t;
    for (auto&& i : e[q.front()]) {
      if (i.second / 1000.0 >= x && i.second / 1000.0 <= y && !v[i.first]) {
        v[i.first] = 1;
        q.push(i.first);
      }
    }
  }
  return f;
}

int main() {
  freopen("trip.in", "r", stdin);
  freopen("trip.out", "w", stdout);
  cin >> n >> m;
  for (ll i = 1, x, y, z; i <= m; i++) {
    cin >> x >> y >> z;
    e[x].push_back({y, z * 1000});
    e[y].push_back({x, z * 1000});
  }
  for (ll i = 1, _t; i <= n; i++) {
    cin >> _t;
    __t += _t;
    for (ll x; _t--;) {
      cin >> x;
      b[x] = i;
    }
  }
  for (ll i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (ll i = 1; i <= __t; i++) {
    for (auto&& j : e[i]) {
      if (b[j.first] == b[i]) {
        j.second = j.second * x[b[i]] / 100;
      } else {
        j.second = j.second * ((x[b[i]] + x[b[j.first]]) / 200.0);
      }
      r = max(j.second, r) + 1;
    }
  }
  cin >> s >> t;
  ra = r;
  for (ll m = l + r + 1 >> 1; l < r; m = l + r + 1 >> 1) {
    if (check(m, 1e9)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  r = ra;
  ra = 0;
  for (ll m = ra + r >> 1; ra < r; m = ra + r >> 1) {
    if (check(l, m)) {
      r = m;
    } else {
      ra = m + 1;
    }
  }
  cout << l << ' ' << ra;
  return 0;
}