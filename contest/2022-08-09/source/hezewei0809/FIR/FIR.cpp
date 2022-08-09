#include <iostream>

using namespace std;

short map[1001][1001];
bool b[1001][1001];
int n, x, y, num;

bool Find(int x, int y) {
  b[x][y] = 1;
  bool k = 0;
  if (map[x][y + 1] && map[x + 1][y] && map[x - 1][y] && map[x][y - 1]) {
    k = 1;
  }
  if (k == 0) {
    return 0;
  }
  if (map[x][y] == map[x][y + 1] && !b[x][y + 1]) {
    if (!Find(x, y + 1)) {
      return 0;
    }
  }
  if (map[x][y] == map[x + 1][y && !b[x + 1][y]]) {
    if (!Find(x + 1, y)) {
      return 0;
    }
  }
  if (map[x][y] == map[x][y - 1] && !b[x][y - 1]) {
    if (!Find(x, y - 1)) {
      return 0;
    }
  }
  if (map[x][y] == map[x - 1][y] && !b[x - 1][y]) {
    if (!Find(x - 1, y)) {
      return 0;
    }
  }
  return 1;
}

void Delete(int x, int y, int z) {
  b[x][y] = 0;
  map[x][y] = z;
  if (b[x][y + 1]) {
    Delete(x, y + 1, z);
  }
  if (b[x + 1][y]) {
    Delete(x + 1, y, z);
  }
  if (b[x][y - 1]) {
    Delete(x, y - 1, z);
  }
  if (b[x - 1][y]) {
    Delete(x - 1, y, z);
  }
}

void Check_Eat(int x, int y) {
  if (map[x][y - 1] != map[x][y] && map[x][y - 1]) {
    if (Find(x, y - 1)) {
      Delete(x, y - 1, 0);
    } else {
      Delete(x, y - 1, map[x][y - 1]);
    }
  }
  if (map[x][y + 1] != map[x][y] && map[x][y + 1]) {
    if (Find(x, y + 1)) {
      Delete(x, y + 1, 0);
    } else {
      Delete(x, y + 1, map[x][y + 1]);
    }
  }
  if (map[x - 1][y] != map[x][y] && map[x - 1][y]) {
    if (Find(x - 1, y)) {
      Delete(x - 1, y, 0);
    } else {
      Delete(x - 1, y, map[x - 1][y]);
    }
  }
  if (map[x + 1][y] != map[x][y] && map[x + 1][y]) {
    if (Find(x + 1, y)) {
      Delete(x + 1, y, 0);
    } else {
      Delete(x + 1, y, map[x + 1][y]);
    }
  }
}

bool Check_Can(int x, int y, int k) {
  if (map[x][y] != 0) {
    return 0;
  }
  map[x][y] = k;
  Check_Eat(x, y);
  if (Find(x, y)) {
    return 0;
  }
  Delete(x, y, k);
  return 1;
}

bool Check_Win(int x, int y) {
  int ans(0);
  for (int i(0); y - i && map[x][y - i] == map[x][y]; ++i, ++ans) {
  }
  for (int i(1); map[x][y + i] == map[x][y]; ++i, ++ans) {
  }
  if (ans >= num) {
    return 1;
  }
  ans = 0;
  for (int i(0); x - i && map[x - i][y] == map[x][y]; ++i, ++ans) {
  }
  for (int i(1); map[x + i][y] == map[x][y]; ++i, ++ans) {
  }
  if (ans >= num) {
    return 1;
  }
  ans = 0;
  for (int i(0); y - i && map[x - i][y - i] == map[x][y]; ++i, ++ans) {
  }
  for (int i(1); map[x + 1][y + i] == map[x][y]; ++i, ++ans) {
  }
  if (ans >= num) {
    return 1;
  }
  return 0;
}

int main() {
  freopen("FIR.in", "r", stdin);
  freopen("FIR.out", "w", stdout);
  cin >> n >> num;
  for (int i(0); i < n; i++) {
    cin >> x >> y;
    if (!Check_Can(x, y, i % 2 + 1)) {
      cout << "illegal";
      return 0;
    }
    if (Check_Win(x, y)) {
      cout << (i % 2 == 0 ? "ITer" : "Kitty") << ' ' << i + 1;
      return 0;
    }
  }
  cout << "draw";
  return 0;
}