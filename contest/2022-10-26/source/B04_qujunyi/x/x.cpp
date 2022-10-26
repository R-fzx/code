#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
} a[100005];
bool bb[100005];
int n;
int maxn = 0;
map<int, int> m;
void dfs(int x) {
  if (x == n + 1) {
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (bb[i] == 1 && bb[j] == 1 && abs(a[i].x - a[j].x) <= (a[i].y + a[j].y)) {
          return;
        }
      }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      if (bb[i] == 1) {
        sum++;
      }
    }
    maxn = max(maxn, sum);
    return;
  }
  bb[x] = 1;
  dfs(x + 1);
  bb[x] = 0;
  dfs(x + 1);
}
bool cmp(node i, node j) {
  return i.x > j.x;
}
int main() {
  freopen("x.in", "r", stdin);
  freopen("x.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  cin >> n;
  bool b = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
    if (a[i].y != 0) {
      b = 1;
    }
  }
  if (b == 0) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      if (m[a[i].x] == 0) {
        sum++;
        m[a[i].x] = 1;
      }
    }
    cout << sum;
  } else if (n <= 30) {
    dfs(1);
    cout << maxn;
  } else {
    vector<node> v, vv;
    for (int i = 1; i <= n; i++) {
      int sum = 0;
      for (int j = i + 1; j <= n; j++) {
        if (abs(a[i].x - a[j].x) > (a[i].y + a[j].y)) {
          sum++;
        }
      }
      node p;
      p.x = sum, p.y = i;
      v.push_back(p);
    }
    int sum  = 0;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
      bool u = 0;
      for (int j = 0; j < vv.size(); j++) {
        if (abs(a[v[i].y].x - a[vv[j].y].x) <= (a[v[i].y].y + a[vv[j].y].y)) {
          u=1;
        }
      }
      if(u==0){
        sum++;
        vv.push_back(v[i]);
      }
    }
    cout << sum;
  }
}
