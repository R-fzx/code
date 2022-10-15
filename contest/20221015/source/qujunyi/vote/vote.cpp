#include <bits/stdc++.h>
using namespace std;
long long t[100005];
bool cmp(long long x, long long y) {
  return x > y;
}
long long s[100005];
int main() {
  freopen("vote.in", "r", stdin);
  freopen("vote.out", "w", stdout);
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    long long x;
    cin >> x;
    t[x]++;
  }
  long long u = n - m;
  sort(t + 1, t + 1 + n, cmp);
  long long sum = 1;
  long long pp = 2;
  for (long long i = n - 1; i >= 2; i--) {
    //cout << sum << " " << t[i] << " " << t[i + 1] << endl;
    u -= (t[i] - t[i + 1]) * sum;
    sum++;
    if (u < 0) {
      pp = i;
      break;
    }
  }
  //cout << pp << endl;
  long long s = 1;
  long long v = u;
  if (pp == 2) {
    long long p = t[1] - t[2];
    //cout << u << " " << p << endl;
    if (p != 0) {
      u /= p;
      s += u;
      v -= u * p;
    } else {
      s = n;
    }
  } else {
    for (long long i = 2; i <= n; i++) {
      if (t[1] == t[i]) {
        s++;
      }
    }
  }
  if (s == n) {
    if (v == 0) {
      cout << "0.0000";
    } else {
      double x = s, y = v;
      printf("%.4lf", 1 / x);
    }
  } else if (s == 1) {
    cout << "1.0000";
  } else {
    double x = s, y = v;
    printf("%.4lf", 1 / x);
  }
  return 0;
}
