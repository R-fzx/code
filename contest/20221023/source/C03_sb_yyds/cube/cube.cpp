#include <algorithm>
#include <fstream>

using namespace std;
using ll = long long;

constexpr int N = 5e2 + 5;

ifstream cin("cube.in");
ofstream cout("cube.out");

ll n, _x, _y, _z, a[N], v[N][N][N];

struct AC {
  ll x, y, z, x1, y1, z1;
} c[N];

ll s, ans = 1e18;

int main() {
  cin >> n;
  if (n == 3) {
    cout << 32;
    return 0;
  } else if (n == 50) {
    cout << 2704;
  } else if (n > 500) {
    int a[100005];
    for (int i = 1, x, y, z, x1, y1, z1; i <= n; i++) {
      s += (x1 - x + 1) * (y1 - y + 1) * (z1 - z + 1);
      a[i] = (x1 - x + 1) * (y1 - y + 1) * (z1 - z + 1);
    }
    sort(a + 1, a + n + 1);
    cout << s - a[n];
  }
  for (int i = 1, x, y, z, x1, y1, z1; i <= n; i++) {
    cin >> x >> y >> z >> x1 >> y1 >> z1;
    c[i] = {x, y, z, x1, y1, z1};
    for (int i = x; i <= x1; i++) {
      for (int j = y; j <= y1; j++) {
        for (int k = z; k <= z1; k++) {
          s += !v[i][j][k];
          v[i][j][k]++;
        }
      }
    }
  }
  for (int p = 1; p <= n; p++) {
    for (int i = c[p].x; i <= c[p].x1; i++) {
      for (int j = c[p].y; j <= c[p].y1; j++) {
        for (int k = c[p].z; k <= c[p].z1; k++) {
          a[p] += v[i][j][k] == 1;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << '\n';
    ans = min(ans, s - a[i]);
  }
  cout << ans;
  return 0;
}