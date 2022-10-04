#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

ifstream fin("puppet.in");
ofstream fout("puppet.out");

const int kMaxN = 51;

int a[kMaxN], b[kMaxN], n, ans;

int main() {
  while (fin >> n) {
    for (int i = 1; i <= n; i++) {
      fin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    copy(a + 1, a + 1 + n, b + 1);
    ans = n;
    for (int i = 1; i <= n; i++) {
      for (int j = n; j >= 1; j--) {
        if (abs(b[j] - a[i]) <= 1) {
          b[j] = 1e9;
          ans--;
          break;
        }
      }
    }
    fout << ans << '\n';
  }
  return 0;
}
