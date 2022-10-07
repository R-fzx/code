#include <bits/stdc++.h>
#define int long long
#define disx(a, b) min(abs(a - b), n + min(a, b) - max(a, b))
#define disy(a, b) min(abs(a - b), m + min(a, b) - max(a, b))
#define _leftx(x) x == 1 ? n : x - 1
#define _rightx(x) x == n ? 1 : x + 1
#define _lefty(y) y == 1 ? m : y - 1
#define _righty(y) y == m ? 1 : y + 1
using namespace std;
const int kMaxN(100009);
int n, m, t, cntx[kMaxN], cnty[kMaxN], tx0[kMaxN][2], tx1[kMaxN][2], ty0[kMaxN][2], ty1[kMaxN][2], ans;

inline int read() {
  char ch(getchar());
  int r(0);
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') r = (r << 1) + (r << 3) + ch - '0', ch = getchar();
  return r;
}
inline int findx0(int x, bool b) {
  return tx0[x][b] == x ? tx0[x][b] : tx0[x][b] = findx0(tx0[x][b], b);
}
inline int findx1(int x, bool b) {
  return tx1[x][b] == x ? tx1[x][b] : tx1[x][b] = findx1(tx1[x][b], b);
}
inline void delx(int a, int d) {
  if (abs(cntx[a]) == d) {
    tx0[a][cntx[a] < 0] = _leftx(a);
    tx1[a][cntx[a] < 0] = _rightx(a);
    cntx[a] = 0;
  } else {
    cntx[a] = cntx[a] < 0 ? cntx[a] + d : cntx[a] - d;
  }
}
inline void compairx(int a, int b) {
  int d(min(abs(cntx[a]), abs(cntx[b])));
  delx(a, d), delx(b, d);
  ans += d * disx(a, b);
  // cout<<a<<' '<<b<<' '<<d<<' '<<disx(a,b)<<'\n';
}
inline int fx(int x, int f, bool b) {
  for (int i(findx0(x, b)), j(findx1(x, b)); true;) {
    if (disx(x, i) < disx(x, j)) {
      if (i == f) {
        compairx(x, f);
        return cntx[x] == 0 ? f : fx(x, x, b);
      } else if (fx(i, x, !b) == x) {
        return cntx[x] == 0 ? i : fx(x, x, b);
      } else {
        i = findx0(i, b);
      }
    } else {
      if (j == f) {
        compairx(x, f);
        return cntx[x] == 0 ? f : fx(x, x, b);
      } else if (fx(j, x, !b) == x) {
        return cntx[x] == 0 ? i : fx(x, x, b);
      } else {
        j = findx1(j, b);
      }
    }
  }
}

inline int findy0(int y, bool b) {
  return ty0[y][b] == y ? ty0[y][b] : ty0[y][b] = findy0(ty0[y][b], b);
}
inline int findy1(int y, bool b) {
  return ty1[y][b] == y ? ty1[y][b] : ty1[y][b] = findy1(ty1[y][b], b);
}
inline void dely(int a, int d) {
  if (abs(cnty[a]) == d) {
    ty0[a][cnty[a] < 0] = _lefty(a);
    ty1[a][cnty[a] < 0] = _righty(a);
    cnty[a] = 0;
  } else {
    cnty[a] = cnty[a] < 0 ? cnty[a] + d : cnty[a] - d;
  }
}
inline void compairy(int a, int b) {
  int d(min(abs(cnty[a]), abs(cnty[b])));
  dely(a, d), dely(b, d);
  ans += d * disy(a, b);
  // cout<<a<<' '<<b<<' '<<d<<' '<<disy(a,b)<<'\n';
}
inline int fy(int y, int f, bool b) {
  for (int i(findy0(y, b)), j(findy1(y, b)); true;) {
    if (disy(y, i) < disy(y, j)) {
      if (i == f) {
        compairy(y, f);
        return cnty[y] == 0 ? f : fy(y, y, b);
      } else if (fy(i, y, !b) == y) {
        return cnty[y] == 0 ? i : fy(y, y, b);
      } else {
        i = findy0(i, b);
      }
    } else {
      if (j == f) {
        compairy(y, f);
        return cnty[y] == 0 ? f : fy(y, y, b);
      } else if (fy(j, y, !b) == y) {
        return cnty[y] == 0 ? i : fy(y, y, b);
      } else {
        j = findy1(j, b);
      }
    }
  }
}
/*
8 4 8
1 4
2 1
3 3
4 1
5 3
5 4
6 2
7 4
ans:both 5
*/
/*
5 4 10
1 1
4 1
5 1
4 2
2 3
3 3
4 3
1 4
4 4
5 4
ans:row 3
*/
signed main() {
  n = read(), m = read(), t = read();
  for (int i(0); i < t; i++) {
    int a(read()), b(read());
    cntx[a]++, cnty[b]++;
  }
  if (t % n == 0) {
    int cur(t / n);
    for (int i(1); i <= n; i++) {
      cntx[i] -= cur;
      tx0[i][1] = cntx[i] < 0 ? i : _leftx(i);
      tx1[i][1] = cntx[i] < 0 ? i : _rightx(i);
      tx0[i][0] = cntx[i] > 0 ? i : _leftx(i);
      tx1[i][0] = cntx[i] > 0 ? i : _rightx(i);
    }
    for (int i(1); i <= n; i++) {
      if (cntx[i] > 0) fx(i, i, 1);
    }
  }
  if (t % m == 0) {
    int cur(t / m);
    for (int i(1); i <= n; i++) {
      cnty[i] -= cur;
      ty0[i][1] = cnty[i] < 0 ? i : _lefty(i);
      ty1[i][1] = cnty[i] < 0 ? i : _righty(i);
      ty0[i][0] = cnty[i] > 0 ? i : _lefty(i);
      ty1[i][0] = cnty[i] > 0 ? i : _righty(i);
    }
    for (int i(1); i <= n; i++) {
      if (cnty[i] > 0) fy(i, i, 1);
    }
  }
  if (t % n == 0 || t % m == 0)
    cout << (t % n == 0 ? t % m == 0 ? "both " : "row " : "column ") << ans;
  else
    cout << "impossible";
  return 0;
}