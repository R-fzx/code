# include <bits/stdc++.h>
# define ll long long
# define mod 2147483647

using namespace std;

int n , m;
int cnt;

vector<pair<int, ll> > edge[100100];

ll dis[1010], vis[1010];
ll dp[1010];

void Dij() {
  memset(dis, 0x3f, sizeof dis);
  dis[1] = 0;
  for(int i = 1 ; i <= n ; i ++) {
    int minv = 0x3f3f3f3f, minx;
    for(int j = 1 ; j <= n ; j ++) {
      if(minv > dis[j] && !vis[j]) {
        minx = j;
        minv = dis[j];
      }
    }
    vis[minx] = 1;
    for(int j = 0; j < edge[minx].size(); j++) {
      int v = edge[minx][j].first , w = edge[minx][j].second;
      dis[v] = min(dis[v],dis[minx] + w);
    }
  }
}

int main() {
  freopen("Castle.in", "r", stdin);
  freopen("Castle.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for(int i = 1, u, v, w; i <= m ; i ++) {
    scanf("%d%d%d", &u, &v, &w);
    edge[u].push_back(make_pair(v, w));
    edge[v].push_back(make_pair(u, w));
  }
  Dij();
  ll ans =  1;
  for(int i = 1; i <= n; i++) {
    for(int j = 0, v, w; j < edge[i].size(); j++) {
      v = edge[i][j].first; w = edge[i][j].second;
      if(dis[v] == dis[i] + w) {
        dp[v] = (dp[v] + 1) % mod;
      } 
    }
  }
  for(int i = 1 ; i <= n ; i ++) {
    if(dp[i]) {
      ans = (ans * dp[i]) % mod; 
    }
  }
  printf("%lld", ans);
}
