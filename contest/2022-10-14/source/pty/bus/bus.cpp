#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("bus.in");
ofstream fout("bus.out");

const int kMaxN = 1e5 + 1;

int a[kMaxN], n;
long long ans;

int main() {
  fin >> n;
  for (int i = 1; i <= n; i++) {
    fin >> a[i];
  }
  for (int i = 1, m = a[1]; i <= n; i++) {
    m = min(m, a[i]);
    ans += m;
  }
  fout << ans;
  return 0;
}