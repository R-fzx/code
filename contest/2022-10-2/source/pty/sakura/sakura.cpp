#include <fstream>

using namespace std;
using LL = long long;

const int kMaxN = 1e6 + 1, kM = 1e9 + 7;

ifstream fin("sakura.in");
ofstream fout("sakura.out");

int f[kMaxN], c[kMaxN], n;
LL ans = 1, v1 = 1, v2 = 1, v20 = 1, v21 = 1;

int main() {
  fin >> n;
  if (n >= 2) {
    for (int i = 2; i <= n; i++) {
      if (!f[i]) {
        for (int j = i; j <= n; j += i) {
          f[j] = i;
        }
      }
      for (int j = i; j > 1; j /= f[j]) {
        c[f[j]]++;
      }
    }
    for (int i = 2; i <= n; i++) {
      if (c[i]) {
        v1 = v1 * (c[i] + 1) % kM;
        v2 = v2 * 2 % kM;
        v20 = v20 * (c[i] * 2 + 1) % kM;
        v21 = v21 * (c[i] + 1) % kM;
      }
    }
    ans = (ans + (v1 + kM - 1) * 2) % kM;
    ans = ans + (v20 + (kM - v21) * 2 + 1) % kM;
  }
  fout << ans;
  return 0;
}