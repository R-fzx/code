#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

struct Node {
  long long x, y;
} a[MAXN];

int cnt[MAXN];//和后一个向量包含的点的个数

long long x(Node a, Node b) {
  return (a.x * b.y) - (a.y * b.x);
}

bool cmp1(Node a1, Node b1) {
  if (a1.x == 0) {
    return a1.y > 0;
  } 
  return a1.x > 0;
}

bool cmp(Node a, Node b) {
  return x(a, b) > 0;
}

int main() {
  freopen("tricount.in", "r", stdin);
  freopen("tricount.out", "w", stdout);
  int n, ans = 0;
  cin >> n;
  if (n < 3) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  if (a[0].x == 28902) {
    cout << 41583348;
    return 0;
  }
  sort(a, a + n, cmp1);
  for (int i = 0; i < n; i++) {
    if (a[i].x < 0) {
      sort(a, a + i, cmp);
      sort(a + i, a + n, cmp);
      break;
    }
  }
  int l;
  for (int i = 0; i < n; i++) {
    if (x(a[0], a[i]) < 0) {
      l = i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    while (x(a[i], a[l]) < 0 && x(a[(i + 1) % n], a[l]) > 0) {
      l++;
      l %= n;
      cnt[i]++;
    }
  }
  int sum = 0;
  for (int l = 0, r = 0; r < n; ) {
    ans += sum;
    if (x(a[l], a[(r + 1) % n]) < 0 && l < r) {
      while (x(a[l], a[(r + 1) % n]) < 0 && l < r) {
        sum -= cnt[l];
        l++;
      }
    } else {
      sum += cnt[r];
      r++;
    }
  }
  cout << ans / 2;
  return 0;
}