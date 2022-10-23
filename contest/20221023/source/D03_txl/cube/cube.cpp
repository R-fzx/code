#include <bits/stdc++.h>
using namespace std;
ifstream fin("cube.in");
ofstream fout("cube.out");
const int kMaxN = 1e5 + 1;
int n, d[120][120][120];
long long sum;
bool f1[120][120][120];
struct node {
  int x0, y0, z0, x2, y2, z2;
} s[kMaxN];
int main() {
  fin >> n;
  for (int i = 1; i <= n; i++) {
    fin >> s[i].x0 >> s[i].y0 >> s[i].z0 >> s[i].x2 >> s[i].y2 >> s[i].z2;
  }
  for (int i = 1; i <= n; i++) {
    for (int x = s[i].x0; x <= s[i].x2; x++) {
      for (int y = s[i].y0; y <= s[i].y2; y++) {
        for (int z = s[i].z0; z <= s[i].z2; z++) {
          d[x + 50][y + 50][z + 50]++;
          if ((d[x + 50][y + 50][z + 50] >= (n - 1)) && (f1[x + 50][y + 50][z + 50] == 0)) {
            sum++;
            f1[x + 50][y + 50][z + 50] = 1;
          }
        }
      }
    }
  }
  fout << sum;
  return 0;
}