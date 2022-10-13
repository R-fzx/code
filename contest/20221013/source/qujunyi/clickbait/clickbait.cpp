#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
struct node {
  int xl, xr, yl, yr;
  int x;
};
vector<node> v;
bool cmp(node i, node j) {
  return i.x < j.x;
}
struct Node {
  int x, y;
};
int n, m;
vector<int> vv[1000005];
bool b[1005][1005];
int col[1005][1005];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ui;
int sum[1000005];
void Dfs(int x, int y) {
  if (col[x][y] != 0) {
    ui = col[x][y];
    return;
  }
  b[x][y] = 1;
  Node p;
  p.x = x, p.y = y;
  if (a[x][y] == '-') {
    if (b[x][y + 1] == 0) {
      Dfs(x, y + 1);
    } else {
      Dfs(x, y - 1);
    }
  } else if (a[x][y] == '|') {
    Dfs(x + 1, y);
  } else if (a[x][y] == '+') {
    for (int i = 0; i < 4; i++) {
      int fx = x + dx[i], fy = y + dy[i];
      if (fx >= 1 && fx <= n && fy >= 1 && fy <= m && a[fx][fy] != '.' && b[fx][fy] == 0) {
        Dfs(fx, fy);
      }
    }
  }
}
void dfs(int x) {
  x--;
    //cout << x+1 << endl;
  int l = v[x].yl - 1, r = v[x].yr + 1;
  for (int i = v[x].xl; i <= v[x].xr; i++) {
    for (int j = v[x].yl; j <= v[x].yr; j++) {
      b[i][j] = 1;
    }
  }
  for (int i = v[x].xr; i >= v[x].xl; i--) {
  int yt = -1, ty = -1;
    if (a[i][l] != '.' && l >= 1) {
      Dfs(i, l);
      yt = ui;
      dfs(yt);
    }
    if (a[i][r] != '.' && r <= m) {
      Dfs(i, r);
      ty = ui;
      dfs(ty);
    }
    //cout <<x<<"LL"<< endl;;
    if (yt!=-1&&ty == -1) {
      //cout << yt <<"L"<< endl;
      vv[x + 1].push_back(yt);
    } else if (ty!=-1&&yt == -1) {
      //cout << ty <<"L"<< endl;
      vv[x + 1].push_back(ty);
    } else if (ty!=-1&&yt != -1){
      //cout << ty << "L"<<endl;
      //cout << yt <<"L"<< endl;
      if (sum[ty] > sum[yt]) {
        vv[x + 1].push_back(yt);
        vv[x + 1].push_back(ty);
      }else{
        vv[x + 1].push_back(ty);
        vv[x + 1].push_back(yt);
      }
    }
  }
  for (int i = 0; i < vv[x + 1].size(); i++) {
    sum[x + 1] += sum[vv[x + 1][i]];
  }
}
void DFs(int x){
  for(int i = 0;i < vv[x].size();i++){
    DFs(vv[x][i]);
  }
  cout << x<< endl;
}
int main() {
  freopen("clickbait.in","r",stdin);
  freopen("clickbait.out","w",stdout);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int s = 0;
      int l = j, r;
      while (j <= m && a[i][j] >= '0' && a[i][j] <= '9') {
        s *= 10;
        s += (a[i][j] - '0');
        j++;
      }
      if (s == 0) {
        continue;
      }
      r = j - 1;
      int xl, xr, yl, yr;
      for (int k = i - 1; k >= 1; k--) {
        if (a[k][j] != '.') {
          xl = k;
          break;
        }
      }
      for (int k = i + 1; k <= n; k++) {
        if (a[k][j] != '.') {
          xr = k;
          break;
        }
      }
      for (int k = l - 1; k >= 1; k--) {
        if (a[i][k] != '.') {
          yl = k;
          break;
        }
      }
      for (int k = r + 1; k <= m; k++) {
        if (a[i][k] != '.') {
          yr = k;
          break;
        }
      }
      for (int i = xl; i <= xr; i++) {
        for (int j = yl; j <= yr; j++) {
          col[i][j] = s;
        }
      }
      node u;
      u.xl = xl;
      u.xr = xr;
      u.yl = yl;
      u.yr = yr;
      u.x = s;
      sum[s] = (xr - xl + 1) * (yr - yl + 1);
      v.push_back(u);
    }
  }
  sort(v.begin(), v.end(), cmp);
  dfs(1);
  //for (int i = 0; i < v.size(); i++) {
  //  for (int j = 0; j < vv[i + 1].size(); j++) {
  //    cout << vv[i + 1][j] << " ";
  //  }
  //  cout << endl;
  //}
  DFs(1);
}