#pragma GCC optimize(3)
#include <iostream>
#include <algorithm>
#include <unordered_map>
// #include <ctime>
#define RF(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;

const int kN = 4e4 + 1;

unsigned short n, m, v, c1[kN], c2[kN], c3[kN], c4[kN], c[kN];
unsigned int a[kN], b[kN];
struct Hash {
  unsigned int operator()(const pair<unsigned short, unsigned short> &x) const {
    return 1919810U * x.first + x.second;
  }
};
unordered_map<pair<unsigned short, unsigned short>, unsigned short, Hash> p;

int main() {
  RF("dandelion");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (unsigned short i = 1; i <= n; ++i) {
    cin >> a[i], b[i] = a[i];
  }
  sort(b + 1, b + n + 1), v = unique(b + 1, b + n + 1) - b - 1;
  for (unsigned short i = 1; i <= n; ++i) {
    a[i] = lower_bound(b + 1, b + v + 1, a[i]) - b;
  }
  for (unsigned short l, r, x = 0; m--; ) {
    cin >> l >> r;
    l = (l + b[x] - 1) % n + 1, r = (r + b[x] - 1) % n + 1;
    if (l > r) {
      swap(l, r);
    }
    pair<unsigned short, unsigned short> _p = {l, r};
    if (p.find(_p) == p.end()) {
      unsigned short i = l;
      for (; i + 4 <= r; i += 4) {
        ++c1[a[i]];
        ++c2[a[i + 1]];
        ++c3[a[i + 2]];
        ++c4[a[i + 3]];
      }
      switch (r - i) {
        case 3: ++c1[a[i + 3]];
        case 2: ++c1[a[i + 2]];
        case 1: ++c1[a[i + 1]];
        case 0: ++c1[a[i]];
      }
      for (i = 1; i + 4 <= v; i += 4) {
        c[i] = c1[i] + c2[i] + c3[i] + c4[i];
        c[i + 1] = c1[i + 1] + c2[i + 1] + c3[i + 1] + c4[i + 1];
        c[i + 2] = c1[i + 2] + c2[i + 2] + c3[i + 2] + c4[i + 2];
        c[i + 3] = c1[i + 3] + c2[i + 3] + c3[i + 3] + c4[i + 3];
      }
      switch (v - i) {
        case 3: c[i + 3] = c1[i + 3] + c2[i + 3] + c3[i + 3] + c4[i + 3];
        case 2: c[i + 2] = c1[i + 2] + c2[i + 2] + c3[i + 2] + c4[i + 2];
        case 1: c[i + 1] = c1[i + 1] + c2[i + 1] + c3[i + 1] + c4[i + 1];
        case 0: c[i] = c1[i] + c2[i] + c3[i] + c4[i];
      }
      unsigned short x1 = 1, x2 = 1, x3 = 1, x4 = 1;
      for (i = 2; i + 4 <= v; i += 4) {
        c[i] > c[x1] && (x1 = i);
        c[i + 1] > c[x2] && (x2 = i + 1);
        c[i + 2] > c[x3] && (x3 = i + 2);
        c[i + 3] > c[x4] && (x4 = i + 3);
      }
      switch (v - i) {
        case 3: c[i + 3] > c[x4] && (x4 = i + 3);
        case 2: c[i + 2] > c[x3] && (x3 = i + 2);
        case 1: c[i + 1] > c[x2] && (x2 = i + 1);
        case 0: c[i] > c[x1] && (x1 = i);
      }
      unsigned short s = max({c[x1], c[x2], c[x3], c[x4]});
      x = r;
      s == c[x1] && (x = min(x, x1)), s == c[x2] && (x = min(x, x2)), s == c[x3] && (x = min(x, x3)), s == c[x4] && (x = min(x, x4));
      for (i = 1; i + 4 <= v; i += 4) {
        c1[i] = 0;
        c1[i + 1] = 0;
        c1[i + 2] = 0;
        c1[i + 3] = 0;
      }
      switch (v - i) {
        case 3: c1[i + 3] = 0;
        case 2: c1[i + 2] = 0;
        case 1: c1[i + 1] = 0;
        case 0: c1[i] = 0;
      }
      for (i = 1; i + 4 <= v; i += 4) {
        c2[i] = 0;
        c2[i + 1] = 0;
        c2[i + 2] = 0;
        c2[i + 3] = 0;
      }
      switch (v - i) {
        case 3: c2[i + 3] = 0;
        case 2: c2[i + 2] = 0;
        case 1: c2[i + 1] = 0;
        case 0: c2[i] = 0;
      }
      for (i = 1; i + 4 <= v; i += 4) {
        c3[i] = 0;
        c3[i + 1] = 0;
        c3[i + 2] = 0;
        c3[i + 3] = 0;
      }
      switch (v - i) {
        case 3: c3[i + 3] = 0;
        case 2: c3[i + 2] = 0;
        case 1: c3[i + 1] = 0;
        case 0: c3[i] = 0;
      }
      for (i = 1; i + 4 <= v; i += 4) {
        c4[i] = 0;
        c4[i + 1] = 0;
        c4[i + 2] = 0;
        c4[i + 3] = 0;
      }
      switch (v - i) {
        case 3: c4[i + 3] = 0;
        case 2: c4[i + 2] = 0;
        case 1: c4[i + 1] = 0;
        case 0: c4[i] = 0;
      }
      p[_p] = x;
    } else {
      x = p[_p];
    }
    cout << b[x] << '\n';
  }
  // cerr << clock();
  return 0;
}