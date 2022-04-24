#include <iostream>

using namespace std;
using LL = long long;

const int kN = 1e5 + 1;

int t, n, c[11][11], a[kN][2];
LL s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    fill(&c[0][0], &c[10][10] + 1, s = 0);
    for (int i = 1; i <= n; ++i) {
      char x, y;
      cin >> x >> y;
      a[i][0] = x - 'a', a[i][1] = y - 'a';
      ++c[a[i][0]][a[i][1]];  // 累加出现次数
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= 10; ++j) {  // 枚举不同位
        if (j != a[i][0]) {
          s += c[j][a[i][1]];  // 第一位不同，第二位相同的情况
        }
        if (j != a[i][1]) {
          s += c[a[i][0]][j];  // 第一位相同，第二位不同的情况
        }
      }
    }
    cout << s / 2 << endl;
  }
  return 0;
}