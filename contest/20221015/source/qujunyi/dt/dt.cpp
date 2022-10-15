#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node {
  int x, y;
} a[100005];
bool cmp(node i, node j) {
  return i.x > j.x;
}
vector<int> v[100005];
bool b[100005];
int s[100005];
int main() {
  freopen("dt.in", "r", stdin);
   freopen("dt.out", "w", stdout);
   ios::sync_with_stdio(false);
   cout.tie(0);
   cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x;
    s[i] = a[i].x;
    a[i].y = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    int x = a[i].y;
    b[x] = 1;
    for (int j = 0; j < v[x].size(); j++) {
      if (b[v[x][j]] == 0) {
        sum += s[v[x][j]];
      }
    }
  }
  cout << sum << endl;
  return 0;
}