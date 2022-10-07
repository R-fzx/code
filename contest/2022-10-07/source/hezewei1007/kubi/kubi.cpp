#include <iostream>

using namespace std;

long long B[11][1000001], a, b, k, t;
long long num;

int main() {
  freopen("kubi.in", "r", stdin);
  freopen("kubi.out", "w", stdout);
  cin >> t;
  while (t--) {
    cin >> a >> b >> k;
    while (1) {
      if (a % b == 0) {
        cout << num << ' ' << 0 << endl;
        break;
      }
      else if (B[t][a % b]) {
        cout << B[t][a % b] - 1 << ' ' << num - B[t][a % b] + 1 << endl;
        break;
      } else {
        B[t][a % b] = ++num;
      }
      a *= k;
      a %= b;
    }
    num = 0;
  }
  return 0;
}