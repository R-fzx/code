#include <iostream>
#include <vector>

using namespace std;

const int kMaxL = 31;

string s;
vector<int> p[3];
long long f[kMaxL][kMaxL][kMaxL][kMaxL * kMaxL], ans;
int c[3], n, k;

int S(int x) {
  int s = 0;
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j < c[i]; j++) {
      s += p[i][j] > p[x][c[x]];
    }
  }
  return s;
}

int main() {
  cin >> s >> k;
  n = s.length(), k = min(k, n * n);
  for (int i = 0; i < n; i++) {
    int v = s[i] == 'K' ? 0 : (s[i] == 'E' ? 1 : 2);
    p[v].push_back(i + 1);
  }
  f[0][0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (c[0] = max(0, (int)(i - p[1].size() - p[2].size())); c[0] <= min((int)p[0].size(), i); c[0]++) {
      for (c[1] = max(0, (int)(i - c[0] - p[2].size())); c[1] <= min((int)p[1].size(), i - c[0]); c[1]++) {
        c[2] = i - c[0] - c[1];
        for (int x = 0; x <= 2; x++) {
          if (c[x] < p[x].size()) {
            int v = p[x][c[x]] + S(x) - i - 1;
            for (int j = v; j <= k; j++) {
              f[i + 1][c[0] + (x == 0)][c[1] + (x == 1)][j] += f[i][c[0]][c[1]][j - v];
            }
          }
        }
      }
    }
  }
  for (c[0] = 0; c[0] <= n; c[0]++) {
    for (c[1] = 0; c[1] <= n; c[1]++) {
      for (int j = 0; j <= k; j++) {
        ans += f[n][c[0]][c[1]][j];
      }
    }
  }
  cout << ans;
  return 0;
}