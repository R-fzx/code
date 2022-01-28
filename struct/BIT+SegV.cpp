#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pii = pair<int, int>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 50001, kI = (1LL << 31) - 1;

struct E {
  int s, l[2];
} e[kN << 8];
int n, q, t, a[kN], qo[kN], ql[kN], qr[kN], qk[kN], b[kN << 1], rt[kN], c;
vector<int> p[2];

Pii Split(Pii o, int m, bool f) { return {f ? m + 1 : o.first, f ? o.second : m}; }
void Add(int &x, Pii o, int t, int v) {
  !x && (x = ++c);
  if (o.first == o.second) {
    e[x].s += v;
  } else {
    int m = o.first + o.second >> 1;
    Add(e[x].l[t > m], Split(o, m, t > m), t, v), e[x].s = e[e[x].l[0]].s + e[e[x].l[1]].s;
  }
}
int LeftSum() {
  int s = 0;
  for (int i = 0; i < 2; ++i) {
    for (int j : p[i]) {
      s += (i ? -1 : 1) * e[e[j].l[0]].s;
    }
  }
  return s;
}
void Adjust(int f) {
  for (int i = 0; i < 2; ++i) {
    for (int &j : p[i]) {
      j = e[j].l[f];
    }
  }
}
int Query(Pii o, int t) {
  if (o.first == o.second) {
    int s = 0;
    for (int i = 0; i < 2; ++i) {
      for (int j : p[i]) {
        s += (i ? -1 : 1) * e[j].s;
      }
    }
    return s;
  }
  int m = o.first + o.second >> 1, f = t > m, s = LeftSum();
  Adjust(f);
  return f * s + Query(Split(o, m, f), t);
}
int At(Pii o, int r) {
  if (o.first == o.second) {
    return o.first;
  }
  int m = o.first + o.second >> 1, s = LeftSum(), f = s < r;
  Adjust(f);
  return At(Split(o, m, f), r - f * s);
}
void Add(int x, int c) {
  for (int i = x; i <= t; Add(rt[i], {1, t}, a[x], c), i += i & -i) {
  }
}
void Split(int x, int t) {
  p[t].clear();
  for (; x; p[t].push_back(rt[x]), x -= x & -x) {
  }
}
int Rank(int l, int r, int x) {
  Split(r, 0), Split(l - 1, 1);
  return Query({1, t}, x - 1) + 1;
}
int At(int l, int r, int x) {
  Split(r, 0), Split(l - 1, 1);
  return At({1, t}, x);
}
int Pre(int l, int r, int x) {
  int rk = Rank(l, r, x) - 1;
  return rk ? At(l, r, rk) : 0;
}
int Next(int l, int r, int x) {
  if (x == t) {
    return t + 1;
  }
  int rk = Rank(l, r, x + 1);
  return rk == r - l + 2 ? t + 1 : At(l, r, rk);
}

int main() {
  // freopen("BIT+SegV.in", "r", stdin);
  // freopen("BIT+SegV.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[++t] = a[i];
  }
  for (int i = 1; i <= q; ++i) {
    cin >> qo[i] >> ql[i];
    if (qo[i] != 3) {
      cin >> qr[i];
    }
    cin >> qk[i];
    if (qo[i] != 2) {
      b[++t] = qk[i];
    }
  }
  sort(b + 1, b + t + 1), t = unique(b + 1, b + t + 1) - b - 1, b[0] = -kI, b[t + 1] = kI;
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(b + 1, b + t + 1, a[i]) - b;
    Add(i, 1);
  }
  for (int i = 1; i <= q; ++i) {
    if (qo[i] != 2) {
      qk[i] = lower_bound(b + 1, b + t + 1, qk[i]) - b;
    }
    if (qo[i] == 1) {
      cout << Rank(ql[i], qr[i], qk[i]) << endl;
    } else if (qo[i] == 2) {
      cout << b[At(ql[i], qr[i], qk[i])] << endl;
    } else if (qo[i] == 3) {
      Add(ql[i], -1), a[ql[i]] = qk[i], Add(ql[i], 1);
    } else if (qo[i] == 4) {
      cout << b[Pre(ql[i], qr[i], qk[i])] << endl;
    } else {
      cout << b[Next(ql[i], qr[i], qk[i])] << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}