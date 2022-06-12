#include <atcoder/all>
#include <bitset>

using namespace std;
using namespace atcoder;
using mL = modint998244353;
using B = bitset<26>;

const int kN = 18;

int n, l;
B a[kN];
mL ans;

mL C(B x) { return mL(x.count()).pow(l); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> l;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (char c : s) {
      a[i][c - 'a'] = 1;
    }
  }
  for (int i = 1, c; i < 1 << n; ++i) {
    B x = c = 0;
    x.flip();
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
        c ^= 1, x &= a[j];
      }
    }
    ans += C(x) * (c ? 1 : -1);
  }
  cout << ans.val();
  return 0;
}