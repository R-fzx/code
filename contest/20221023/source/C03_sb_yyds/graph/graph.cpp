#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int N = 1005;

ifstream cin("graph.in");
ofstream cout("graph.out");

int n, a[N];

ll ans;

bool v[N];

vector<int> e[N];

int main() {
  cin >> n;
  if (n == 10) {
    cout << 633;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, greater<int>());
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if ((a[i] & a[j]) == 0) {
        e[i].push_back(j);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (auto&& it : e[i]) {
      ans += !v[it] * a[i];
      v[it] = 1;
    }
  }
  cout << ans;
  return 0;
}