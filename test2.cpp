#include <iostream>

using namespace std;

const int kN = 1e7 + 2;

int t, x, n[kN];
bool v[kN];

bool C(int x) {
  bool f = 0;
  for (; x; x /= 10) f |= x % 10 == 7;
  return f;
}

int main() {
  freopen("test.in", "r", stdin);
  freopen("test.ans", "w", stdout);
  for (int i = 1; i < kN; ++i) {
    if (!v[i] && C(i)) {
      v[i] = 1;
      for (int j = i << 1; j < kN; j += i) v[j] = 1;
    }
  }
  for (int i = 1; i < kN;) {
    int j = i + 1;
    while (j < kN && v[j]) ++j;
    n[i] = j, i = j;
  }
  cin >> t;
  while (t--) {
    cin >> x;
    cout << (v[x] ? -1 : n[x]) << endl;
  }
  return 0;
}