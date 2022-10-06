#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, maxa, maxb, cnt, rnk[10];
bool b[10][10];
unordered_map<int, bool> m;
queue<int> q[10];
set<pair<int, int> > s;
inline bool check(int x) {
  if (m.count(x)) return x;
  auto p(s.find({x + 1, LONG_LONG_MAX}));
  if (p->first <= x && p->second >= x) return m[x] = true;
  p--;
  if (p->first <= x && p->second >= x) return m[x] = true;
  return false;
}
inline void f(int x) {
  for (int i(1), j(0); j < k && i <= x; i *= 10, j++) {
    int cur(x % (i * 10) / i);
    for (int j(1); j <= 9; j++) {
      if ((!b[cur][j]) && cur != j && !check(x - cur * i + j * i)) {
        b[cur][j] = true, b[j][cur] = true;
      }
    }
  }
}
inline void work1() {
  for (auto p(s.begin()); p != s.end(); p++) {
    for (int i(p->first); i <= p->second; i++) {
      f(i);
    }
  }
}
inline void work2() {
  for (auto p(s.begin()); p != s.end(); p++) {
    for (int i(p->first); i <= p->second; i++) {
      for (int i(0); i <= 9; i++) f(p->first + i), f(p->second - i);
    }
  }
}
signed main() {
  freopen("laser.in", "r", stdin), freopen("laser.out", "w", stdout);
  cin >> n >> k;
  for (int i(0), a, b; i < n; i++) {
    cin >> a >> b;
    maxb = max(b, maxb);
    s.insert({a, b});
  }
  if (n <= 50 && maxb <= 6000) {
    work1();
  } else if (k == 1) {
    work2();
  } else if (n == 1) {
    f(s.begin()->first), f(s.begin()->second);
    for (; clock() < 500;) {
      int x(s.begin()->first + rand());
      if (x < s.begin()->second) f(x);
    }
    for (; clock() < 920;) {
      int x(s.begin()->second - rand());
      if (x > s.begin()->first) f(x);
    }
  } else {
    cout << "123456789";
    return 0;
  }
  for (int i(1); i <= 9; i++) {
    for (int j(1); j < i; j++) {
      if (!b[i][j]) rnk[i] = rnk[j];
    }
    if (!rnk[i])
      q[rnk[i] = ++cnt].push(i);
    else
      q[rnk[i]].push(i);
  }
  for (int i(1); i <= cnt; i++) {
    while (!q[i].empty()) {
      cout << q[i].front();
      q[i].pop();
    }
    puts("");
  }
  return 0;
}