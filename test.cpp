#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[9] = {0, 1, 2, 3, 3, 4, 5, 5};
  int l = unique(a + 1, a + 8) - a;
  cout << l;
  // for (int i = 1; i <= l; ++i) cout << a[i] << " ";
  cout << lower_bound(a + 1, a + l, 4) - a;
  return 0;
}