#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using Pii = pair<int, int>;

const int kN = 2e5 + 1;

int n, m, d, f[kN], c;
vector<int> e[kN], p;
vector<Pii> ans;

int F(int x) { return x == f[x] ? x : (f[x] = F(f[x])); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> d;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  iota(f + 1, f + n + 1, 1);
  for (int i = 2; i <= n; ++i) {
    for (int j : e[i]) {
      if (j != 1 && c < n - 1 && F(i) != F(j)) {
        f[F(j)] = F(i), ++c;
      }
    }
  }
  for (int i : e[1]) {
    if (c < n - 1 && F(1) != F(i)) {
      p.push_back(i), f[F(i)] = F(1), ++c;
    }
  }
  if (p.size() > d) {
    cout << "NO";
  } else {
    iota(f + 1, f + n + 1, 1), c = 0;
    for (int i : p) {
      f[F(i)] = F(1), ++c, ans.emplace_back(1, i);
    }
    for (int i : e[1]) {
      if (c < d && F(1) != F(i)) {
        f[F(i)] = F(1), ++c, ans.emplace_back(1, i);
      }
    }
    if (c < d) {
      cout << "NO";
    } else {
      cout << "YES" << endl;
      for (int i = 2; i <= n; ++i) {
        for (int j : e[i]) {
          if (c < n - 1 && j != 1 && F(i) != F(j)) {
            f[F(j)] = F(i), ++c, ans.emplace_back(i, j);
          }
        }
      }
      for (auto &i : ans) {
        cout << i.first << " " << i.second << endl;
      }
    }
  }
  return 0;
}