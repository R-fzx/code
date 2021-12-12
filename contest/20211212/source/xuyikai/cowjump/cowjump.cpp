#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int vis[N];
struct Node {
  int sx, sy, fx, fy;
} a[N];
struct node {
  int m, w;
} s[N];
bool cmp(node A, node B) {
  if (A.w == B.w) {
    return A.m < B.m;
  }
  return A.w > B.w;
}
int main() {
  freopen("cowjump.in", "r", stdin);
  freopen("cowjump.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].sx >> a[i].sy >> a[i].fx >> a[i].fy;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].sx > a[i].fx) {
      swap(a[i].sx, a[i].fx);
      swap(a[i].sy, a[i].fy);
    } else if (a[i].sx == a[i].fx) {
      if (a[i].sy > a[i].fy) {
        swap(a[i].sx, a[i].fx);
        swap(a[i].sy, a[i].fy);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i].sx <= a[j].sx && a[i].sy >= a[j].sy && a[i].fx >= a[j].sx && a[i].fy <= a[j].sy || a[j].sx <= a[i].sx && a[j].sy >= a[i].sy && a[j].fx >= a[i].sx && a[j].fy <= a[i].sy) {
        vis[i]++;
        vis[j]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    s[i].m = i;
    s[i].w = vis[i];
  }
  sort(s + 1, s + n + 1, cmp);
  cout << s[1].m;
  return 0;
}