# include <stdio.h>
# include <vector>
# include <queue>

using namespace std;

int n, m, ans;
vector <int> edge[100100];
int in[100100], out[100100], cnt[100100];

int main() {
  freopen("lyx.in", "r", stdin);
  freopen("lyx.out", "w", stdout);
  scanf("%d%d",&n, &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    ++out[a];
    ++in[b];
    edge[a].push_back(b);
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) {
      q.push(i);
      cnt[i] = 1;
    }
  }
  while (q.size()) {
    int t = q.front();
    q.pop();
    for (auto i : edge[t]) {
      cnt[i] += cnt[t];
      if (--in[i] == 0) {
        if (out[i] == 0) {
          ans += cnt[i];
        } else {
          q.push(i);
        }
      }
    }
  }
  printf("%d", ans);
}
/*
10 16
1 2
1 4
1 10
2 3
2 5
4 3
4 5
4 8
6 5
7 6
7 9
8 5
9 8
10 6
10 7
10 9
*/