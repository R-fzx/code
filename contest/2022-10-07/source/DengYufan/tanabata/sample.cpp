#include <ctime>
#include <iostream>

using namespace std;

const int kMaxN = 1e5, kMaxM = 1e5, kMaxT = 1e5;
pair<int, int> a[kMaxT + 1];

bool Chick(int x, int y, int i) {
  for (int j = 0; j < i; j++) {
    if (a[j].first == x && a[j].second == y) {
      return 1;
    }
  }
  return 0;
}

int main() {
  freopen("tanabata.in", "w", stdout);
  srand(time(0));
  cout << kMaxN << ' ' << kMaxM << ' ' << kMaxT << '\n';
  for (int i = 1; i <= kMaxT; i++) {
    int x = rand() % kMaxN + 1, y = rand() % kMaxM + 1;
    while (Chick(x, y, i)) {
      x = rand() % kMaxN + 1, y = rand() % kMaxM + 1;
    }
    cout << x << ' ' << y << '\n';
  }
  return 0;
}
