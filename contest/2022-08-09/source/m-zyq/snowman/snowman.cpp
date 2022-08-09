#include <bits/stdc++.h>
#define down 0.996
using namespace std;
int n, _n, v[500009], l[500009], k[500009];
map<pair<int, int>, int> m;
inline int read() {
  int r(0);
  char ch(getchar());
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') r = (r << 1) + (r << 3) + ch - '0', ch = getchar();
  return r;
}
struct E {
  int l1, l2;
} ans;
int answ;
inline int check(E cur) {
  if (m.count(make_pair(cur.l1, cur.l2))) return min(m[make_pair(cur.l1, cur.l2)], cur.l2 - cur.l1);
  if (l[cur.l1] != l[cur.l2]) return min(m[make_pair(cur.l1, cur.l2)] = min(l[cur.l1], l[cur.l2]), cur.l2 - cur.l1);
  int cnt(l[cur.l1]);
  for (; cur.l2 + cnt < n; cnt++) {
    if (cnt > cur.l2 - cur.l1) return cur.l2 - cur.l1;
    if (v[cur.l1] - v[cur.l2] != v[cur.l1 + cnt] - v[cur.l2 + cnt]) break;
  }
  return cnt;
}
inline int check(int l1, int l2) {
  if (l[l1] != l[l2]) return min(min(l[l1], l[l2]), l2 - l1);
  int cnt(l[l1]);
  for (; l2 + cnt < n; cnt++) {
    if (cnt > l2 - l1) return l2 - l1;
    if (v[l1] - v[l2] != v[l1 + cnt] - v[l2 + cnt]) break;
  }
  return cnt;
}
inline void sa() {
  double t = 3000;
  E e = {-1, -1};
  srand(time(0));
  while (t > 1e-15 && clock() < 1920) {
    while (true) {
      e.l1 = ans.l1 + (rand() % (_n << 1) - _n), e.l2 = ans.l2 + (rand() % (_n << 1) - _n);
      if (e.l1 >= 0 && e.l2 >= 0 && e.l1 < e.l2 && max(e.l1, e.l2) < n) break;
    }
    int ew = check(e);
    int de = ew - answ;
    if (de > 0) {
      ans = e;
      answ = ew;
    } else if (exp(-de / t) * RAND_MAX > rand()) {
      ans = e;
    }
    t *= down;
  }
}
inline void solve(){
  for (; clock() < 1850;) sa();
}
inline void work(){
  for (int i(0); i < n; i++) {
    for (int j(i + 1); j < n; j++) {
      if (n - j < answ) break;
      answ=max(answ,check(i,j));
    }
    if (n - i < answ||clock()>1990)break;//
  }
}
int main() {
  freopen("snowman.in", "r", stdin), freopen("snowman.out", "w", stdout);
  cout.tie(0);
  n = read(), _n = max(pow(n,0.7),2.0), ans = (E){n / 2, n / 2 + 1};
  for (int i(0); i < n; i++) {
    v[i] = read();
  }
  l[0] = n, k[0] = 1;
  for (int i(1); i < n; i++) {
    int dis = v[0] - v[1];
    k[i] = min(k[i - 1], n - i), l[i] = k[i];
    for (int j(i - 1 + k[i]); j < n; j++) {
      if (v[j - i] - v[j] == v[j - i + 1] - v[j + 1])
        l[i]++;
      else
        break;
      if (v[j] - v[j + 1] == dis) k[i]++;
    }
  }
  if(n>=28000)solve();
  else work();
  cout << answ;
  return 0;
}
