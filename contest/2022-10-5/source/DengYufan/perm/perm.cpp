#include <iostream>
#define LL long long

using namespace std;

LL n, m, ans, a[10], c[50], prime[50];
string s;

void D(LL n, LL k) {
  for (LL i = n; i > 1; i /= prime[i]) {
    c[prime[i]] += k;
  }
}

LL R(LL n) {
  fill(&c[0], &c[50], 0);
  LL m = 0;
  for (LL i = 1; i < 10; i++) {
    m += a[i];
  }
  if (n < m || !m) {
    return 0;
  }
  for (LL i = 2; i <= n; i++) {
    D(i, 1);
  }
  for (LL i = 2; i <= n - m; i++) {
    D(i, -1);
  }
  for (LL i = 1; i < 10; i++) {
    for (LL j = 2; j <= a[i]; j++) {
      D(j, -1);
    }
  }
  LL t = 1;
  for (LL i = 2; i < 50; i++) {
    for (LL j = 1; j <= c[i]; j++) {
      t *= i;
    }
  }
  return t;
}

void W() {
  for (LL i = 0; i < n; i++) {
    for (LL j = !i; j < s[i] - '0'; j++) {
      if (a[j]) {
        a[j]--;
        ans += R(n - i - 1);
        a[j]++;
      }
    }
    if (!a[s[i] - '0']--) {
      return;
    }
  }
}

int main() {
  freopen("perm.in", "r", stdin);
  freopen("perm.out", "w", stdout);
  for (LL i = 2; i < 50; i++) {
    if (!prime[i]) {
      for (LL j = 1; i * j < 50; j++) {
        !prime[i * j] && (prime[i * j] = i);
      }
    }
  }
  cin >> s;
  n = m = s.size();
  for (char ch : s) {
    a[ch - '0']++, m -= ch == '0';
  }
  ans += R(n - 1), W();
  cout << ans;
  return 0;
}
