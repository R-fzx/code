#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
using ll = long long;

const int kM = 1e9 + 7;
const int kMaxN = 1e6 + 1;

bool fpri[kMaxN];
int prime[kMaxN];
ll t[kMaxN], ans = 1;
int n, cnt;

void init() {
  fpri[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!fpri[i]) {
      prime[cnt++] = i;
    }
    for (int j = 0; j < cnt && i * prime[j] <= n; j++) {
      fpri[i * prime[j]] = 1;
    }
  }
}

int main() {
  ifstream cin("sakura.in");
  ofstream cout("sakura.out");

  cin >> n;
  init();
  for (int i = 0; i < cnt; i++) {
    int p = prime[i];
    for (ll j = p; j <= n; j *= p) {
      t[i] += (n / j);
    }
    t[i] %= kM;
  }
  for (int i = 0; i < cnt; i++) {
    ans *= ((t[i] << 1) + 1), ans %= kM;
  }
  cout << ans << endl;
  return 0;
}