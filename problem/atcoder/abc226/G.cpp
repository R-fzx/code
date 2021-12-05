#include <iostream>
#include <map>
#include <vector>

using namespace std;
using LL = long long;

const LL kM = 998244353;
const int kN = 1e6 + 1;

LL n, k, m[kN];
map<LL, int> f;
vector<LL> l;

int main() {
  cin >> n >> k;
  for (int i = 2; i < kN; ++i) {
    if (!m[i]) {
      for (int j = i; j < kN; j += i) m[j] = i;
      
    }
  }
  return 0;
}