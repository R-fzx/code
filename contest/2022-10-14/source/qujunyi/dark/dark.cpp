#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
  double x, y;
  bool operator<(const node &p) const {
    if (x == p.x) {
      return y < p.y;
    }
    return x < p.x;
  }
} a[200005];
bool cmp(int x, int y) {
  return a[x].y < a[y].y;
}
double dist(int x, int y) {
  return sqrt((a[x].x - a[y].x) * (a[x].x - a[y].x) + (a[x].y - a[y].y) * (a[x].y - a[y].y));
}
double merge(int l, int r) {
  if (l == r) {
    return 1e9;
  }
  if (l + 1 == r) {
    return dist(l, r);
  }
  int mid = (l + r) >> 1;
  double p = min(merge(l, mid), merge(mid + 1, r));
  vector<int> v;
  for (int i = l; i <= r; i++) {
    if (fabs(a[mid].x - a[i].x <= p)) {
      v.push_back(i);
    }
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (a[v[j]].y - a[v[i]].y >= p) {
        break;
      }
      p = min(p, dist(v[i], v[j]));
    }
  }
  return p;
}
int main() {
  freopen("dark.in", "r", stdin);
  freopen("dark.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  sort(a + 1, a + 1 + n);
  printf("%.3lf\n", merge(1, n) / 2.0000);
  return 0;
}