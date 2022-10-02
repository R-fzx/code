#include <algorithm>
#include <iostream>
#include <list>
#include <iomanip>

using namespace std;

long long b[11], temp[11];
int n, a[301];
long double ans;
list<int> v;

void Find() {
  v.push_back(1);
  b[1] = 1;
  for (int i = 1; i < n; i++) {
    int s = v.size();
    for (int j = 0; j < s; j++) {
      for (int k = 1; k <= i + 1; k++) {
        if (!temp[v.front() + k] && !b[v.front() + k]) {
          v.push_back(v.front() + k);
        }
        temp[v.front() + k] += b[v.front()];
      }
      v.pop_front();
    }
    for (int j = 0; j <= (s + 2) * (s + 1) / 2; j++) {
      b[j] = temp[j];
      temp[j] = 0;
    }
    cout << endl;
  }
}

int main() {
  freopen("queue.in", "r", stdin);
  freopen("queue.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  Find();
  for (int i = 0; i < 100001; i++) {
    ans += b[i] * i;
  }
  for (int i = 1; i <= n;i++) {
    ans /= i;
  }
    cout << fixed << setprecision(2) << ans;
  return 0;
}