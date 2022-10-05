#include <iostream>
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;

const int kN = 51;

string n;
LL ans;
int c[10], _c[10];

int main() {
  RF("perm");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (char i : n) {
    ++c[i - '0'];
  }
  for (int i = 0; i < n.size(); ++i) {
    int x = n[i] - '0';
    for (int j = 0; j < x; ++j) {
      if (c[j]) {
        long double s = 1;
        for (int k = 0, p = 1; k < 10; ++k) {
          for (_c[k] = c[k] - (k == j); _c[k]; s *= p++, s /= _c[k]--) {
          }
        }
        ans += s;
      }
    }
    --c[x];
  }
  cout << ans;
  return 0;
}