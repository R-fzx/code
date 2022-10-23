#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1005;

int n, ans, a[N];
vector <int> q[N];
queue <int> p;
bool f[N];
 

int main() {
  freopen("graph.in", "r", stdin);
  freopen("graph.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (!(a[i] & a[j])) {
        q[i].push_back(j);
        q[j].push_back(i);
      }
    }
  }
  p.push(1);
  for (int i = 2; i <= n; i++) {
    ans += a[i];
  }
  cout << ans;
  return 0;
}
