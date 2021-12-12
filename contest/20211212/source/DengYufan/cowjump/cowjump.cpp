#include <algorithm>
#include <ctime>
#include <iostream>
#define LL long long

using namespace std;

struct V {
  LL x[2], y[2];
} v[100001];
LL n, l[100001];

LL Cross(LL i, LL j, LL p) {
  LL c = (v[i].x[1] - v[i].x[0]) * (v[j].y[p] - v[i].y[0]) - (v[j].x[p] - v[i].x[0]) * (v[i].y[1] - v[i].y[0]);
  return c ? c > 0 ? 1 : -1 : 0;
}

bool C(LL j) {
  LL num = 0;
  for (LL i = 1; i <= n; i++) {
    if (i != j && Cross(i, j, 0) * Cross(i, j, 1) <= 0 && Cross(j, i, 0) * Cross(j, i, 1) <= 0) {
      num++;
    }
  }
  return num < 2;
}

int main() {
  freopen("cowjump.in", "r", stdin);
  freopen("cowjump.out", "w", stdout);
  cin >> n;
  for (LL i = 1; i <= n; i++) {
    cin >> v[i].x[0] >> v[i].y[0] >> v[i].x[1] >> v[i].y[1];
    l[i] = i;
    if (v[i].x[0] > v[i].x[1] || v[i].x[0] == v[i].x[1] && v[i].y[0] > v[i].y[1]) {
      swap(v[i].x[0], v[i].x[1]), swap(v[i].y[0], v[i].y[1]);
    }
  }
  sort(l + 1, l + n + 1, [](LL i, LL j) { return v[i].x[0] < v[j].x[0] || v[i].x[0] == v[j].x[0] && v[i].y[0] < v[j].y[0]; });
  for (LL i = 1; i < n; i++) {
    for (LL j = i + 1; j <= n && v[l[j]].x[0] <= v[l[i]].x[1]; j++) {
      if (Cross(l[i], l[j], 0) * Cross(l[i], l[j], 1) <= 0 && Cross(l[j], l[i], 0) * Cross(l[j], l[i], 1) <= 0) {
        cout << (C(max(l[i], l[j])) ? min(l[i], l[j]) : max(l[i], l[j]));
        return 0;
      }
    }
  }
  // cout << "Runtime:" << clock() / 1000.0 << "s\n";
  return 0;
}
