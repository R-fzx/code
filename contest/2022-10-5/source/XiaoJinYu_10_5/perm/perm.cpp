#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

__uint128_t a[MAXN];

inline void w(__uint128_t x) {
  if (x > 9)
    w(x / 10);
  putchar(x % 10 + 48);
}

int f[10];
int n;

__uint128_t C(int x, int y) {
  return a[y] / a[x] / a[y - x];
}

__uint128_t shit() {
  int cnt = 0;
  for (int i = 1; i < 10; ++i) {
    cnt += f[i];
  }
  if (cnt + f[0] == 1) {
    return 1;
  }
  __uint128_t sum1 = a[cnt], cnt1 = 0;
  for (int i = 1; i < 10; ++i) {
    sum1 /= a[f[i]];
  }
  ++cnt;
  for (int j = 0; j < min(f[0], cnt); ++j) {
    cnt1 += C(j + 1, cnt) * C(j, f[0] - 1);
  }
  if (f[0]) {
    return sum1 * cnt1;
  }
  return sum1;
}

int main() {
  freopen("perm.in", "r", stdin);
  freopen("perm.out", "w", stdout);
  a[0] = a[1] = 1;
  for (int i = 2; i < 35; ++i) {  //预处理阶乘
    a[i] = a[i - 1] * i;
  }
  string s;
  cin >> s;
  n = s.size();
  if (n == 1) {
    putchar(48);
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    ++f[s[i] - '0'];
    if (s[i] > '0') {
      ++cnt;
    }
  }
  __uint128_t sum1 = a[cnt], cnt1 = 1, ans;

  if (f[0]) {
    for (int i = 1; i < 10; ++i) {
      sum1 /= a[f[i]];
    }
    for (int i = 1; i < f[0]; ++i) {
      for (int j = 0; j < min(i, cnt); ++j) {
        cnt1 += C(j + 1, cnt) * C(j, i);
      }
    }
    ans = cnt1 * sum1;
  } else {
    ans = 0;
  }
  for (int i = 1; i < s[0] - '0'; ++i) {
    if (f[i]) {
      --f[i];
      ans += shit();
      ++f[i];
    }
  }
  --f[s[0] - '0'];
  for (int i = 1; i < s.size(); ++i) {
    for (int j = 0; j < s[i] - '0'; ++j) {
      if (f[j]) {
        --f[j];
        ans += shit();
        ++f[j];
      }
    }
    --f[s[i] - '0'];
  }
  w(ans);
  return 0;
}