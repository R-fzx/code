#include <fstream>

using namespace std;

ifstream fin("taiko.in");
ofstream fout("taiko.out");

const int kMaxK = 11;

int a[1 << kMaxK], k, w;

int main() {
  fin >> k, w = 1 << k;
  fout << string(k, '0');
  for (int v = w - 1, i = 0; i <= k; i++) {
    v = v * 2 % w;
    a[v] = 1;
  }
  for (int v = 0; v != w - 1;) {
    if (!a[v * 2 % w]) {
      v = v * 2 % w;
      fout << 0;
    } else if (!a[v * 2 % w + 1]) {
      v = v * 2 % w + 1;
      fout << 1;
    }
    a[v] = 1;
  }
  return 0;
}
