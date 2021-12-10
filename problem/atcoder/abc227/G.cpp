#include <iostream>
#include <vector>
#include <map>
#include <ctime>

using namespace std;
using LL = long long;

const int kV = 1e6 + 5;
const LL kM = 998244353;

LL n, k, c = 1;
bool v[kV];
vector<LL> p[kV << 1];
map<int, LL> m;

int main() {
  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);
  cin >> n >> k;
  for (int i = 2; i < kV; ++i) {
    if (!v[i]) {
      p[i].push_back(i);
      for (int j = i << 1; j < kV; j += i) {
        v[j] = 1, p[j].push_back(i);
      }
      for (LL j = (n - k + i) / i * i; j <= n; j += i) {
        p[j - (n - k + 1) + kV].push_back(i);
      }
    }
  }
  cerr << "INIT" << endl;
  for (int i = 2; i <= k; ++i) {
    int x = i;
    for (int j : p[i]) {
      for (; x % j == 0; x /= j) --m[j];
    }
    if (x != 1) --m[x];
  }
  for (int i = kV; i < kV + k; ++i) {
    LL x = n - k + 1 + i - kV;
    for (int j : p[i]) {
      for (; x % j == 0; x /= j) ++m[j];
    }
    if (x != 1) ++m[x];
  }
  cerr << "CALC" << endl;
  for (auto x : m) {
    c = c * (x.second + 1) % kM;
  }
  cerr << "SOLVE" << endl;
  cout << c;
  cerr << clock() << endl;
  return 0;
}