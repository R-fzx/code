#include <iostream>
#include <cstdio>
#include <algorithm> 

using namespace std;

const int N = 1005;

struct Node {
  int a, b, t, id;
}a[N];
int n, k, m, mxt, ans;
bool f[N];

bool cmp(Node x, Node y) {
  if (x.t == y.t) {
    return x.b > y.b;
  }
  return x.t < y.t;  
}

void dfs(int now, int t, int sum) {
  if (t == mxt) {
    ans = max(ans, sum);
    return ;
  } 
  if (now > n || now < 1) {
    return ;
  }
  if (a[now + 1].t >= t && !f[now + 1]) {
    f[now + 1] = 1;
    dfs(now + 1, t + 1, sum + a[now + 1].b);
    f[now + 1] = 0;
  } else {
    dfs(now + 1, t + 1, sum);
  }
  if (a[now - 1].t >= t && !f[now - 1]) {
    f[now - 1] = 1;
    dfs(now - 1, t + 1, sum + a[now - 1].b);
    f[now - 1] = 0;
  } else {
    dfs(now - 1, t + 1, sum);
  }
}
int main() {
  freopen("go.in", "r", stdin);
  freopen("go.out", "w", stdout);
  cin >> n >> k >> m;
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    cin >> a[x].b >> a[x].t;
    cout << a[x].t << endl;
    mxt = max(mxt, a[x].t);
  }  
  dfs(k, 0, a[k].b);  
  cout << ans;
  return 0;
}
