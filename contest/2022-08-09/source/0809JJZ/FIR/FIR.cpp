#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int kN = 1e3 + 5, kD[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool vis[kN][kN];
int n, k, X[kN], Y[kN], b[kN][kN], a[kN][kN];
bool BEE (int x, int y, int t) {
  vis[x][y] = true;
  for (int i = 0, dx, dy; i < 4; i++) {
    dx = x + kD[i][0], dy = y + kD[i][1];
    if (vis[dx][dy]) {
      continue;
    }
    if (!a[dx][dy]) {
      return vis[x][y] = false;
    }
    if (a[X[t]][Y[t]] == a[dx][dy] && !BEE (dx, dy, t)) {
      return vis[x][y] = false;
    }
  }
  vis[x][y] = false;
  return true;
}
void DEL (int x, int y, int t) {
  a[x][y] = 0;
  for (int i = 0, dx, dy; i < 4; i++) {
    dx = x + kD[i][0], dy = y + kD[i][1];
    (a[dx][dy] == ((t & 1) ? 1 : 2)) ? DEL (dx, dy, t) : void ();
  }
}
void EAT (int x, int y, int t) {
  for (int i = 0, dx, dy; i < 4; i++) {
    dx = x + kD[i][0], dy = y + kD[i][1];
    (a[dx][dy] && a[dx][dy] != a[x][y] && BEE (dx, dy, b[dx][dy])) ? DEL (dx, dy, b[dx][dy]) : void ();
  }
}
bool WIN (int t) {
  int c = 0, x = X[t], y = Y[t];
  for ( ; a[x][y] == a[X[t]][Y[t]] && c < k; c++, x--) {}
  x = X[t] + 1;
  for ( ; a[x][y] == a[X[t]][Y[t]] && c < k; c++, x++) {}
  if (c >= k) {
    return true;
  }
  c = 0, x = X[t], y = Y[t];
  for ( ; a[x][y] == a[X[t]][Y[t]] && c < k; c++, y--) {}
  y = Y[t] + 1;
  for ( ; a[x][y] == a[X[t]][Y[t]] && c < k; c++, y++) {}
  if (c >= k) {
    return true;
  }
  c = 0, x = X[t], y = Y[t];
  for ( ; a[x][y] == a[X[t]][Y[t]] && c < k; c++, x--, y--) {}
  x = X[t] + 1, y = Y[t] + 1;
  for ( ; a[x][y] == a[X[t]][Y[t]] && c < k; c++, x++, y++) {}
  if (c >= k) {
    return true;
  }
  c = 0, x = X[t], y = Y[t];
  for ( ; a[x][y] == a[X[t]][Y[t]] && c < k; c++, x--, y++) {}
  x = X[t] + 1, y = Y[t] + 1;
  for ( ; a[x][y] == a[X[t]][Y[t]] && c < k; c++, x++, y--) {}
  return c >= k;
}
int main () {
  freopen ("FIR.in", "r", stdin);
  freopen ("FIR.out", "w", stdout);
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> X[i] >> Y[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[X[i]][Y[i]]) {
      cout << "illegal" << '\n';
      return 0;
    }
    a[X[i]][Y[i]] = ((i & 1) ? 1 : 2);
    b[X[i]][Y[i]] = i, EAT (X[i], Y[i], i);
    if (BEE (X[i], Y[i], i)) {
      cout << "illegal" << '\n';
      return 0;
    }
    if (WIN (i)) {
      cout << ((i & 1) ? "ITer" : "Kitty") << ' ' << i << '\n';
      return 0;
    }
  }
  cout << "draw" << '\n';
  return 0;
}