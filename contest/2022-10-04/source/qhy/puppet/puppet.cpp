#include <algorithm>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

int n;
int p[50];
int g[50][50], f[50];

int main() {
  ifstream cin("puppet.in");
  ofstream cout("puppet.out");

  while (cin >> n) {
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
    }
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        bool f = 1;
        for (int k = 1; k <= j - i + 1; k++) {
          for (int w = i; w + k <= j; w++) {
            if (p[w + k] > p[w] + 1) {
              f = 0;
            }
          }
          if (!f || abs(p[j - k + 1] - p[i + k - 1]) <= 1) {
            g[i][j] = k - 1;
            break;
          }
        }
        if (f) {
          g[i][j] = j - i + 1;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        f[i] = max(f[i], f[j] + g[j + 1][i]);
      }
    }
    cout << f[n] << '\n';
  }
  return 0;
}