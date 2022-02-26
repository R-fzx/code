#include <iostream>

using namespace std;

const int kN = 2e5 + 1;

int n, b[kN], t, m;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    m = max(m, x), b[t] == x ? (--t && b[t] < x && (b[++t] = -1)) : (b[++t] = x);
  }
  cout << (!t || t == 1 && b[1] == m ? "YES" : "NO");
  return 0;
}