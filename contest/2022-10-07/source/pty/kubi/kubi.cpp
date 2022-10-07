#include <fstream>
#include <map>

using namespace std;
using LL = long long;

ifstream fin("kubi.in");
ofstream fout("kubi.out");

map<LL, int> p;
int t;
LL a, b, g, k;

LL G(LL a, LL b) { return b ? G(b, a % b) : a; }

int main() {
  for (fin >> t; t; t--) {
    fin >> a >> b >> k;
    g = G(a, b), a /= g, b /= g;
    a %= b;
    p.clear();
    for (int i = 1;; i++) {
      if (!a) {
        fout << i - 1 << ' ' << "0\n";
        break;
      }
      if (p[a]) {
        fout << p[a] - 1 << ' ' << i - p[a] << '\n';
        break;
      }
      p[a] = i;
      a = a * k % b;
    }
  }
  return 0;
}
