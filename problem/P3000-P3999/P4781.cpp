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
template <>
inline int redi<double>(double& x) {
  static std::streambuf* inbuf = cin.rdbuf();
  LL y, z;
  int _y = redi(y), _z = redi(z);
  if (_y == EOF || _z == EOF) {
    return EOF;
  }
  
  return ;
}
template <typename T, typename... Args>
inline int redi(T& a, Args&... args) { return redi(a) != EOF ? redi(args...), 0 : EOF; }
inline int redc(char& ch) {
  static std::streambuf* inbuf = cin.rdbuf();
  return (ch = getc()) == EOF ? EOF : 0;
}
inline int redst(char* st) {
  if (redc(*st) != EOF && (*st))
    while (redc(*(++st)) != EOF) 1;
  else
    return EOF;
  return 0;
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
template <typename T>
inline void put(const char ch, T x) { put_non(x), putc(ch); }
template <typename T>
inline void put(T x) { put('\n', x); }
inline void putst(const char* st) {
  do putc(*(st++));
  while (*st);
}
inline void putst(string st) { putst(st.c_str()); }
template <typename T>
inline void put(const char* st, T x) { put_non(x), putst(st); }
template <typename T, typename... Args>
inline void put(T a, Args... args) { put(a), put(args...); }
template <typename T, typename... Args>
inline void put(const char ch, T a, Args... args) { put(ch, a), put(ch, args...); }
template <typename T, typename... Args>
inline void put(const char* st, T a, Args... args) { put(st, a), put(st, args...); }
}  // namespace OUT
using IN::redc;
using IN::redi;
using IN::redst;
using OUT::put;
using OUT::put_non;
using OUT::putc;
using OUT::putst;
}  // namespace IO
struct BigUint {
  using _Type = vector<uLL>;
  static const uLL BASE = 100000000, WIDTH = 8;
  _Type s;
  int len;
  const BigUint& clean() {
    while (!s.back() && s.size() > 1) s.pop_back();
    return *this;
  }
  BigUint(const uLL num = 0) { *this = num; }
  BigUint(const string& s) { *this = s; }
  BigUint(const _Type& b) { *this = b; }
  const BigUint& operator=(uLL num) {
    s.clear();
    long long t = num;
    while (t) t /= 10, len++;
    do s.push_back(num % BASE), num /= BASE;
    while (num > 0);
    return *this;
  }
  const BigUint& operator=(const string& str) {
    s.clear();
    int x, l = ((len = str.length()) - 1) / WIDTH + 1;
    for (int i = 0, end, start; i < l; i++) end = str.length() - i * WIDTH, start = max(0uLL, end - WIDTH), sscanf(str.substr(start, end - start).c_str(), "%d", &x), s.push_back(x);
    return this->clean();
  }
  const BigUint& operator=(const _Type& b) { return s = b, this->clean(); }
  const BigUint& operator+(const BigUint& b) const {
    BigUint c;
    c.s.clear();
    for (int i = 0, g = 0, x; g || i < s.size() || i < b.s.size(); i++) x = g, i < s.size() && (x += s[i]), i < b.s.size() && (x += b.s[i]), c.s.push_back(x % BASE), g = x / BASE;
    return c;
  }
  const BigUint& operator-(const BigUint& b) const {
    assert(b <= *this);
    BigUint c;
    c.s.clear();
    for (int i = 0, g = 0, x; g || i < s.size() || i < b.s.size(); i++) x = s[i] + g, i < b.s.size() && (x -= b.s[i]), x < 0 ? (g = -1, x += BASE) : (g = 0), c.s.push_back(x);
    return c.clean();
  }
  const BigUint& operator*(const BigUint& b) const {
    int i, j;
    uLL g, x;
    _Type v(s.size() + b.s.size(), 0);
    BigUint c;
    c.s.clear();
    for (i = 0; i < s.size(); i++)
      for (j = 0; j < b.s.size(); j++) v[i + j] += (uLL)(s[i]) * b.s[j];
    for (i = 0, g = 0; g || i < v.size(); i++) x = v[i] + g, c.s.push_back(x % BASE), g = x / BASE;
    return c.clean();
  }
  int bsearch(const BigUint& b, const BigUint& m) const {
    int x;
    for (int L = 0, R = BASE - 1; x = (L + R) >> 1, b * x > m || b * (x + 1) <= m; (b * x <= m ? L : R) = x) 1;
    return x;
  }
  const BigUint& operator/(const BigUint& b) const {
    assert(b > 0);
    BigUint c = *this, m;
    for (int i = s.size() - 1; i >= 0; i--) m = m * BASE + s[i], c.s[i] = bsearch(b, m), m -= b * c.s[i];
    return c.clean();
  }
  const BigUint& operator%(const BigUint& b) const {
    BigUint c = *this, m;
    for (int i = s.size() - 1; i >= 0; i--) m = m * BASE + s[i], c.s[i] = bsearch(b, m), m -= b * c.s[i];
    return m;
  }
  static const _Type& to_bit(const BigUint& b) {
    _Type s;
    uLL j;
    for (BigUint x = b; x.clean(), x != (j = 0); s.push_back(j))
      for (uLL i = x.s.size() - 1; i >= 0; --i, j = j * BASE + x.s[i], x.s[i] = j >> 1, j &= 1) 1;
    return s;
  }
  static const BigUint& to_dec(const _Type& b) {
    BigUint s;
    uLL j;
    for (BigUint x = b; x.clean(), x != (j = 0); s.s.push_back(j))
      for (uLL i = x.s.size() - 1; i >= 0; --i, j = j * BASE + x.s[i], x.s[i] = j >> 1, j &= 1) 1;
    return s.clean();
  }
#define GET(x) (x.size() > i ? x[i] : 0)
  const BigUint& operator|(const BigUint& b) const {
    _Type _x = to_bit(*this), _y = to_bit(b), s;
    for (int i = 0; i < max(_x.size(), _y.size()); s.push_back(GET(_x) | GET(_y)), ++i) 1;
    return to_dec(s);
  }
  const BigUint& operator&(const BigUint& b) const {
    _Type _x = to_bit(*this), _y = to_bit(b), s;
    for (int i = 0; i < max(_x.size(), _y.size()); s.push_back(GET(_x) & GET(_y)), ++i) 1;
    return to_dec(s);
  }
  const BigUint& operator^(const BigUint& b) const {
    _Type _x = to_bit(*this), _y = to_bit(b), s;
    for (int i = 0; i < max(_x.size(), _y.size()); s.push_back(GET(_x) ^ GET(_y)), ++i) 1;
    return to_dec(s);
  }
  const BigUint& operator~() const {
    _Type _x = to_bit(*this);
    for (int i = 0; i < _x.size(); ++i) _x[i] = !_x[i];
    return to_dec(_x);
  }
  const BigUint& operator<<(const int b) const {
    _Type _x = to_bit(*this), s = _Type(b, 0uLL);
    for (uLL x : _x) s.push_back(x);
    return to_dec(s);
  }
  const BigUint& operator>>(const int b) const {
    _Type _x = to_bit(*this), s;
    for (int i = b; i < _x.size(); ++i) s.push_back(_x[i]);
    return to_dec(s);
  }
  const BigUint& operator+=(const BigUint& b) { return (*this) = (*this) + b; }
  const BigUint& operator-=(const BigUint& b) { return (*this) = (*this) - b; }
  const BigUint& operator*=(const BigUint& b) { return (*this) = (*this) * b; }
  const BigUint& operator/=(const BigUint& b) { return (*this) = (*this) / b; }
  const BigUint& operator%=(const BigUint& b) { return (*this) = (*this) % b; }
  const BigUint& operator|=(const BigUint& b) { return (*this) = (*this) | b; }
  const BigUint& operator&=(const BigUint& b) { return (*this) = (*this) & b; }
  const BigUint& operator^=(const BigUint& b) { return (*this) = (*this) ^ b; }
  const BigUint& operator++() { return *this += 1; }
  const BigUint& operator++(int) {
    const BigUint& x = *this;
    return ++*this, x;
  }
  const BigUint& operator--() { return *this -= 1; }
  const BigUint& operator--(int) {
    const BigUint& x = *this;
    return --*this, x;
  }
  const BigUint& operator<<=(const int b) { return *this = *this << b; }
  const BigUint& operator>>=(const int b) { return *this = *this >> b; }
  bool operator<(const BigUint& b) const {
    if (s.size() != b.s.size()) return s.size() < b.s.size();
    for (int i = s.size() - 1; i >= 0; i--)
      if (s[i] != b.s[i]) return s[i] < b.s[i];
    return false;
  }
  bool operator>(const BigUint& b) const { return b < *this; }
  bool operator<=(const BigUint& b) const { return !(b < *this); }
  bool operator>=(const BigUint& b) const { return !(*this < b); }
  bool operator!=(const BigUint& b) const { return b < *this || *this < b; }
  bool operator==(const BigUint& b) const { return !(b < *this) && !(b > *this); }
  void read() {
    string _s;
    IO::redst(_s), *this = _s;
  }
  void write() {
    clean(), IO::put_non(s.back());
    for (int i = s.size() - 2; ~i; --i) {
      char sc[20];
      sprintf(sc, "%08d", s[i]), IO::putst(sc);
    }
  }
};
namespace Prime {
const int kN = 25;
const LL kTs[kN] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
LL pow(LL a, LL p, LL mod) {
  LL s = 1;
  for (; p; p >>= 1, a = a * a % mod) (p & 1) && (s = s * a % mod);
  return s % mod;
}
bool is_prime(LL P) {
  if (P == 1) return 0;
  LL t = P - 1, k = 0;
  while (!(t & 1)) k++, t >>= 1;
  for (LL i = 0; i < kN; i++) {
    if (P == kTs[i]) return 1;
    LL a = pow(kTs[i], t, P), nxt = a;
    for (LL j = 1; j <= k; j++) {
      nxt = (a * a) % P;
      if (nxt == 1 && a != 1 && a != P - 1) return 0;
      a = nxt;
    }
    if (a != 1) return 0;
  }
  return 1;
}
}  // namespace Prime
using Prime::is_prime;

const int kN = 2001;
const LL kM = 998244353;

int n, k;
double x[kN], y[kN], s;

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