#include <fstream>

using namespace std;
using LL = long long;

const int kL = 20;

ifstream fin("sillyz.in");
ofstream fout("sillyz.out");

int a[kL], c[10], _c[10], f[kL], t[kL];
LL l, r, ans, ansr;

int B(LL n) {
  int c = 0;
  for (; n; n /= 10) {
    c++;
  }
  return c;
}

void R(int n, int v) {
  for (; n > 1; n /= f[n]) {
    t[f[n]] += v;
  }
}

void D(int s) {
  fill(t, t + kL, 0);
  for (int i = 2; i <= s; i++) {
    R(i, 1);
  }
  for (int i = 1; i <= 9; i++) {
    for (int j = 2; j <= c[i]; j++) {
      R(j, -1);
    }
  }
  LL r = 1;
  for (int i = 2; i < kL; i++) {
    for (int j = 1; j <= t[i]; j++) {
      r *= i;
    }
  }
  ans += r;
}

void W(int s, LL n) {
  if (!s) {
    return;
  }
  if (s < B(n)) {
    D(s);
    return;
  }
  for (int i = 0; i < s; i++) {
    a[i] = n % 10;
    n /= 10;
  }
  for (int i = s - 1; i >= 0; i--) {
    for (int j = 1; j < a[i]; j++) {
      if (c[j]) {
        c[j]--;
        D(i);
        c[j]++;
      }
    }
    if (!c[a[i]]) {
      return;
    }
    c[a[i]]--;
  }
  ans++;
}

void S(int i, int s, LL n) {
  if (s > B(n)) {
    return;
  }
  if (i == 10) {
    copy(c, c + 10, _c);
    W(s, n);
    copy(_c, _c + 10, c);
    return;
  }
  S(i + 1, s, n);
  c[i]++;
  S(i, s + 1, n / i);
  c[i]--;
}

int main() {
  for (int i = 2; i < kL; i++) {
    if (!f[i]) {
      for (int j = i; j < kL; j += i) {
        f[j] = i;
      }
    }
  }
  fin >> l >> r;
  ans = 0, S(1, 0, r), ansr = ans;
  ans = 0, S(1, 0, l - 1);
  fout << ansr - ans;
  return 0;
}
