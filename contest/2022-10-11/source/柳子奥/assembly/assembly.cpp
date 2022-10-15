#include <bits/stdc++.h>

#define db(x) cerr << #x << '=' << x << endl

using namespace std;

const int kMaxN = 9;

int n, k, A;
int b[9], l[9];
double ans;

void solve() {
  double tmp = 0;
  for (int i = 0; i < (1 << n); ++i) {
    double p = 1; int B = 0, cnt = 0;
    for (int j = 1; j <= n; ++j) {
      if (i >> (j - 1) & 1) {
        ++cnt;
        p *= (double)l[j] / 100.0;
      } else {
        p *= (double)(100 - l[j]) / 100.0, B += b[j];
      }
    }
    if (cnt * 2 > n) {
      tmp += p;
    } else {
      tmp += p * (double)A / (A + B);
    }
  }
  ans = max(ans, tmp);
}

void dfs(int x, int k) {
  if (x == n + 1) {
    return solve();
  }
  for (int i = 0; i <= min((100 - l[i]) / 10, k); ++i) {
    l[x] += 10 * i;
    dfs(x + 1, k - i);
    l[x] -= 10 * i;
  }
}

int main() {
  freopen("assembly.in", "r", stdin);
  freopen("assembly.out", "w", stdout);
  cin >> n >> k >> A;
  for (int i = 1; i <= n; ++i) {
    cin >> b[i] >> l[i];
  }
  dfs(1, k);
  cout << fixed << setprecision(6) << ans << endl;
  return 0;
}