#include <iostream>
#define LL long long

using namespace std;

const LL kMod = 1e9 + 7;
LL n, m[11], ans[11], c[11], f[100001][11], fact[100001] = {1}, _fact[100001] = {1};
string l, r, s;

LL C(LL n, LL m) {
  return fact[n] * _fact[m] % kMod * _fact[n - m] % kMod;
}

LL Pow(LL x, LL y) {
  LL ans = 1;
  for (LL i = 1; i <= y; i <<= 1) {
    if (i & y) {
      ans = ans * x % kMod;
    }
    x = x * x % kMod;
  }
  return ans;
}

void W(LL n) {
  LL m = 0;
  for (LL i = 0; i <= 9; i++) {
    m += c[i] > 0;
  }
  for (LL i = 0; i <= min(10 - m, n); i++) {
    ans[i + m] = (ans[i + m] + Pow(i + m, n - i) * C(n, i) % kMod * fact[i] % kMod * C(10 - m, i) % kMod) % kMod;
    // n个位置填i+m种数，i种必选，m种可选。
    // 考虑n-i个位置中可以在i+m个数中随便取，剩下i个位置可以在i个数中分别取一个且有顺序，且这i个数可以在0-9中随便选不与之前相同的。
    // 但是n-i与i里面的数之间会有重复。
    // ans[i + m] = (ans[i + m] + Pow(m * (i + m) % kMod, n * (n - 1) / 2) * Pow(i, n) % kMod) % kMod;
  }
}

void M() {
  fill(c, c + 11, 0);
  for (LL i = 1; i < s.size(); i++) {
    for (LL j = 1; j <= 10; j++) {
      ans[j] = (ans[j] + f[i][j]) % kMod;
    }
  }
  for (LL i = 0; i < s.size(); i++) {
    for (LL j = !i; j < s[i] - '0'; j++) {
      c[j]++, W(s.size() - i - 1), c[j]--;
    }
    c[s[i] - '0']++;
  }
}

int main() {
  freopen("P1160.in", "r", stdin);
  cin >> l >> r;
  f[1][1] = 9;
  for (LL i = 2; i <= 100000; i++) {
    for (LL j = 1; j <= 10; j++) {
      f[i][j] = (f[i - 1][j] * j % kMod + f[i - 1][j - 1] * (11 - j) % kMod) % kMod;
    }
  }
  for (LL i = 1; i <= 100000; i++) {
    fact[i] = fact[i - 1] * i % kMod;
  }
  _fact[100000] = Pow(fact[100000], kMod - 2);
  for (LL i = 99999; i >= 1; i--) {
    _fact[i] = _fact[i + 1] * (i + 1) % kMod;
  }
  s = l, M();
  copy(ans, ans + 11, m), fill(ans, ans + 11, 0);
  s = r, M();
  W(0);
  for (LL i = 1; i <= 10; i++) {
    cout << (ans[i] - m[i] + kMod) % kMod << ' ';
  }
  return 0;
}
