#include <iostream>
#include <vector>

namespace utools {
using LL = long long;
class BigInteger {
  static const LL kB = 1000000000;
  static const int kL = 9;
  std::vector<LL> v;
  bool n;

public:
  BigInteger() {}
  BigInteger(LL x) {
    n = x < 0;
    for (v.push_back(x % kB); x /= kB; v.push_back(x % kB));
  }
  BigInteger(const std::string &s) {
    n = s[0] == '-';
    for (int i = n; i < s.size(); i += kL) {
      v.push_back(std::stoll(s.substr(i, kL)));
    }
  }
  const BigInteger& operator+(const BigInteger &o) const {
    BigInteger r;
    r.n = n | o.n;
    LL c = 0;
    for (int i = 0; i < std::max(v.size(), o.v.size()); ++i) {
      r.v.push_back((i < v.size() ? v[i] : 0) + (i < o.v.size() ? o.v[i] : 0) + c);
      c = r.v.back() / kB;
      r.v.back() %= kB;
    }
    if (c) r.v.push_back(c);
    return r;
  }
  const BigInteger& operator-(const BigInteger &o) const {
    BigInteger r;
    r.n = n ^ o.n;
    LL c = 0;
    for (int i = 0; i < std::max(v.size(), o.v.size()); ++i) {
      r.v.push_back((i < v.size() ? v[i] : 0) - (i < o.v.size() ? o.v[i] : 0) + c);
      c = r.v.back() / kB;
      r.v.back() %= kB;
    }
    if (c) r.v.push_back(c);
    return r;
  }
};
}  // namespace utools