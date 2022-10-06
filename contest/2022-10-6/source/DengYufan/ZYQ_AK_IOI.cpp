#include <iostream>
#define LL long long

using namespace std;

const LL kPrime[21] = {0, 0, 2, 3, 2, 5, 2, 7, 2, 3, 2, 11, 2, 13, 2, 3, 2, 17, 2, 19, 2};
LL l, r, ans, _ans, a[20], c[10], _c[10], d[20];

LL Length(LL n) {
  LL l = 0;
  for (; n; n /= 10) {
    l++;
  }
  return l;
}

LL A(LL s) {
  LL t = 1;
  fill(&d[0], &d[20], 0);
  for (LL i = 2; i <= s; i++) {
    for (LL j = i; j > 1; j /= kPrime[j]) {
      d[kPrime[j]]++;
    }
  }
  for (LL i = 1; i <= 9; i++) {
    for (LL j = 2; j <= c[i]; j++) {
      for (LL k = j; k > 1; k /= kPrime[k]) {
        d[kPrime[k]]--;
      }
    }
  }
  for (LL i = 1; i <= 19; i++) {
    for (LL j = 1; j <= d[i]; j++) {
      t *= i;
    }
  }
  return t;
}

void CalcAns(LL s, LL n) {
  if (!s) {
    return;
  } else if (s < Length(n)) {
    ans += A(s);
    return;
  }
  for (LL i = 0; i < s; i++) {
    a[i] = n % 10, n /= 10;
  }
  for (LL i = s - 1; i >= 0; i--) {
    for (LL j = 1; j < a[i]; j++) {
      if (c[j]) {
        c[j]--, ans += A(i), c[j]++;
      }
    }
    if (!c[a[i]]--) {
      return;
    }
  }
  ans++;
}

void M(LL x, LL s, LL n) {
  if (s > Length(n)) {
    return;
  } else if (x == 10) {
    copy(&c[0], &c[10], &_c[0]);
    CalcAns(s, n);
    copy(&_c[0], &_c[10], &c[0]);
    return;
  }
  M(x + 1, s, n);
  c[x]++, M(x, s + 1, n / x), c[x]--;
}

int main() {
  cin >> l >> r;
  M(1, 0, l - 1), _ans = ans;
  ans = 0, M(1, 0, r);
  cout << ans - _ans;
  return 0;
}
