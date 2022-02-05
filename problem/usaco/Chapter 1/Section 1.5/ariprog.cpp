/*
ID: wsfxk.e1
LANG: C++
TASK: ariprog
*/
#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;
using Pll = pair<int, int>;

const int kM = 125001, kL = 10001;

int n, m, t, a[kM], k;
bool b[kM];
Pll l[kL];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ifstream fin("ariprog.in");
  ofstream fout("ariprog.out");
  fin >> n >> m;
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= m; ++j) {
      bool &f = b[i * i + j * j];
      if (!f) {
        a[++k] = i * i + j * j, f = 1;
      }
    }
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= 3000; ++j) {
      if (a[i] + j * (n - 1) > kM) {
        break;
      }
      bool f = 1;
      for (int p = 2, u = a[i] + j; p <= n; ++p, u += j) {
        if (!b[u]) {
          f = 0;
          break;
        }
      }
      if (f) {
        l[++t] = {j, a[i]};
      }
    }
  }
  if (!t) {
    fout << "NONE\n";
    // cerr << clock();
    return 0;
  }
  sort(l + 1, l + t + 1);
  for (int i = 1; i <= t; ++i) {
    fout << l[i].second << ' ' << l[i].first << '\n';
  }
  // cerr << clock();
  return 0;
}