#include <iostream>
#include <algorithm>
#include <cstring>

#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define put(x) (cout << (x) << '\n')
#define file(x) freopen (x".in", "r", stdin), freopen (x".out", "w", stdout)

using namespace std;
using Pii = pair <int, int>;
#define w first
#define p second
const int kN = 1e5 + 5;

bool col, row;
Pii pr[kN], pc[kN];
int n, m, t, c[kN], r[kN], ans, a, k;
int main () {
  file ("tanabata");
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n >> m >> t;
  for (int i = 1, C, R; i <= t; i++) {
    cin >> R >> C, c[C]++, r[R]++;
  }
  t % m || (col = true), t % n || (row = true);
  if (col && row) {
    cout << "both ";
  } else if (col) {
    cout << "column ";
  } else if (row) {
    cout << "row ";
  } else {
    cout << "impossible ";
  }
  if (row) {
    a = t / n, pr[0].w = 0;
    for (int i = 1; i <= n; i++) { pr[i] = {pr[i - 1].w + r[i], i}; }
    sort (pr, pr + n);
    k = (!n % 2 ? pr[(n + 1) /  2].p : pr[n / 2].p);
    for (int i = k, cur, nxt, t; i <= k + n - 1; i++) {
      cur = (i % n == 0 ? n : i % n);
      nxt = ((i + 1) % n == 0 ? n : (i + 1) % n);
      t = a - r[cur], r[cur] += t, r[nxt] -= t, ans += abs (t);
    } 
  }
  if (col) {
    a = t / m, pc[0].w = 0;
    for (int i = 1; i <= m; i++) { pc[i] = {pc[i - 1].w + c[i], i}; }
    sort (pc, pc + m);
    k = (!m % 2 ? pc[(m + 1) / 2].p : pc[m / 2].p);
    for (int i = k, cur, nxt, t; i <= k + m - 1; i++) {
      cur = (i % m == 0 ? m : i % m);
      nxt = ((i + 1) % m == 0 ? m : (i + 1) % m);
      t = a - c[cur], c[cur] += t, c[nxt] -= t, ans += abs (t);
    }
  }
  if (col || row) { put (ans); }
  return 0;
}