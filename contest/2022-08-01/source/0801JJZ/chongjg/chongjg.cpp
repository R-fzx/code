#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;
using ll = long long;
const int kN = 205, kM = kN * 21, kK = 1e3 + 5, kB = 27;

char s[kK * kK];
double b1[kK], b2[kK], ans[kN];
int n, t[kN * 10][kB], tot = 1, a[kM][kN], fail[kM], d[kM], up[kM];
struct Node {
  int x, y;
} p[kN];
void Fail () {
  int h = 0, w = 1;
  for (d[1] = 1; h < w; ) {
    int x = d[++h];
    for (int i = 1; i <= 26; i++) {
      if (t[x][i] != 0) {
        int y = t[x][i], z = fail[x];
        for ( ; z && !t[z][i]; z = fail[z]) {
        }
        fail[y] = (!t[z][i] ? 1 : t[z][i]), d[++w] = y, up[y] = y;
        (!t[y][0] && up[y] != 1) ? up[y] = up[fail[y]] : 0;
      }
    }
  }
}
void query (int m) {
  int x = 1;
  for (int i = 1, j; i <= m; i++) {
    for (j = s[i] - 'a' + 1; x != 1 && !t[x][j]; x = fail[x]) {
    }
    (t[x][j]) ? x = t[x][j] : 0;
    for (int k = up[x]; k; k = up[fail[x]]) {
      for (int i = 1; i <= a[k][0]; i++) {
        p[a[k][i]].x++;
      }
    }
  }
}
int main () {
  freopen ("chongjg.in", "r", stdin);
  freopen ("chongjg.out", "w", stdout);
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n;
  for (int i = 1, x, m; i <= n; i++) {
    cin >> s + 1, x = 1, m = strlen (s + 1);
    for (int j = 1; j <= m; j++) {
      (!t[x][s[j] - 'a' + 1]) ? t[x][s[j] - 'a' + 1] = ++tot : 0;
      x = t[x][s[j] - 'a' + 1];
    }
    t[x][0]++, a[x][++a[x][0]] = i;
  }
  Fail ();
  cin >> s + 1;
  int m = strlen (s + 1);
  query (m);
  for (int i = 1; i <= n; i++) {
    p[i].y = i;
  }
  sort (p + 1, p + n + 1, [&] (Node &p1, Node &p2) { return p1.x < p2.x; }), p[0].x = -1;
  double r; int l;
  cin >> r >> l, fill (b1, b1 + l + 1, 0);
  for (int i = 1; i <= n; i++) {
    b2[0] = 1;
    if (p[i].x == p[i - 1].x) {
      ans[p[i].y] = ans[p[i - 1].y];
      continue;
    }
    for (int j = 1; j <= i; j++) {
      b2[j] = b1[j - 1] + (b2[j - 1] - b1[j - 1]) * r;
    }
    for (int j = 1; j <= l; j++) {
      b1[j] = b2[j], b1[0] = 1;
    }
    ans[p[i].y] = b2[l];
  } 
  for_each (ans + 1, ans + n + 1, [&] (double &x) { cout << fixed << setprecision (3) << x << ' '; });
  return 0;
}