#include <iostream>
#include <queue>

using namespace std;

struct V {
  int i, _i, o;
  vector<int> e, _e, ans;
} v[201];
int n, m, num;
vector<int> l, ans;
queue<int> q;

int main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; i++) {
    cin >> x >> y;
    v[x].e.push_back(y), v[x].o++, v[y].i++;
  }
  for (int i = 1; i <= n; i++) {
    if (!v[i].o) {
      v[i].ans.push_back(i);
    }
    if (!(v[i]._i = v[i].i)) {
      q.push(i);
    }
  }
  for (; !q.empty(); q.pop()) {
    int c = q.front();
    l.push_back(c);
    for (int i : v[c].e) {
      if (!--v[i].i) {
        q.push(i);
        v[c]._e.push_back(i);
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    int s = 0;
    for (int j : v[l[i]]._e) {
      s += max(int(v[j].ans.size()), 1);
    }
    if (s >= v[l[i]].ans.size()) {
      v[l[i]].ans.clear();
      for (int j : v[l[i]]._e) {
        if (v[j].ans.empty()) {
          v[l[i]].ans.push_back(j);
        }
        for (int k : v[j].ans) {
          v[l[i]].ans.push_back(k);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!v[i]._i) {
      num += v[i].ans.size();
      for (int j : v[i].ans) {
        ans.push_back(j);
      }
    }
  }
  cout << num << '\n';
  for (int i : ans) {
    cout << i << ' ';
  }
  return 0;
}
