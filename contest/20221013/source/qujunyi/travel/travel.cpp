#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, l, r;
} a[3005];
vector<int> v;
int fa[1005];
bool cmp(node i, node j) {
  return i.r > j.r;
}
int find(int x) {
  if (fa[x] == x) {
    return x;
  }
  return fa[x] = find(fa[x]);
}
int main() {
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].x >> a[i].y >> a[i].l >> a[i].r;
    v.push_back(a[i].l);
  }
  sort(a + 1, a + 1 + m, cmp);
  sort(v.begin(),v.end());
  int maxn = 0,mal=1,mar=0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j <= n; j++) {
      fa[j] = j;
    }
    for (int j = 1; j <= m; j++) {
      if (v[i] >= a[j].l) {
        int fx = find(a[j].x), fy = find(a[j].y);
        if (fx != fy) {
          fa[fx] = fy;
        }
        fx = find(1), fy = find(n);
        if (fx == fy) {
          int l = v[i], r = a[j].r;
          if(r-l>maxn){
            maxn = r-l;
            mal=l,mar=r;
          }
          break;
        }
      }
    }
  }
  cout << maxn+1 << endl;
  for(int i = mal;i <= mar;i++){
    cout << i << " ";
  }
}