#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n, m, l, r, t = 1, Last_l, Last_r;
pair<int, int> a[40001];
int b[40001], temp[40001], Max;

int main() {
  freopen("dandelion.in", "r", stdin);
  freopen("dandelion.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = n; i > 0; i--) {
    if (a[i].first != a[i - 1].first) {
      t++;
      b[t] = a[i - 1].first;
    }
    a[i].first = t - (b[t] != a[i].first);
  }
  sort(a + 1, a + n + 1, [](pair<int, int> a, pair<int, int> b) -> bool {
    return a.second < b.second;
  });
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &l, &r);
    l = (l + b[Max] - 1) % (n + 1), r = (r + b[Max] - 1) % (n + 1);
    if(l > r) {
      swap(l, r);
    } 
    Max = 0;
    for (int j = l; j <= r; j++) {
      temp[a[j].first]++;
      if (temp[a[j].first] > temp[Max] || (temp[Max] == temp[a[j].first] && a[j].first > Max)) {
        Max = a[j].first;
      }
    }
    printf("%d\n", b[Max]);
    memset(temp, 0, sizeof(temp));
  }
  return 0;
}