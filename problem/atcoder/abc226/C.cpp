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

const int kN = 2e5 + 1;

int n;
LL t[kN], ans;
vector<int> e[kN];
bool v[kN];

void D(int x) {
  if (v[x]) {
    return;
  }
  v[x] = 1;
  for (int i : e[x]) {
    D(i);
  }
  ans += t[x];
}

int main() {
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, j; i <= n; ++i) {
    cin >> t[i] >> j;
    for (int k = 1, x; k <= j; ++k) {
      cin >> x;
      e[i].push_back(x);
    }
  }
  D(n);
  cout << ans;
#ifdef TIME
  double t = 1.0 * clock() / CLOCKS_PER_SEC;
  cerr << "\n\nTIME: " << t << "s\n";
#endif
  return 0;
}