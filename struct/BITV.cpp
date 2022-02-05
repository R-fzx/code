#include <iostream>

using namespace std;

const int kV = 1e7 + 1;

int q, o, x, s[kV << 1];

void Add(int x, int v) {
  
  for (; x < kV * 2; s[x] += v, x += x & -x) {
  }
}
int Query(int x) {
  int _s = 0;
  for (; x; _s += s[x], x -= x & -x) {
  }
  return _s;
}
int At(int r) {
  int x = 0, c = 0;
  for (int i = 25; ~i; --i) {
    x += 1 << i;
    if (x >= kV * 2 - 1 || c + s[x] >= r) {
      x -= 1 << i;
    } else {
      c += s[x];
    }
  }
  return x + 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> o >> x;
    if (o == 1) {
      Add(x + kV, 1);
    } else if (o == 2) {
      Add(x + kV, -1);
    } else if (o == 3) {
      cout << Query(x + kV - 1) + 1 << '\n';
    } else if (o == 4) {
      cout << At(x) - kV << '\n';
    } else if (o == 5) {
      cout << At(Query(x + kV - 1)) - kV << '\n';
    } else {
      cout << At(Query(x + kV) + 1) - kV << '\n';
    }
  }
  return 0;
}