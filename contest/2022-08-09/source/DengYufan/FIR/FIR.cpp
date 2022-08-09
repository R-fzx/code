#include <iostream>
#define LL long long

using namespace std;

const int kMove1[3][2] = {{1, 0}, {1, 1}, {0, 1}}, kMove2[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, x, b[1001][1001], d[1001][1001];
pair<int, int> a[1001];

bool Win(int p, int q) {
  for (int i = 0; i < 3; i++) {
    int c = 1;
    for (int j = 1; c < x && max(p + j * kMove1[i][0], q + j * kMove1[i][1]) <= 1000 && d[p + j * kMove1[i][0]][q + j * kMove1[i][1]] == d[p][q]; j++, c++) {
    }
    for (int j = 1; c < x && min(p - j * kMove1[i][0], q - j * kMove1[i][1]) >= 1 && d[p - j * kMove1[i][0]][q - j * kMove1[i][1]] == d[p][q]; j++, c++) {
    }
    if (c >= x) {
      return 1;
    }
  }
  return 0;
}

bool Eat(int k, int p, int q) {
  if (b[p][q] == k) {
    return 1;
  }
  b[p][q] = k;
  for (int i = 0; i < 4; i++) {
    if (p + kMove2[i][0] < 1 || p + kMove2[i][0] > 1000 || q + kMove2[i][1] < 1 || q + kMove2[i][1] > 1000 || !d[p + kMove2[i][0]][q + kMove2[i][1]]) {
      return 0;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (d[p + kMove2[i][0]][q + kMove2[i][1]] == d[p][q] && !Eat(k, p + kMove2[i][0], q + kMove2[i][1])) {
      return 0;
    }
  }
  return 1;
}

void Fill(int p, int q) {
  int c = d[p][q];
  d[p][q] = 0;
  for (int i = 0; i < 4; i++) {
    if (d[p + kMove2[i][0]][q + kMove2[i][1]] == c) {
      Fill(p + kMove2[i][0], q + kMove2[i][1]);
    }
  }
}

int main() {
  freopen("FIR.in", "r", stdin);
  freopen("FIR.out", "w", stdout);
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 1; i <= n; i++) {
    if (d[a[i].first][a[i].second]) {
      cout << "illegal";
      return 0;
    }
    d[a[i].first][a[i].second] = i & 1 ? 1 : -1;
    for (int j = 0; j < 4; j++) {
      if (Eat(i * 5 + j + 1, a[i].first + kMove2[j][0], a[i].second + kMove2[j][1])) {
        Fill(a[i].first + kMove2[j][0], a[i].second + kMove2[j][1]);
      }
    }
    if (Eat(i * 5, a[i].first, a[i].second)) {
      cout << "illegal";
      return 0;
    }
    if (Win(a[i].first, a[i].second)) {
      cout << (i & 1 ? "ITer " : "Kitty ") << i;
      return 0;
    }
  }
  cout << "draw";
  return 0;
}
