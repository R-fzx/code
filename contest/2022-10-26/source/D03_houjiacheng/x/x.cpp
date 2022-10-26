# include <bits/stdc++.h>

using namespace std;

int n, ans;
int maxy;
struct str {
  int x, y;
  int s1, s2;
} a[100100];
priority_queue<int>q;

bool cmp(str a, str b) {
  return a.s2 == b.s2 ? a.s1 < b.s1 : a.s2 < b.s2;
}

int main() {
  freopen("x.in", "r", stdin);
  freopen("x.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1, x, y; i <= n; i++) {
    scanf("%d%d", &x, &y);
    a[i].x = x, a[i].y = y;
    a[i].s1 = x + y, a[i].s2 = x - y;
  }
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    if (q.size() == 0 || q.top() < a[i].s2) {
      ans++;
      q.push(a[i].s1);
    } else if(a[i].s1 < q.top()) {
      q.pop();
      q.push(a[i].s1);
    }
  }
  printf("%d", ans);
}























//sort x   :   xi + yi < xj - yj

//sort x>  :             xi - yi > xj + yj

