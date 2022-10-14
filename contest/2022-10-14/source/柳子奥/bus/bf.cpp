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
bool read(char &x) {
  while ((x = getc()) == ' ' || x == '\n' || x == '\r');
  return x != EOF;
}
bool read(char *x) {
  while ((*x = getc()) == '\n' || *x == ' ' || *x == '\r');
  if (*x == EOF) return 0;
  while (!(*x == '\n' || *x == ' ' || *x == '\r' || *x == EOF)) *(++x) = getc();
  *x = 0;
  return 1;
}
template<typename A, typename ...B> bool read(A &x, B &...y) { return read(x) && read(y...); }

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
template<typename A, typename ...B> void write(A x, B ...y) { write(x), write(y...); }
struct Flusher {
  ~Flusher() { flush(); }
} flusher;
} // namespace FASTIO
using FASTIO::read; using FASTIO::putc; using FASTIO::write;

typedef long long ll;

const int kMaxN = 1e5 + 5;

int n; ll ans;
int a[kMaxN];
ll f[kMaxN];
vector<int> v;

int main() {
  freopen("bus.in", "r", stdin);
  freopen("bf.out", "w", stdout);
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
  }
  memset(f, 0x3f, sizeof(f));
  f[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      f[i] = min(f[i], f[j] + 1ll * a[j + 1] * (i - j));
    }
  }
  write(f[n]);
  return 0;
}