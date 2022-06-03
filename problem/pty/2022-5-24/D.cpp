#include <iostream>

using namespace std;

const int kN = 201;

struct Q {
  int i, j, k, d, p;
  char c;
} q[kN * kN * kN * 2];
int n, m, h = 1, t, d[kN][kN][kN * 2];
string a, b;

bool R(int i, int j, int k, int d, int p, char c) { return k >= 0 && k < kN * 2 && !::d[i][j][k] && (q[++t] = {i, j, k, d, p, c}, ::d[i][j][k] = d), i == n && j == m && !k; }

int main() {
  cin >> a >> b, n = a.size(), m = b.size();
  for (R(0, 0, 0, 0, 0, ' '); h <= t; ++h) {
    int i = q[h].i, j = q[h].j, k = q[h].k, d = q[h].d;
    if (R(i + (i < n && a[i] == '('), j + (j < m && b[j] == '('), k + 1, d + 1, h, '(') ||
        R(i + (i < n && a[i] == ')'), j + (j < m && b[j] == ')'), k - 1, d + 1, h, ')')) {
      break;
    }
  }
  for (int i = t; i; q[q[i].p].d = i, i = q[i].p) {
  }
  q[t].d = 0;
  for (int i = 1; i; cout << q[i].c, i = q[i].d) {
  }
  return 0;
}