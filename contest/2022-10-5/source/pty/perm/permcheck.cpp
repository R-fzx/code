#include <algorithm>
#include <fstream>

using namespace std;
using LL = long long;

const int kMaxN = 51;

ifstream fin("perm.in");
ofstream fout("perm.out");

string s;
int c[kMaxN], n;
LL ans, sv;

void S(int i, int t, LL v) {
  if (i == t) {
    ans += v < sv;
    return;
  }
  for (int j = !i; j <= 9; j++) {
    if (c[j]) {
      c[j]--;
      S(i + 1, t, v * 10 + j);
      c[j]++;
    }
  }
}

int main() {
  fin >> s, n = s.size();
  for (int i = 0; i < n; i++) {
    sv = sv * 10 + s[i] - '0';
    c[s[i] -'0']++;
  }
  S(0, n, 0);
  while (c[0]) {
    c[0] --, n--;
    S(0, n, 0);
  }
  fout << ans;
  return 0;
}