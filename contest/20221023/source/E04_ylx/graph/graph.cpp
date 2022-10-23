#include <bits/stdc++.h>

#include <fstream>
#pragma GCC optimize("Ofast")

using namespace std;
using ll = long long;
using Pii = pair<int, int>;

ifstream fin("graph.in");
ofstream fout("graph.out");

const int N = 1e3 + 5;

int n, a[N], I[N], r;

int main() {
  fin >> n;
  for (int i = 1; i <= n; i++) {
    fin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = n; i; i--) {
    if (!I[i]) {
      for (int j = i - 1; j; j--) {
        if (I[j] && !(a[i] & a[j])) {
          r += a[j];
          break;
        }
      }
      I[i] = 1;
    }
    for (int j = 1; j < i; j++) {
      if (!I[j] && !(a[i] & a[j])) {
        r += a[i];
        I[j] = 1;
      }
    }
  }
  fout << r;
  return 0;
}
/*
 */