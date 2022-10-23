#include <algorithm>
#include <fstream>

using namespace std;
using ll = long long;

constexpr int N = 1e5 + 5;

ifstream cin("triangle.in");
ofstream cout("triangle.out");

ll n, q, a[N], c[N];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int l, r, f = 0; q--; f = 0) {
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
      c[i] = a[i];
    }
    sort(c + l, c + r + 1);
    for (int i = l; i <= r - 3 && !f; i++) {
      f = c[i] + c[i + 1] > c[i + 2];
    }
    cout << (f ? "Yes\n" : "No\n");
  }
  return 0;
}