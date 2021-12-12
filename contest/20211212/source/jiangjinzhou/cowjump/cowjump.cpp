#include <bits/stdc++.h>

using namespace std;
const int kMaxN = 1e5 + 5;

struct segment {
  int x1, x2, y1, y2;
} seg[kMaxN];
int n, bucket[kMaxN], ans = -1, cur = -1;
int main () {
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> seg[i].x1 >> seg[i].y1 >> seg[i].x2 >> seg[i].y2;
    if (i > 1) {
      for (int j = 1; j < i; j++) {
        if (max (seg[i].x1, seg[i].x2) < min (seg[j].x1, seg[j].x2) && max (seg[i].y1, seg[i].y2) < min (seg[j].y1, seg[j].y2) || max (seg[j].x1, seg[j].x2) < min (seg[i].x1, seg[i].x2) && max (seg[j].y1, seg[j].y2) < min (seg[i].y1, seg[i].y2) && max (seg[i].x1, seg[i].x2) > max (seg[j].x1, seg[j].x2) && min (seg[i].x1, seg[i].x2) < max (seg[j].x1, seg[j].x2) && max (seg[i].y1, seg[i].y2) > max (seg[j].y1, seg[j].y2) && min (seg[i].y1, seg[i].y2) < max (seg[j].y1, seg[j].y2) || max (seg[j].x1, seg[j].x2) > max (seg[i].x1, seg[i].x2) && min (seg[j].x1, seg[j].x2) < max (seg[i].x1, seg[i].x2)         && max (seg[j].y1, seg[j].y2) > max (seg[i].y1, seg[i].y2) && min (seg[j].y1, seg[j].y2) < max (seg[i].y1, seg[i].y2) ||        max (seg[j].x1, seg[j].x2) > min (seg[i].x1, seg[i].x2) && min (seg[j].x1, seg[j].x2) < min (seg[i].x1, seg[i].x2)        && max (seg[j].y1, seg[j].y2) > min (seg[i].y1, seg[i].y2) && min (seg[j].y1, seg[j].y2) < min (seg[i].y1, seg[i].y2) ||         max (seg[i].x1, seg[i].x2) > min (seg[j].x1, seg[j].x2) && min (seg[i].x1, seg[i].x2) < min (seg[j].x1, seg[j].x2)        && max (seg[i].y1, seg[i].y2) > min (seg[j].y1, seg[j].y2) && min (seg[i].y1, seg[i].y2) < min (seg[j].y1, seg[j].y2)) {
          bucket[i]++, bucket[j]++;
        }
      }
    }
  }

  for (int i = 1; i <= n;  i++) {
    if (bucket[i] > ans) {
      ans = bucket[i];
      cur = i;
    }
    cout << bucket[i] << ' ';
  }
  cout << '\n' << cur << '\n';
  return 0;
}