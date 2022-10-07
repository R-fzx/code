#include <algorithm>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;
using ll = long long;

const int kMaxN = 1e5 + 1;

int n, m, t;
ll ans, avrrow, avrcol;
ll row[kMaxN], col[kMaxN];
ll rows[kMaxN], cols[kMaxN];
bool colf, rowf;

void shit(ll aorc[], int n) {
  sort(aorc + 1, aorc + n + 1);
  int mid = aorc[n >> 1];
  for (int i = 1; i <= n; i++) {
    ans += abs(aorc[i] - mid);
  }
}

int main() {
  ifstream cin("tanabata.in");
  ofstream cout("tanabata.out");

  cin >> n >> m >> t;
  for (int i = 1; i <= t; i++) {
    int x, y;
    cin >> x >> y;
    row[x]++, col[y]++;
  }
  for (int i = 1; i <= n; i++) {
    avrrow += row[i];
  }
  for (int i = 1; i <= m; i++) {
    avrcol += col[i];
  }
  avrrow /= n, avrcol /= m;
  for (int i = 1; i <= n; i++) {
    rows[i] = rows[i - 1] + row[i] - avrrow;
  }
  for (int i = 1; i <= m; i++) {
    cols[i] = cols[i - 1] + col[i] - avrcol;
  }
  rowf = !(t % n), colf = !(t % m);
  if (!rowf && !colf) {
    cout << "impossible\n";
  } else if (rowf && !colf) {
    shit(rows, n);
    if (t == 1) {
      ans--;
    }
    cout << "row " << ans << '\n';
  } else if (!rowf && colf) {
    shit(cols, m);
    cout << "column " << ans << '\n';
  } else if (rowf && colf) {
    shit(cols, m), shit(rows, n);
    cout << "both " << ans << '\n';
  }
  return 0;
}