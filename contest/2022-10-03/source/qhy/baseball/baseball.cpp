#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

int n;
ll r, ten, ans;

ll gcd(ll x, ll y) { return y == 0 ? x : gcd(y, x % y); }

int main() {
  ifstream cin("baseball.in");
  ofstream cout("baseball.out");
  while (cin >> n) {
    ld tmp;
    ans = INT64_MAX;
    cin >> tmp;
    r = tmp * (ten = pow(10, n + 1)) / 10, ten /= gcd(r * 10, ten);
    if (r == 0) {
      cout << 1 << '\n';
    }
    for (ll i = 2; i <= ten; i++) {
      for (ll j = 1; j < i; j++) {
        if ((ll)round((long double)j / i * pow(10, n)) == r) {
          cout << i << '\n';
          goto shit;
        }
      }
    }
  shit:;
  }

  return 0;
}