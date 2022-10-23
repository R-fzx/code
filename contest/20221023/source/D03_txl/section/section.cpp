#include <bits/stdc++.h>
using namespace std;
ifstream fin("section.in");
ofstream fout("section.out");
const int kMaxN = 1e6 + 1;
int n, m, q, s[kMaxN], o, l, sum;
int main() {
  fin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    fin >> s[i];
  }
  while (q--) {
    fin >> o >> l;
    if (o == 1) {
      int h = l, t = l + m - 1;
      while (h < t) {
        swap(s[h], s[t]);
        h++, t--;
      }
    } else {
      sum ^= s[l];
    }
  }
  fout << sum;
  return 0;
}