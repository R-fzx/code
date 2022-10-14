#include <algorithm>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>

using namespace std;

int n;
pair<int, int> a[200001];
double ans = 3e6 + 1;

int main() {
  freopen("dark.in", "r", stdin);
  freopen("dark.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a, a + n);
  for (int i = 0; i < n && clock() <= 900; i++) {
    for (int j = i + 1; a[j].first - a[i].first < ans && j < n && clock() <= 900; j++) {
      ans = min(ans, (double)sqrt((double)(a[i].first - a[j].first) * (a[i].first - a[j].first) + (double)(a[i].second - a[j].second) * (a[i].second - a[j].second)));
    }
  }
  cout << fixed << setprecision(3) << ans / 2.0 << endl;
  return 0;
}