#include <iostream>

using namespace std;

const int kN = 1e5 + 1, kL = 32, kV = 1e7;

int q, o, x, l[kN * kL][2], c[kN * kL], _c = 1;

void Update(int x, int v) {
  x += kV;
  for (int i = kL - 1, r = 1; ~i; --i) {
    int &y = l[r][x >> i & 1];
    !y && (y = ++_c), c[r = y] += v;
  }
}
int Rank(int v) {
  x += kV;
  int s = 0;
  for (int i = kL - 1, r = 1; ~i; --i) {
    int y = x >> i & 1;
    s += (y ? c[l[r][0]] : 0), r = l[r][y];
  }
  return s;
}
int Kth(int k) {
  int s = 0;
  for (int i = kL - 1, r = 1; ~i; --i) {
    int f = k > c[l[r][0]];
    s |= f << i, k -= f ? c[l[r][0]] : 0, r = l[r][f];
  }
  return s - kV;
}

int main() {
  freopen("P3369_5.in", "r", stdin);
  freopen("P3369.out", "w", stdout);
  cin >> q;
  while (q--) {
    cin >> o >> x;
    if (o == 1) {
      Update(x, 1);
    } else if (o == 2) {
      Update(x, -1);
    } else if (o == 3) {
      cout << Rank(x) + 1 << endl;
    } else if (o == 4) {
      cout << Kth(x) << endl;
    } else if (o == 5) {
      cout << Kth(Rank(x)) << endl;
    } else {
      cout << Kth(Rank(x + 1) + 1) << endl;
    }
  }
  return 0;
}