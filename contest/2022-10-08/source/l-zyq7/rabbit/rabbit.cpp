#include <bits/stdc++.h>
using namespace std;

int n, ans;
short cnt[1000][1000], d[1000];

inline void write(int x) {
  if (x > 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void add(int a, int b, int c) {
  cnt[a][b]++, cnt[b][a]++, cnt[a][c]++, cnt[c][a]++, cnt[b][c]++, cnt[c][b]++;
  d[a]++, d[b]++, d[c]++;
}
inline void del(int a, int b, int c) {
  cnt[a][b]--, cnt[b][a]--, cnt[a][c]--, cnt[c][a]--, cnt[b][c]--, cnt[c][b]--;
  d[a]--, d[b]--, d[c]--;
}
map<unsigned long long, int> mp;
inline unsigned long long hsh() {
  unsigned long long r(0);
  for (int i(1), j(1); i <= n; i++, j *= n) {
    r += d[i] * j;
  }
  return r;
}
inline bool f(int bs) {
  map<pair<short, pair<short, short> >, bool> m;
  unsigned long long h(hsh());
  if (mp.count(h) && mp[h] >= bs) return false;
  if (ans == bs) return true;
  mp[h] = bs;
  // cout << ans << '\n';
  for (int i(1); i <= n; i++) {
    for (int j(i + 1); j <= n; j++) {
      for (int k(j + 1); k <= n; k++) {
        int a(i), b(j), c(k);
        if (cnt[a][b] >= 3 || cnt[a][c] >= 3 || cnt[b][c] >= 3) continue;
        if (d[a] > d[b]) swap(a, b);
        if (d[b] > d[c]) swap(b, c);
        if (d[a] > d[b]) swap(a, b);
        if (m[{d[a], {d[b], d[c]}}]) continue;
        m[{d[a], {d[b], d[c]}}] = true;
        add(i, j, k);
        if (f(bs + 1)) {
          cout << a << ' ' << b << ' ' << c << '\n';
          return true;
        }
        del(i, j, k);
      }
    }
  }
  return false;
}
int main() {
  freopen("rabbit.in", "r", stdin), freopen("rabbit.out", "w", stdout);
  cin.tie(0), cout.tie(0);
  cin >> n;
  ans = n * (n - 4);
	cout << ans << '\n';
  f(0);
  return 0;
}