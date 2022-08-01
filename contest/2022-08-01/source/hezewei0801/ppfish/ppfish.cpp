#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

string A[201], B, s;
int p[201][21], n, k, num, z;
double q;
bool b[1000001];
double map[1001][1001];

struct dot {
  int num, place;
  double ans;
} Dot[201];

bool C_1(dot a, dot b) {
  return a.num < b.num;
}

bool C_2(dot a, dot b) {
  return a.place < b.place;
}

// kmp预处理
void P(int x) {
  int j = 0;
  for (int i = 1; i < A[x].length() - 1; i++) {
    while (A[x][j + 1] != A[x][i + 1] && j) {
      j = p[x][j];
    }
    if (A[x][j + 1] == A[x][i + 1]) {
      j++;
    }
    p[x][i] = j;
  }
}

// kmp获取答案
int Ans(int x) {
  int ans = 0, j = 0;
  for (int i = 0; i < B.length() - 1; i++) {
    while (A[x][j + 1] != B[i + 1] && j) {
      j = p[x][j];
    }
    if (A[x][j + 1] == B[i + 1]) {
      j++;
    }
    if (j == A[x].length() - 1) {
      ans++;
      j = p[x][j];
    }
  }
  return ans;
}

int main() {
  freopen("ppfish.in", "r", stdin);
  freopen("ppfish.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    A[i] = ' ' + s;
    P(i);
  }
  cin >> s;
  B = ' ' + s;
  for (int i = 0; i < n; i++) {
    Dot[i].place = i;     // 出现位置
    Dot[i].num = Ans(i);  // 出现次数
    Dot[i].ans = 1;       // 处理重复次数内一定能记住的情况
  }
  cin >> q >> k;
  map[0][0] = 1;
  // 预处理每种情况的可能性
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      map[i][j + 1] += map[i][j] * q;
      map[i + 1][j] += map[i][j] * (1 - q);
    }
  }
  sort(Dot, Dot + n, C_1);  // 按出现次数排列
  for (int i = 0; i <= k; i++, z++) {
    Dot[z].ans = map[i][k - i];
    if (k - i >= 1) {                          // 防止访问越界
      map[i + 1][k - i - 1] += map[i][k - i];  // 叠加上一种可能性（包含上一种可能性）
    }
    while (Dot[z].num == Dot[z + 1].num) {  // 出现次数相同
      Dot[z + 1].ans = Dot[z].ans;          // 答案复制
      z++;
    }
  }
  sort(Dot, Dot + n, C_2);  //按出现顺序排列
  for (int i = 0; i < n; i++) {
    cout << fixed << setprecision(3) << Dot[i].ans << ' ';
  }
  return 0;
}