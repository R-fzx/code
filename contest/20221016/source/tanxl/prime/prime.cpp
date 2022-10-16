#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 1e5 + 1;
long long q, x, d[kMaxN][2], fz, fm;
bool P(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
void G(long long l, long long r) {
  if (fz == 0 && fm == 0) {
    fz = r, fm = l;
    return;
  }
  if (l == fm) {
    fz += r;
    return;
  } else {
    for (int i = max(fm, l); i <= fm * l; i++) {
      if (i % l == 0 && i % fm == 0) {
        fz = fz * (i / fm);
        fz += (i / l) * r;
        fm = i;
        return;
      }
    }
  }
}
void W() {
  for (int i = min(fz, fm); i >= 2; i--) {
    if (fz % i == 0 && fm % i == 0) {
      fz /= i, fm /= i;
    }
  }
}
int main() {
  freopen("prime.in", "r", stdin);
  freopen("prime.out", "w", stdout);
  cin >> q;
  while (q--) {
    cin >> x;
    fz = 0, fm = 0;
    for (int i = 2; i <= x; i++) {
      long long l, r;
      if (d[i][1] && d[i][0]) {
        l = d[i][1], r = d[i][0];
      } else {
        long long p;
        for (int j = x; j >= 2; j--) {
          if (P(j)) {
            p = j;
            break;
          }
        }
        for (int j = x + 1;; j++) {
          if (P(j)) {
            p *= j;
            break;
          }
        }
        d[i][1] = p, d[i][0] = 1;
        l = d[i][1], r = d[i][0];
      }
      G(l, r);
    }
    W();
    if (fz == fm) {
      cout << 1 << '\n';
    } else {
      cout << fz << '/' << fm << '\n';
    }
  }
  return 0;
}