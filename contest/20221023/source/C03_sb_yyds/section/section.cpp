#include <algorithm>
#include <fstream>

using namespace std;

constexpr int N = 1e6 + 5;

ifstream cin("section.in");
ofstream cout("section.out");

int n, m, q, ans, a[N];

int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int k, op; q--;) {
    cin >> op >> k;
    if (op == 1) {
      reverse(a + k, a + k + m);
    } else {
      ans ^= a[k];
    }
  }
  cout << ans;
  return 0;
}