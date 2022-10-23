#include <bits/stdc++.h>

#include <fstream>
#pragma GCC optimize("Ofast")

using namespace std;
using ll = long long;
using Pii = pair<int, int>;

ifstream fin("section.in");
ofstream fout("section.out");

const int N = 1e5 + 5;

int n, m, q, a[N], t;

int main() {
  fin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    fin >> a[i];
  }
  for (int o, l; q--;) {
    fin >> o >> l;
    if (o == 1) {
      reverse(a + l, a + l + m);
    } else {
      t ^= a[l];
    }
  }
  fout << t;
  return 0;
}
/*
*/