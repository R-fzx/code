#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 25e3 + 1, kMaxM = kMaxN * 400;

struct V {
  vector<Pii> a;
  int e[2];
} v[kMaxM];
int t[kMaxN], n, m = 1, l;
string s;

void I(int i) {
  for (int x = 1, p = i; p <= min(n, i + l - 1); p++) {
    if (!v[x].e[s[p] - '0']) {
      v[x].e[s[p] - '0'] = ++m;
    }
    x = v[x].e[s[p] - '0'];
    v[x].a.push_back({i, p});
  }
}

int C(int x) {
  int r = 0;
  for (; x; x -= x & -x) {
    r = max(r, t[x]);
  }
  return r;
}

void U(int x, int v) {
  for (; x <= n; x += x & -x) {
    t[x] = max(t[x], v);
  }
}

void S(int x) {
  if (x == 0) {
    return;
  }
  sort(v[x].a.begin(), v[x].a.end());
  for (auto i = v[x].a.rbegin(); i != v[x].a.rend(); i++) {
    U(i->second, C(i->first - 1) + 1);
  }
  S(v[x].e[0]), S(v[x].e[1]);
}

int main() {
  cin >> n >> s, s = ' ' + s;
  for (l = 1; (l + 2) * (l + 1) / 2 <= n; l++) {
  }
  for (int i = 1; i <= n; i++) {
    I(i);
  }
  S(1);
  cout << C(n);
  return 0;
}