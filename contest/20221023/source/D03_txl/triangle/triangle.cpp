#include <bits/stdc++.h>
using namespace std;
ifstream fin("triangle.in");
ofstream fout("triangle.out");
const int kMaxN = 1e5 + 1;
int n, q, s[kMaxN], l, r;
int main() {
  fin >> n >> q;
  for (int i = 1; i <= n; i++) {
    fin >> s[i];
  }
  while (q--) {
    fin >> l >> r;
    bool f = false;
    for (int i = l; i <= r; i++) {
      for (int j = i + 1; j <= r; j++) {
        for (int k = j + 1; k <= r; k++) {
          if (s[i] + s[j] > s[k] && s[i] + s[k] > s[j] && s[j] + s[k] > s[i]) {
            fout << "Yes\n";
            f = true;
            break;
          }
        }
        if (f) break;
      }
      if (f) break;
    }
    if (!f) {
      fout << "No\n";
    }
  }
  return 0;
}