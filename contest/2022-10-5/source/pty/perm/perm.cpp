#include <algorithm>
#include <fstream>

using namespace std;
using LL = long long;

const int kMaxN = 51;

ifstream fin("perm.in");
ofstream fout("perm.out");

string s;
int f[kMaxN], a[kMaxN], c[kMaxN], t[kMaxN], c0, n;
LL ans;

void R(int n, int v) {
  for (; n > 1; n /= f[n]) {
    t[f[n]] += v;
  }
}

void S(int n) {
  fill(t, t + kMaxN, 0);
  for (int i = 2; i <= n; i++) {
    R(i, 1);
  }
  for (int i = 0; i <= 9; i++) {
    for (int j = 2; j <= c[i]; j++) {
      R(j, -1);
    }
  }
  LL tot = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= t[i]; j++) {
      tot *= i;
    }
  }
  ans += tot;
}

void C1(int n) {
  for (int i = 1; i <= 9; i++) {
    if (c[i]) {
      c[i]--;
      S(n - 1);
      c[i]++;
    }
  }
}

int main() {
  fin >> s, n = s.size();
  for (int i = 0; i < n; i++) {
    a[i] = s[n - 1 - i] - '0';
    c[a[i]]++;
  }
  for (int i = 2; i <= n; i++) {
    if (!f[i]) {
      for (int j = i; j <= n; j += i) {
        f[j] = i;
      }
    }
  }
  c0 = c[0];
  for (int i = 1; i <= c0; i++) {
    c[0] = c0 - i;
    C1(n - i);
  }
  c[0] = c0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i == n - 1; j < a[i]; j++) {
      if (c[j]) {
        c[j]--;
        S(i);
        c[j]++;
      }
    }
    if (!c[a[i]]) {
      break;
    }
    c[a[i]]--;
  }
  fout << ans;
  return 0;
}