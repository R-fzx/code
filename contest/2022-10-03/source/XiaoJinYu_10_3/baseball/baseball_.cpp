#include <bits/stdc++.h>

using namespace std;

long long shit;
int s[1000];
int cnt;
long double r;

long long check(long long minn, long long i) {
  long long xx = 1.0 * i * (r + 0.5) / shit, xx2 = 1.0 * i * (r - 0.5) / shit, aa = 1145141919810114514;
  for (long long j = xx2; j <= xx; ++j) {
    long long x = 1.0 * j / i * shit + 0.5;
    if (x == r) {
      cout << i << '\n';
      return 0;
    }
    if (abs(x - r) < aa) {
      aa = abs(x - r);
    }
  }
  return aa;
}

int main() {
  freopen("baseball.in", "r", stdin);
  freopen("baseball_.out", "w", stdout);
  int n;
  long long minn = 1145141919810114514, li = 0;
  while (cin >> n >> r) {
    shit = 1;
    for (int i = 0; i < n; ++i) {
      shit *= 10;
    }
    cnt = 0;
    s[++cnt] 
    r *= shit;
    int fucku = 1, lfucku = 1;
    for (long long i = 2;; i += fucku) {
      // cout << 1.0 * i * r / shit << ' ';
      long long ci = check(minn, i);
      if (minn > aa) {
        // cout << "fucku "<< fucku << '\n';
        minn = aa;
        fucku = i - li;
        cout << fucku << ' ' << i - li << '\n';
        li = i;
      } else {
        i -= fucku - 1;
        fucku = fucku / 2;
      }

      // for (int j = 1; j < i; ++j) {
      //   int x = 1.0 * j / i * shit + 0.5;
      //   if (x == r) {
      //     // cout << j << '/' << i << '=' << 1.0 * j / i << ' ' << 1.0 * i * r / shit << '\n';
      //     cout << '?';
      //     return 0;
      //     // cout << xx << ' ' << j;
      //     // cout << abs((1.0 * j - 1.0 * i * r / shit) / i);
      //     // if (abs((1.0 * j - 1.0 * i * r / shit) / i) > maxx) {
      //     //   maxx = abs((1.0 * j - 1.0 * i * r / shit) / i);
      //     // }
      //     // cout << j << ' ' << xx << ' ' << xx2 << '\n';
      //     // if (xx != j) {
      //     //   cout << "???" << xx << ' ' << j << ' ' << i << ' ' <<1.0 * i * (r + 0.5) << ' ';
      //     //   cout << (1.0 * j - 1.0 * i * r / shit) / i;
      //     // }
      //   }
      // }
      // cout << '\n';
    }
  }
  return 0;
}