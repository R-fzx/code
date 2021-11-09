// #define TIME
// #define DEBUG_
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <random>
#include <set>
#include <unordered_map>
#include <vector>
#ifdef DEBUG_
#define debug(format, ...) printf(format, ##__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using uLL = unsigned long long;
using uI = unsigned int;
using Pll = pair<LL, LL>;

// struct ModInt {
//   uLL b;
//   __uint128_t m;
//   ModInt(int mod) : b(mod), m(((__uint128_t)1 << 64) / mod) {}
// };
// uLL operator%(uLL a, ModInt b) {
//   uLL q = a - (b.m * a >> 64) * b.b;
//   return q >= b.b ? q - b.b : q;
// }
// uLL operator%=(uLL a, ModInt b) { return a = a % b; }
// const ModInt kMod1(1e9 + 7);
// const ModInt kMod2(998244353);

random_device rd;
mt19937 rnd(rd());
mt19937_64 rnd_64(rd());

namespace IO {
namespace IN {
#define getc() (p1 == p2 && (p2 = (p1 = buf) + inbuf->sgetn(buf, MAX_INPUT), p1 == p2) ? EOF : *p1++)
const int MAX_INPUT = 1000000;
char buf[MAX_INPUT], *p1, *p2;
template <typename T>
inline int redi(T &x) {
  static std::streambuf *inbuf = cin.rdbuf();
  register int f = x = 0, flag = 1;
  register char ch = getc();
  if (ch == EOF) return EOF;
  while (!std::isdigit(ch)) ch == '-' && (f = 1), ch = getc();
  if (std::isdigit(ch)) x = x * 10 + ch - '0', ch = getc(), flag = 0;
  while (std::isdigit(ch)) x = x * 10 + ch - 48, ch = getc();
  return x = f ? -x : x, ch == EOF ? EOF : flag;
}
template <typename T, typename... Args>
inline int redi(T &a, Args &...args) { return redi(a) != EOF ? redi(args...), 0 : EOF; }
inline int redc(char &ch) {
  static std::streambuf *inbuf = cin.rdbuf();
  return (ch = getc()) == EOF ? EOF : 0;
}
inline int redst(char *st) {
  if (redc(*st) != EOF && (*st))
    while (redc(*(++st)) != EOF) 1;
  else
    return EOF;
  return 0;
}
#undef getc
}  // namespace IN
namespace OUT {
template <typename T>
inline void put(T x) {
  static std::streambuf *outbuf = cout.rdbuf();
  static char stack[21];
  static int top = 0;
  if (x < 0) outbuf->sputc('-'), x = -x;
  if (!x) {
    outbuf->sputc('0'), outbuf->sputc('\n');
    return;
  }
  while (x) stack[++top] = x % 10 + '0', x /= 10;
  while (top) outbuf->sputc(stack[top]), --top;
  outbuf->sputc('\n');
}
inline void putc(const char ch) {
  static std::streambuf *outbuf = cout.rdbuf();
  outbuf->sputc(ch);
}
template <typename T>
inline void put_non(T x) {
  static std::streambuf *outbuf = cout.rdbuf();
  static char stack[21];
  static int top = 0;
  if (x < 0) outbuf->sputc('-'), x = -x;
  if (!x) {
    outbuf->sputc('0');
    return;
  }
  while (x) stack[++top] = x % 10 + '0', x /= 10;
  while (top) outbuf->sputc(stack[top]), --top;
}
template <typename T>
inline void put(const char ch, T x) {
  static std::streambuf *outbuf = cout.rdbuf();
  static char stack[21];
  static int top = 0;
  if (x < 0) outbuf->sputc('-'), x = -x;
  if (!x) {
    outbuf->sputc('0'), outbuf->sputc(ch);
    return;
  }
  while (x) stack[++top] = x % 10 + '0', x /= 10;
  while (top) outbuf->sputc(stack[top]), --top;
  outbuf->sputc(ch);
}
inline void putst(const char *st) {
  static std::streambuf *outbuf = cout.rdbuf();
  do {
    outbuf->sputc(*(st++));
  } while (*st);
}
template <typename T>
inline void put(const char *st, T x) {
  static std::streambuf *outbuf = cout.rdbuf();
  static char stack[21];
  static int top = 0;
  if (x < 0) outbuf->sputc('-'), x = -x;
  if (!x) {
    outbuf->sputc('0'), putst(st);
    return;
  }
  while (x) stack[++top] = x % 10 + '0', x /= 10;
  while (top) outbuf->sputc(stack[top]), --top;
  putst(st);
}
template <typename T, typename... Args>
inline void put(T a, Args... args) { put(a), put(args...); }
template <typename T, typename... Args>
inline void put(const char ch, T a, Args... args) { put(ch, a), put(ch, args...); }
template <typename T, typename... Args>
inline void put(const char *st, T a, Args... args) { put(st, a), put(st, args...); }
}  // namespace OUT
using IN::redc;
using IN::redi;
using IN::redst;
using OUT::put;
using OUT::put_non;
using OUT::putc;
using OUT::putst;
}  // namespace IO

const int kN = 5e5 + 1;

struct E {
  LL s;
  int l, r, ma, mb, sm, ct, ta[2], tb[2];
#define rt 1, 1, n
#define md (l + r >> 1)
#define ls (x << 1)
#define rs (x << 1 | 1)
} e[kN << 2];

int n, q, o, l, r, v;

void PushUp(int x) {
  e[x].ma = max(e[ls].ma, e[rs].ma), e[x].mb = max(e[ls].mb, e[rs].mb), e[x].s = e[ls].s + e[rs].s;
  if (e[ls].ma == e[rs].ma) {
    e[x].sm = max(e[ls].sm, e[rs].sm), e[x].ct = e[ls].ct + e[rs].ct;
  } else if (e[ls].ma > e[rs].ma) {
    e[x].sm = max(e[ls].sm, e[rs].ma), e[x].ct = e[ls].ct;
  } else {
    e[x].sm = max(e[rs].sm, e[ls].ma), e[x].ct = e[rs].ct;
  }
}

void Build(int x, int l, int r) {
  e[x].l = l, e[x].r = r;
  if (l == r) {
    IO::redi(e[x].mb), e[x].s = e[x].ma = e[x].mb, e[x].sm = INT32_MIN, e[x].ct = 1;
    return;
  }
  Build(ls, l, md), Build(rs, md + 1, r), PushUp(x);
}

void Update(int x, int ama, int amb, int ana, int anb) {
  e[x].s += 1LL * ama * e[x].ct + 1LL * ana * (e[x].r - e[x].l + 1 - e[x].ct);
  e[x].mb = max(e[x].mb, e[x].ma + amb), e[x].tb[0] = max(e[x].tb[0], e[x].ta[0] + amb);
  e[x].tb[1] = max(e[x].tb[1], e[x].ta[1] + anb);
  e[x].ma += ama, e[x].ta[0] += ama, e[x].ta[1] += ana;
  if (e[x].sm != INT32_MIN) {
    e[x].sm += ana;
  }
}

void PushDown(int x) {
  int mx = max(e[ls].ma, e[rs].ma);
  Update(ls, e[x].ta[mx != e[ls].ma], e[x].tb[mx != e[ls].ma], e[x].ta[1], e[x].tb[1]);
  Update(rs, e[x].ta[mx != e[rs].ma], e[x].tb[mx != e[rs].ma], e[x].ta[1], e[x].tb[1]);
  e[x].ta[0] = e[x].ta[1] = e[x].tb[0] = e[x].tb[1] = 0;
}

void Update_sum(int x, int l, int r, int v) {
  if (l > e[x].r || r < e[x].l) {
    return;
  }
  if (l <= e[x].l && e[x].r <= r) {
    Update(x, v, v, v, v);
    return;
  }
  PushDown(x), Update_sum(ls, l, r, v), Update_sum(rs, l, r, v), PushUp(x);
}

void Update_min(int x, int l, int r, int v) {
  if (l > e[x].r || r < e[x].l || v >= e[x].ma) {
    return;
  }
  if (l <= e[x].l && e[x].r <= r && v > e[x].sm) {
    Update(x, v - e[x].ma, v - e[x].ma, 0, 0);
  }
  PushDown(x), Update_min(ls, l, r, v), Update_min(rs, l, r, v), PushUp(x);
}

LL Query_sum(int x, int l, int r) {
  if (l > e[x].r || r < e[x].l) {
    return 0;
  }
  if (l <= e[x].l && e[x].r <= r) {
    return e[x].s;
  }
  PushDown(x);
  return Query_sum(ls, l, r) + Query_sum(rs, l, r);
}

int Query_max(int x, int l, int r) {
  if (l > e[x].r || r < e[x].l) {
    return INT32_MIN;
  }
  if (l <= e[x].l && e[x].r <= r) {
    return e[x].ma;
  }
  PushDown(x);
  return max(Query_max(ls, l, r), Query_max(rs, l, r));
}

int Query_maxb(int x, int l, int r) {
  if (l > e[x].r || r < e[x].l) {
    return INT32_MIN;
  }
  if (l <= e[x].l && e[x].r <= r) {
    return e[x].mb;
  }
  PushDown(x);
  return max(Query_maxb(ls, l, r), Query_maxb(rs, l, r));
}

int main() {
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  IO::redi(n), IO::redi(q);
  Build(rt);
  while (q--) {
    IO::redi(o), IO::redi(l), IO::redi(r);
    if (o == 1) {
      IO::redi(v), Update_sum(1, l, r, v);
    } else if (o == 2) {
      IO::redi(v), Update_min(1, l, r, v);
    } else if (o == 3) {
      IO::put(Query_sum(1, l, r));
    } else if (o == 4) {
      IO::put(Query_max(1, l, r));
    } else {
      IO::put(Query_maxb(1, l, r));
    }
  }
#ifdef TIME
  double t = 1.0 * clock() / CLOCKS_PER_SEC;
  cerr << "\n\nTIME: " << t << "s\n";
#endif
  return 0;
}