#include <iostream>

using namespace std;

int ans, c[5], e[4];
double a[5], _a[5];
bool b[5], _b[5];
pair<int, int> d[4];

void R(int n) {
  if (n == 4) {
    copy(&a[0], &a[5], &_a[0]);
    for (int i = 1; i < 4; i++) {
      if (e[i] == 1) {
        _a[c[d[i].first]] += _a[c[d[i].second]];
      } else if (e[i] == 2) {
        _a[c[d[i].first]] -= _a[c[d[i].second]];
      } else if (e[i] == 3) {
        _a[c[d[i].first]] *= _a[c[d[i].second]];
      } else if (!_a[c[d[i].second]]) {
        return;
      } else {
        _a[c[d[i].first]] /= _a[c[d[i].second]];
      }
    }
    ans += abs(_a[c[d[3].first]] - 24.0) < 1e-6;
    return;
  }
  for (int i = 1; i < 5; i++) {
    e[n] = i;
    R(n + 1);
  }
}

void T(int n) {
  if (n == 4) {
    R(1);
    return;
  }
  for (int i = 1; i < 5 - n; i++) {
    for (int j = i + 1; j < 6 - n; j++) {
      if (!_b[i] && !_b[j]) {
        d[n] = {i, j}, _b[j] = 1;
        T(n + 1);
        _b[j] = 0;
      }
    }
  }
}

void S(int n) {
  if (n == 5) {
    T(1);
    return;
  }
  for (int i = 1; i < 5; i++) {
    if (!b[i]) {
      b[i] = 1, c[n] = i;
      S(n + 1);
      b[i] = 0;
    }
  }
}

int main() {
  cin >> a[1] >> a[2] >> a[3] >> a[4];
  S(1);
  cout << ans;
  return 0;
}
