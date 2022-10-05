#include <algorithm>
#include <fstream>

using namespace std;
using LL = long long;

const int kMaxN = 801;

ifstream fin("scalar.in");
ofstream fout("scalar.out");

int a[kMaxN], b[kMaxN], n;
LL ans;

int main() {
  fin >> n;
  for (int i = 1; i <= n; i++) {
    fin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    fin >> b[i];
  }
  sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; i++) {
    ans += (LL)a[i] * b[n - i + 1];
  }
  fout << ans;
  return 0;
}