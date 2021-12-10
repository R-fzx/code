// #define TIME
// #define DEBUG_
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
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

random_device rd;
mt19937 rnd(rd());
mt19937_64 rnd_64(rd());

namespace IO {
namespace IN {
#define getc() (p1 == p2 && (p2 = (p1 = buf) + inbuf->sgetn(buf, MAX_INPUT), p1 == p2) ? EOF : *p1++)
const int MAX_INPUT = 1000000;
char buf[MAX_INPUT], *p1, *p2;
template <typename T>
inline int redi(T& x) {
  static std::streambuf* inbuf = cin.rdbuf();
  bool f = x = 0, flag = 1;
  char ch = getc();
  if (ch == EOF) return EOF;
  while (!std::isdigit(ch)) f |= ch == '-', ch = getc();
  if (std::isdigit(ch)) x = x * 10 + ch - '0', ch = getc(), flag = 0;
  while (std::isdigit(ch)) x = x * 10 + ch - 48, ch = getc();
  return x = f ? -x : x, ch == EOF ? EOF : flag;
}
inline int redc(char& ch) {
  static std::streambuf* inbuf = cin.rdbuf();
  return (ch = getc()) == EOF ? EOF : 0;
}
inline int redst(string& s) {
  s = "";
  char c;
  for (; redc(c) != EOF && !isspace(c); s.push_back(c)) 1;
  return c == EOF ? EOF : 0;
}
#undef getc
}  // namespace IN
namespace OUT {
inline void putc(const char ch) {
  static std::streambuf* outbuf = cout.rdbuf();
  outbuf->sputc(ch);
}
template <typename T>
inline void put_non(T x) {
  static char stack[21];
  static int top = 0;
  if (x < 0) putc('-'), x = -x;
  if (!x) {
    putc('0');
    return;
  }
  while (x) stack[++top] = x % 10 + '0', x /= 10;
  while (top) putc(stack[top]), --top;
}
inline void putst(const char* st) {
  do putc(*(st++));
  while (*st);
}
inline void putst(string st) { putst(st.c_str()); }
}  // namespace OUT
using IN::redc;
using IN::redi;
using IN::redst;
using OUT::put_non;
using OUT::putc;
using OUT::putst;
}  // namespace IO
namespace Prime {
const int kN = 25;
const LL kTs[kN] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
LL pow(LL a, LL p, LL mod) {
  LL s = 1;
  for (; p; p >>= 1, a = a * a % mod) (p & 1) && (s = s * a % mod);
  return s % mod;
}
bool IsPrime(LL P) {
  if (P == 1) return 0;
  LL t = P - 1, k = 0;
  while (!(t & 1)) ++k, t >>= 1;
  for (LL i = 0; i < kN; i++) {
    if (P == kTs[i]) return 1;
    LL a = pow(kTs[i], t, P), nxt = a;
    for (LL j = 1; j <= k; j++) {
      nxt = a * a % P;
      if (nxt == 1 && a != 1 && a != P - 1) return 0;
      a = nxt;
    }
    if (a != 1) return 0;
  }
  return 1;
}
}  // namespace Prime
using Prime::IsPrime;

LL Pow(LL b, LL e, LL m) {
  LL s = 1;
  for (; e; e >>= 1, b = b * b % m) (e & 1) && (s = s * b % m);
  return s;
}
template <typename T>
T Cmin(T& x, T y) { return x = min(x, y); }
template <typename T>
T Cmax(T& x, T y) { return x = max(x, y); }
template <typename T>
T Max(T x) { return x; }
template <typename T>
T Min(T x) { return x; }
template <typename T, typename... _T>
T Max(T x, _T... y) { return max(x, Max(y...)); }
template <typename T, typename... _T>
T Min(T x, _T... y) { return min(x, Min(y...)); }

int main() {
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
#ifdef TIME
  double t = 1.0 * clock() / CLOCKS_PER_SEC;
  cerr << "\n\nTIME: " << t << "s\n";
#endif
  return 0;
}