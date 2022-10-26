#include <bits/stdc++.h>
using namespace std;
vector<int> v[200005];
int h[200005];
vector<int> vv;
struct node {
  int x, y;
} a[200005] ;
struct Node {
  long long l, r;
  long long sum, maxi, add;
} b[800005];
void Pushup(Node &u, Node &l, Node &r) {
  u.l = l.l, u.r = r.r;
  u.maxi = min(l.maxi, r.maxi);
}
void build(long long u, long long l, long long r) {
  if (l == r) {
    b[u] = {l, r, h[r], h[r], 0};
  } else {
    long long mid = (l + r) >> 1;
    build(u * 2, l, mid), build(u * 2 + 1, mid + 1, r);
    Pushup(b[u],b[u*2],b[u*2+1]);
  }
}
long long query(long long x, long long l, long long r) {
  if (l <= b[x].l && b[x].r <= r) {
    return b[x].maxi;
  } else {
    long long mid = (b[x].l + b[x].r) >> 1;
    long long maxi = 1e9;
    if (l <= mid) {
      maxi = min(maxi, query(x * 2, l, r));
    }
    if (r > mid) {
      maxi = min(maxi, query(x * 2 + 1, l, r));
    }
    return maxi;
  }
}
int main() {
  freopen("h.in", "r", stdin);
  freopen("h.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  build(1, 1, n);
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    a[i].x = x, a[i].y = y;
    if (v[y].size() == 0) {
      vv.push_back(y);
    }
    v[y].push_back(x);
  }
  for (int i = 0; i < vv.size(); i++) {
    sort(v[vv[i]].begin(), v[vv[i]].end());
  }
  int sum = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < vv.size(); j++) {
      int x = vv[j];
      bool s = 0;
      int l = 0, r = v[x].size() - 1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (v[x][mid] <= a[i].x) {
          l = mid + 1;
          s=1;
        } else {
          r = mid - 1;
        }
      }
      s=0;
      int u = l - 1, uu;
      l = 0, r = v[x].size() - 1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (v[x][mid] >= a[i].x) {
          r = mid - 1;
          s=1;
        } else {
          l = mid + 1;
        }
      }
      uu = r + 1;
      if(s==0){
      	uu = v[x].size()-1;
	  }
      if(u<0){
      	u = 0;
	  }
      l = 0, r = u;
      while (l <= r) {
        int mid = (l + r) / 2; 
        if (abs(a[i].y - query(1,min(v[x][mid],a[i].x), max(v[x][mid],a[i].x))) + abs(x - query(1,min(v[x][mid],a[i].x), max(v[x][mid],a[i].x))) + abs(v[x][mid] - a[i].x) <= k) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      int p = r + 1, pp;
      l = uu, r = v[x].size()-1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (abs(a[i].y - query(1,min(v[x][mid],a[i].x), max(v[x][mid],a[i].x))) + abs(x - query(1,min(v[x][mid],a[i].x), max(v[x][mid],a[i].x))) + abs(v[x][mid] - a[i].x) <= k) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      pp=l-1;
      if(pp-p+1>=0){
      	
      sum+=(pp-p+1);
	  }
      if(a[i].y==x){
        sum--;
      }
    }
  }
  cout << sum/2;
}
