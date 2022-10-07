#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("tanabata.in");
ofstream fout("tanabata.out");

const int kMaxN = 1e5 + 1;
const string kS[] = {"impossible", "row", "column", "both"};

int a[2][kMaxN], b[kMaxN], l[2], t, s;
long long ans;

void C(int o) {
  for (int i = 1; i <= l[o]; i++) {
    b[i] = b[i - 1] + a[o][i] - t / l[o];
  }
  sort(b + 1, b + 1 + l[o]);
  for (int i = 1; i <= l[o]; i++) {
    ans += abs(b[l[o] / 2 + 1] - b[i]);
  }
}

int main() {
  fin >> l[0] >> l[1] >> t;
  for (int i = 1, x, y; i <= t; i++) {
    fin >> x >> y;
    a[0][x]++, a[1][y]++;
  }
  for (int i = 0; i <= 1; i++) {
    if (t % l[i] == 0) {
      C(i), s |= 1 << i;
    }
  }
  fout << kS[s];
  if (s) {
    fout << ' ' << ans;
  }
  return 0;
}
