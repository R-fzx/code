#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 2e5 + 5;

int n, k;
int a[kMaxN], f[kMaxN][22], lg[kMaxN], sum[kMaxN];

void prework() {
  lg[0] = -1;
  for (int i = 1; i <= n; ++i) {
    f[i][0] = a[i], lg[i] = lg[i >> 1] + 1;
  }
  for (int i = 1; i <= lg[n]; ++i) {
    for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
      f[j][i] = min(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);
    }
  }
}

int query(int l, int r) {
  int k = lg[r - l + 1];
  return min(f[l][k], f[r - (1 << k) + 1][k]);
}

int main() {
  freopen("fuck.in", "r", stdin);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int m; cin >>m;
  for (int i = 1; i <= k; ++i) {
    int x, y; cin >> x >> y;
    ++sum[x];
  }
  for (int i = 1; i <= 2e5; ++i) sum[i] += sum[i - 1];
  prework();
  long long tmp = 0;
  for (int i = 1; i <= n; ++i){
    int L = 0, R = i + 1, resl = i;
    while (L + 1 < R) { 
      int mid = (L + R) >> 1;
      if (query(mid, i) == a[i]) R = resl = mid;
      else L = mid;
    }
    int resr = i;
    L = i, R = n + 1;
    while (L + 1 < R) {
      int mid = (L + R) >> 1;
      if (query(i + 1, mid) > a[i]) L = resr = mid;
      else R = mid;
    }
    tmp += sum[resr] - sum[resl - 1];
  }
  cout << tmp << endl;
  return 0;
}