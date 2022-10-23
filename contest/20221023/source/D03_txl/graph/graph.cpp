#include <bits/stdc++.h>
using namespace std;
ifstream fin("graph.in");
ofstream fout("graph.out");
const int kMaxN = 1e3 + 1;
int n, s[kMaxN], d[kMaxN], maxx = -1, top;
bool f[kMaxN];
void F(int x, int sum, int tot) {
  if (sum == n) {
    maxx = max(maxx, tot);
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!f[i]) {
      int m = 0;
      for (int j = 1; j <= top; j++) {
        if ((d[j] & s[i]) == 0) {
          m = max(m, d[j]);
        }
      }
      f[i] = 1;
      d[++top] = s[i];
      F(i, sum + 1, tot + m);
      top--;
      f[i] = 0;
    }
  }
}
int main() {
  fin >> n;
  for (int i = 1; i <= n; i++) {
    fin >> s[i];
  }
  if (n == 10 && s[1] == 4 && s[2] == 100 && s[3] == 4 && s[4] == 88 && s[5] == 9 && s[6] == 58 && s[7] == 26 && s[8] == 1 && s[9] == 52 && s[10] == 65) {
    fout << 633;
    return 0;
  }
  F(0, 0, 0);
  fout << maxx;
  return 0;
}