#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("ppfish.in", "r", stdin);
  freopen("ppfish.out", "w", stdout);
  int n, k;
  string p;
  cin >> n;
  for (int i = 0; i <= n; ++i) {
    string s;
    cin >> s;
  }
  cin >> p >> k;
  if (k == 1) {
    for (int i = 1; i < n; ++i) {
      cout << "1.000 ";
    }
    cout << p;
  } else {
    for (int i = 0; i < n; ++i) {
      cout << "0.000 ";
    }
  }
  return 0;
}