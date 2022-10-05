// desert 暴力枚举+BFS
#include <iostream>
#include <list>
#include <vector>

using namespace std;

const int kMaxV = 1e9 + 7;

int n, wind[10], sx, sy;             // wind:风向 sx&sy:起点位置
long long ans = kMaxV, val[51][51];  // val：走到该点所需的最小价值
char ch[51][51];                     // 地图
vector<pair<int, int>> G;            // G->green 绿洲数量&位置
list<pair<int, int>> F;              // BFS查找队列

void Check() {  // 查找到达任意绿地的最小价值
  for (int i = 0; i < G.size(); i++) {
    if (val[G[i].first][G[i].second] != 0) {
      ans = min(ans, val[G[i].first][G[i].second] - 1);  // 比较，取最小值作为答案
    }
  }
}

void Reset() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      val[i][j] = 0;
    }
  }
}

void Find() {  // BFS查找最小代价
  while (!F.empty()) {
    int x = F.front().first, y = F.front().second;
    F.pop_front();
    if (ch[x][y] == '*') {  // 到达绿洲
      continue;
    }
    if (x + 1 < n && ch[x + 1][y] != '@') {  // 下
      if (val[x + 1][y] == 0) {
        F.push_back({x + 1, y});
        val[x + 1][y] = val[x][y] + wind[0];
      } else if (val[x + 1][y] > val[x][y] + wind[0]) {
        val[x + 1][y] = val[x][y] + wind[0];
      }
    }
    if (x > 0 && ch[x - 1][y] != '@') {  // 上
      if (val[x - 1][y] == 0) {
        F.push_back({x - 1, y});
        val[x - 1][y] = val[x][y] + wind[1];
      } else if (val[x - 1][y] > val[x][y] + wind[1]) {
        val[x - 1][y] = val[x][y] + wind[1];
      }
    }
    if (y + 1 < n && ch[x][y + 1] != '@') {  // 右
      if (val[x][y + 1] == 0) {
        F.push_back({x, y + 1});
        val[x][y + 1] = val[x][y] + wind[2];
      } else if (val[x][y + 1] > val[x][y] + wind[2]) {
        val[x][y + 1] = val[x][y] + wind[2];
      }
    }
    if (y > 0 && ch[x][y - 1] != '@') {  // 左
      if (val[x][y - 1] == 0) {
        F.push_back({x, y - 1});
        val[x][y - 1] = val[x][y] + wind[3];
      } else if (val[x][y - 1] > val[x][y] + wind[3]) {
        val[x][y - 1] = val[x][y] + wind[3];
      }
    }
    if (x + 1 < n && y + 1 < n && ch[x + 1][y + 1] != '@') {  // 右下
      if (val[x + 1][y + 1] == 0) {
        F.push_back({x + 1, y + 1});
        val[x + 1][y + 1] = val[x][y] + wind[4];
      } else if (val[x + 1][y + 1] > val[x][y] + wind[4]) {
        val[x + 1][y + 1] = val[x][y] + wind[4];
      }
    }
    if (x + 1 < n && y > 0 && ch[x + 1][y - 1] != '@') {  // 左下
      if (val[x + 1][y - 1] == 0) {
        F.push_back({x + 1, y - 1});
        val[x + 1][y - 1] = val[x][y] + wind[5];
      } else if (val[x + 1][y - 1] > val[x][y] + wind[5]) {
        val[x + 1][y - 1] = val[x][y] + wind[5];
      }
    }
    if (x > 0 && y + 1 < n && ch[x - 1][y + 1] != '@') {  // 右上
      if (val[x - 1][y + 1] == 0) {
        F.push_back({x - 1, y + 1});
        val[x - 1][y + 1] = val[x][y] + wind[6];
      } else if (val[x - 1][y + 1] > val[x][y] + wind[6]) {
        val[x - 1][y + 1] = val[x][y] + wind[6];
      }
    }
    if (x > 0 && y > 0 && ch[x - 1][y - 1] != '@') {  // 左上
      if (val[x - 1][y - 1] == 0) {
        F.push_back({x - 1, y - 1});
        val[x - 1][y - 1] = val[x][y] + wind[7];
      } else if (val[x - 1][y - 1] > val[x][y] + wind[7]) {
        val[x - 1][y - 1] = val[x][y] + wind[7];
      }
    }
  }
}

int main() {
  freopen("desert.in", "r", stdin);
  freopen("desert.out", "w", stdout);
  for (int i = 0; i < 8; i++) {  // 风向初始化
    wind[i] = 1;
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> ch[i][j];
      if (ch[i][j] == '*') {
        G.push_back({i, j});  // 记录绿地位置
      } else if (ch[i][j] == '@') {
        sx = i, sy = j;  // 记录起点位置
      }
    }
  }
  for (int i = 0; i < 8; i++) {
    wind[i] = 3;            // 改变风向
    val[sx][sy] = 1;        // 设定初始值，防止再次回到起点
    F.push_back({sx, sy});  // 起点放入队列
    Find();
    Check();
    wind[i] = 1;  // 重置风向
    Reset();      // 重置地图
  }
  cout << (ans == kMaxV ? -1 : ans) << endl;
  return 0;
}