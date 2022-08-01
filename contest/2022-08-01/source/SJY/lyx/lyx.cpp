#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int N = 1e5 + 5;

int n, m, vis[N], ans[N], sum;
vector<int> q[N]; 

int dfs(int x) {
  vis[x] = 1;
  if (ans[x]) {
    return ans[x];
  }
  ans[x] = q[x].size();
  for (int i = 0; i < q[x].size(); ++i) {
    ans[x] += max(dfs(q[x][i]) - 1, 0);
  }
  return ans[x];
}

int main() {
  freopen("lyx.in", "r", stdin);
  freopen("lyx.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
	  int a, b;
	  cin >> a >> b;
	  q[a].push_back(b);
	}
	
	for (int i = 1; i <= n; ++i) {
	  int f = vis[i];
	  ans[i] = dfs(i);
	  vis[i] = f;
	}
	
	for (int i = 1; i <= n; ++i) {
	  if (!vis[i]) {
      sum += ans[i];
	  }
	}
	
	cout << sum;
	return 0;
}
