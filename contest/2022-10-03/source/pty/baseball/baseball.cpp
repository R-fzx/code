#include <cmath>
#include <fstream>

using namespace std;
using LL = long long;

ifstream fin("baseball.in");
ofstream fout("baseball.out");

LL n, x, y, ans, v, a, b, _a, _b;
char c;

int main() {
  while (fin >> n >> x >> c >> x) {
    n = pow(10, n + 1);
    x = x * 10 - 5, y = x + 10;
    ans = n / x, a = x * ans, b = y * ans;
    while (b <= n) {
      _a = a, _b = b;
      ans++;
      a += x - n, b += y - n;
      v = (n - a) / x;
      ans += v;
      a += v * x, b += v * y;
      if (a > _a && b > _b) {
        LL vv = min((n - a) / (a - _a), (n - b) / (b - _b));
        ans += (v + 1) * vv;
        a += vv * (a - _a), b += vv * (b - _b);
      } else if (a < _a && b < _b) {
        LL vv = min((a - (n - x + 1)) / (_a - a), b / (_b - b));
        vv = max(vv, 0LL);
        ans += (v + 1) * vv;
        a -= vv * (_a - a), b -= vv * (_b - b);
      }
    }
    fout << ans << '\n';
  }
  return 0;
}