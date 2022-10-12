#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif

using namespace std;

namespace FASTIO {
char ibuf[1 << 21], *p1 = ibuf, *p2 = ibuf;
char getc() {
  return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
}
template<class T> bool read(T &x) {
  x = 0; int f = 0; char ch = getc();
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getc();
  while (ch >= '0' && ch <= '9') x = (x * 10) + (ch ^ 48), ch = getc();
  x = (f ? -x : x); return 1;
}
template<typename A, typename ...B> bool read(A &x,B &...y) { return read(x) && read(y...); }

char obuf[1 << 21], *o1 = obuf, *o2 = obuf + (1 << 21) - 1;
void flush() { fwrite(obuf, 1, o1 - obuf, stdout), o1 = obuf; }
void putc(char x) { *o1++ = x; if (o1 == o2) flush(); }
template<class T> void write(T x) {
  if (!x) putc('0');
  if (x < 0) x = -x, putc('-');
  char c[40]; int tot = 0;
  while (x) c[++tot] = x % 10, x /= 10;
  for (int i = tot; i; --i) putc(c[i] + '0');
}
void write(char x) { putc(x); }
template<typename A,typename ...B> void write(A x, B ...y) { write(x), write(y...); }
struct Flusher {
  ~Flusher() { flush(); }
} flusher;
} // namespace FASTIO
using FASTIO::read; using FASTIO::putc; using FASTIO::write;

int n, m;
int f[1005];

int main() {
  srand(time(nullptr));
  freopen("castle.in", "w", stdout);
  n = 1000, m = n * (n - 1) / 2;
  cout << n << ' ' << m << endl;
  for (int i = 2; i <= n; ++i) {
    if (i == 2) f[i] = 1;
    else f[i] = rand() % (i - 2) + 1;
  }
  random_shuffle(f + 2, f + 1 + n);
  for (int i = 2; i <= n; ++i) {
    cout << i << ' ' << f[i] << ' ' << rand() % 1000 + 1 << endl;
  }
  for (int i = 1; i <= m - n + 1; ++i) {
    cout << rand() % n + 1 << ' ' << rand() % n + 1 << ' ' << rand() % 1000 + 1 << endl;
  }
  return 0;
}