#include <iostream>

using namespace std;

const int kMove[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
int n, m, k, x, y;
bool b[11];
pair<int, int> a[11];

bool Chick() {
  for (int i = 1; i <= k; i++) {
    if (b[i] && (a[i].first < 1 || a[i].second < 1 || a[i].first > n || a[i].second > m)) {
      return 1;
    }
  }
  for (int i = 1; i <= k; i++) {
    for (int j = i + 1; j <= k; j++) {
      if (a[i].first == a[j].first && a[i].second == a[j].second) {
        return 1;
      }
    }
  }
  return 0;
}

bool Chick2() {
  for (int i = 1; i <= k; i++) {
    if (b[i] && (a[i].first != x || a[i].second != y)) {
      return 0;
    }
  }
  return 1;
}

bool S(int k) {
  if (Chick()) {
    return 0;
  } else if (k == 1 && Chick2()) {
    return 1;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      for (int l = 0; l < 8; l++) {
        if (a[i].first + kMove[l][0] == a[j].first && a[i].second + kMove[l][1] == a[j].second) {
          b[j] = 0;
          a[i].first += 2 * kMove[l][0], a[i].second += 2 * kMove[l][1];
          if (S(k - 1)) {
            return 1;
          }
          b[j] = 1;
          a[i].first -= 2 * kMove[l][0], a[i].second -= 2 * kMove[l][1];
        }
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < 8; j++) {
      a[i].first += 3 * kMove[j][0], a[i].second += 3 * kMove[j][1];
      if (S(k)) {
        return 1;
      }
      a[i].first -= 3 * kMove[j][0], a[i].second -= 3 * kMove[j][1];
    }
  }
  return 0;
}

int main() {
  freopen("galaxy.in", "r", stdin);
  freopen("galaxy.out", "w", stdout);
  while (cin >> k) {
    cin >> n >> m >> x >> y;
    fill(&b[0], &b[11], 1);
    for (int i = 1; i <= k; i++) {
      cin >> a[i].first >> a[i].second;
    }
    cout << (S(k) ? "Yes\n" : "No\n");
  }
  return 0;
}
