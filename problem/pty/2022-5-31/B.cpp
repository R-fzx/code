#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int kN = 2e5 + 1;

int n, a[kN], c[kN];
priority_queue<int, vector<int>, greater<int>> q;

void R(int x) {
  if (!c[x]) {
    q.push(x);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for_each(a + 1, a + n, [](int &x) { cin >> x, ++c[x]; });
  for (int i = 1; i <= n; R(i++)) {
  }
  cout << a[1] << endl;
  for (int i = n - 1; i >= 1; --i) {
    int x = q.top();
    q.pop(), cout << x << " " << a[i] << endl, --c[a[i]], R(a[i]);
  }
  return 0;
}