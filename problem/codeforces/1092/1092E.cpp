#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using Pii = pair<int, int>;

const int kN = 1001;

int n, m, s[kN], v[kN], p[kN], pl, d[kN], q[kN], h, t, l[kN];
bool b[kN];
vector<int> e[kN];
vector<Pii> ans;

int D(int x, int f) {
  int s = b[x] = 1;
  for (int i : e[x]) {
    if (i != f) {
      s += D(i, x);
    }
  }
  return s;
}
int C(int x, int f, int n) {
  v[x] = 1;
  for (int i : e[x]) {
    if (i != f) {
      v[x] += C(i, x, n), s[x] = max(s[x], v[i]);
    }
  }
  if (max(s[x], n - v[x]) <= n >> 1) {
    p[pl] = x;
  }
  return v[x];
}
void S(int x) {
  ++pl, fill(v + 1, v + n + 1, 0), fill(s + 1, s + n + 1, 0), C(x, 0, D(x, 0));
}
void R(int x, int _d) {
  if (d[x] == -1) {
    d[x] = _d, q[++t] = x;
  }
}
void B(int x) {
  fill(d + 1, d + n + 1, -1);
  for (h = 1, t = 0, R(x, 0); h <= t; ++h) {
    for (int i : e[q[h]]) {
      R(i, d[q[h]] + 1);
    }
  }
}
void L(int x) {
  B(x);
  int y = max_element(d + 1, d + n + 1) - d;
  B(y), l[pl] = *max_element(d + 1, d + n + 1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    if (!b[i]) {
      S(i), L(i);
    }
  }
  int x = max_element(l + 1, l + pl + 1) - l;
  for (int i = 1; i <= pl; ++i) {
    if (i != x) {
      ans.push_back({p[x], p[i]}), e[p[x]].push_back(p[i]), e[p[i]].push_back(p[x]);
    }
  }
  L(1);
  cout << l[pl] << endl;
  for (Pii &i : ans) {
    cout << i.first << " " << i.second << endl;
  }
  return 0;
}