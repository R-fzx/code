#include <bits/stdc++.h>
using namespace std;
int n, x, y, z;
struct node {
  int x, y, z, id;
} a[500005],b[500005];
bool cmp(node i, node j) {
  if (i.x == j.x) {
    return (i.x + i.y + i.z) > (j.x + j.y + j.z);
  }
  return i.x > j.x;
}
bool cmp1(node i, node j) {
  if (i.y == j.y) {
    return (i.x + i.y + i.z) > (j.x + j.y + j.z);
  }
  return i.y > j.y;
}
bool cmp2(node i, node j) {
  if (i.z == j.z) {
    return (i.x + i.y + i.z) > (j.x + j.y + j.z);
  }
  return i.z > j.z;
}
int p[500005];
vector<node> v, vv, vvv;
void clearv() {
  while (v.size()>0&&p[v[v.size() - 1].id] != 0) {
    v.pop_back();
  }
  while (vv.size()>0&&p[vv[vv.size() - 1].id] != 0) {
    vv.pop_back();
  }
  while (vvv.size()>0&&p[vvv[vvv.size() - 1].id] != 0) {
    vvv.pop_back();
  }
}
int main() {
	freopen("ゆりっぺ.in","r",stdin);
	freopen("ゆりっぺ.out","w",stdout);
  ios::sync_with_stdio(false);
  cin >> n >> x >> y >> z;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y >> a[i].z;
    a[i].id = i;
    b[i]=a[i];
    v.push_back(a[i]), vv.push_back(a[i]), vvv.push_back(a[i]);
  }
  sort(v.begin(), v.end(), cmp);
  sort(vv.begin(), vv.end(), cmp1);
  sort(vvv.begin(), vvv.end(), cmp2);
  reverse(v.begin(),v.end());
  reverse(vv.begin(),vv.end());
  reverse(vvv.begin(),vvv.end());
  int sum = 0;
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= x; i++) {
    sum += a[i].x;
    p[a[i].id] = 1;
    clearv();
  }
  sort(a + 1, a + 1 + n, cmp1);
  int uni = 0;
  for (int i = 1; uni < y; i++) {
    if (p[a[i].id] == 1) {
      if (v[v.size() - 1].x - a[i].x >= vv[vv.size() - 1].y - a[i].y) {
        p[a[i].id] = 2;
        sum += a[i].y;
        sum -= a[i].x;
        sum += v[v.size() - 1].x;
        uni++;
        p[v[v.size() - 1].id] = 1;
      }
    } else {
      sum += a[i].y;
      p[a[i].id] = 2;
      uni++;
    }
    clearv();
  }
  sort(a + 1, a + 1 + n, cmp2);
  uni = 0;
  for (int i = 1; uni < z; i++) {
    if (p[a[i].id] == 1) {
      if (v[v.size() - 1].x - a[i].x >= vvv[vvv.size() - 1].z - a[i].z) {
        p[a[i].id] = 3;
        sum += a[i].z;
        sum -= a[i].x;
        sum += v[v.size() - 1].x;
        uni++;
        p[v[v.size() - 1].id] = 1;
      }
    } else if (p[a[i].id] == 2) {
      if (vv[vv.size() - 1].y - a[i].y >= vvv[vvv.size() - 1].z - a[i].z) {
        p[a[i].id] = 3;
        sum += a[i].z;
        sum -= a[i].y;
        sum += vv[vv.size() - 1].y;
        uni++;
        p[vv[vv.size() - 1].id] = 2;
      }
    } else {
      sum += a[i].z;
      p[a[i].id] = 2;
      uni++;
    }
    clearv();
  }
  cout << sum<< endl;
  int summ = 0;
  for(int i = 1;i <= n;i++){
    if(p[i]!=0){
      summ+=b[i].x+b[i].y+b[i].z;
    }
  }
  cout << summ;
  return 0;
}
