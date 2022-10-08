#include <iostream>
#include <queue>
#include <vector>

#define x second.first
#define y second.second

using namespace std;

int n;
priority_queue<pair<int, pair<int, int>>> val;
int b[1001][1001];
vector<pair<int, pair<int, int>>> v;

int main() {
  freopen("rabbit.in", "r", stdin);
  freopen("rabbit.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      val.push({3, {i, j}});
      b[i][j] = 3;
    }
  }
  while (!val.empty() && val.top().first != 0) {
    pair<int, pair<int, int>> temp1 = val.top();
    int num = 0, temp2;
    val.pop();
    if (b[temp1.x][temp1.y] != temp1.first) {
      temp1.first = b[temp1.x][temp1.y];
      if (temp1.first != 0) {
        val.push(temp1);
      }
      continue;
    }
    for (int i = 1; i <= n; i++) {
      if (num < temp1.first + b[min(temp1.x, i)][max(i, temp1.x)] + b[min(temp1.y, i)][max(i, temp1.y)] && b[min(temp1.x, i)][max(i, temp1.x)] && b[min(temp1.y, i)][max(i, temp1.y)]) {
        temp2 = i;
        num = temp1.first + b[min(temp1.x, i)][max(i, temp1.x)] + b[min(temp1.y, i)][max(i, temp1.y)];
      }
    }
    if (num != 0) {
      v.push_back({temp2, {temp1.x, temp1.y}});
      temp1.first--;
      if (temp1.first != 0) {
        val.push(temp1);
      }
      b[min(temp1.x, temp2)][max(temp2, temp1.x)]--;
      b[min(temp1.y, temp2)][max(temp2, temp1.y)]--;
      b[temp1.x][temp1.y]--;
    }
  }
  cout << v.size() << endl;
  for (int i = 0;i < v.size(); i++) {
    cout << v[i].first << ' ' << v[i].x << ' ' << v[i].y << '\n';
  }
    return 0;
}