// 搜索 优化：记录动物食物链条数，遍历过后可直接返回
#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b;
bool temp[100001];  // 消费者标记
int ans[100001];    // 该动物的食物链条数
vector<int> Animal[100001], Find;

int Find_Ans(int x) {
  if (!ans[x]) {                              // 未查找过的动物
    for (int i = 0; i < Animal[x].size();) {  // 遍历食物链
      ans[x] += Find_Ans(Animal[x][i++]);     // 答案记录（同时记录该动物食物链条数）
    }
  }
  return ans[x] ? ans[x] : 1;  // 拥有食物链返回食物链条数，否则返回1（食物链顶端）
}

long long Find_Start() {
  long long ans = 0;
  for (int i = 1; i <= n; i++) {  // 遍历动物查找生产者（起点）
    if (!temp[i]) {
      ans += Find_Ans(i);  // 从生产者（起点）开始遍历答案
    }
  }
  return ans;
}

int main() {
  freopen("lyx.in", "r", stdin);
  freopen("lyx.out", "w", stdout);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    temp[b] = 1;             // 消费者标记
    Animal[a].push_back(b);  // 食物链前往方向
  }
  cout << Find_Start();
  return 0;
}