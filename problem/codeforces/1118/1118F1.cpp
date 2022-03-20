#include <iostream>
#include <vector>

using namespace std;

const int kN = 3e5 + 1;

int n, a[kN], s[3][kN], ans;
vector<int> e[kN];

void D(int x, int f) {
  s[a[x]][x] = 1;
  for (int i : e[x]) {
    if (i != f) {
      D(i, x), s[1][x] += s[1][i], s[2][x] += s[2][i];
    }
  }
}
void S(int x, int f) {
  ans += !s[1][x] && s[2][x] == s[2][1] || !s[2][x] && s[1][x] == s[1][1];
  for (int i : e[x]) {
    if (i != f) {
      S(i, x);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  D(1, 0), S(1, 0);
  cout << ans;
  return 0;
}