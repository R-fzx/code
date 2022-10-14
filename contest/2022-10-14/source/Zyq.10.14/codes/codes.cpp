#include <bits/stdc++.h>
#define P pair<long long, int>
using namespace std;
int n, answ(INT32_MAX), del[23];
long long ans(LONG_LONG_MAX);
P a[23];
set<P> m;
inline int read() {
  int r(0);
  char ch(getchar());
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    r = (r << 1) + (r << 3) + ch - '0', ch = getchar();
  return r;
}
inline P change(string s) {
  long long r(0), p(0);
  for (int i(0); i < s.size(); i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      r = (r << 1) + s[i] - '0', p++;
    }
  }
  return {r, p};
}
inline string _change(P x) {
  string s("");
  for (int i(0); i < x.second; i++) {
    s = (char)((x.first & 1) + '0') + s, x.first >>= 1;
  }
  return s;
}
inline P add(P a, P b) {
  return {(a.first << b.second) + b.first, a.second + b.second};
}
inline void f(P x) {
  if (x.second > answ || (x.second == answ && ans < x.first)) {
    return;
  }
  if (m.count(x)) {
    answ = x.second, ans = x.first;
    return;
  }
  m.insert(x);
  for (int i(0); i < n; i++) {
    if (del[i]) {
      continue;
    }
    del[i] = 1;
    f(add(x, a[i]));
    del[i] = 0;
  }
}
signed main() {
  freopen("codes.in", "r", stdin), freopen("codes.out", "w", stdout);
  n = read();
  string str;
  for (int i(0); i < n; i++) {
    getline(cin, str), a[i] = change(str);
  }
  sort(a, a + n);
  f({0, 0});
  cout << answ << '\n' << _change({ans, answ});
  return 0;
}