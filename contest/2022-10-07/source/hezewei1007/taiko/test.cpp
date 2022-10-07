#include <iostream>
#include <vector>

using namespace std;

bool Used[20000001];
int n, k = 1;
vector<int> v, ans;

bool Compare() {
  if (ans.size() == v.size()) {
    for (int i = 0; i < min(ans.size(), v.size()); i++) {
      if (ans[i] != v[i]) {
        return ans[i] > v[i];
      }
    }
  }
  return ans.size() < v.size();
}

bool Check(int x, int length) {
  x <<= 1;
  x %= k;
  x += v[length];
  if (length == n) {
    return 1;
  }
  if (Used[x]) {
    return 0;
  }
  Used[x] = 1;
  bool z = Check(x, length + 1);
  Used[x] = 0;
  return z;
}

bool Find(int x) {
  if (v.size() >= ans.size() && v.size() >= n) {
    if (Check(x, 0) && Compare()) {
      while (!ans.empty()) {
        ans.pop_back();
      }
      for (int i = 0; i < v.size(); i++) {
        ans.push_back(v[i]);
      }
    }
  }
  x <<= 1;
  x %= k;
  if (v.size() < n || !Used[x]) {
    if (v.size() >= n) {
      Used[x] = 1;
    }
    v.push_back(0);
    Find(x);
    v.pop_back();
    if (v.size() >= n) {
      Used[x] = 0;
    }
  }
  if (!Used[x + 1]) {
    if (v.size() >= n) {
      Used[x + 1] = 1;
    }
    v.push_back(1);
    Find(x + 1);
    v.pop_back();
    if (v.size() >= n) {
      Used[x + 1] = 0;
    }
  }
  return 0;
}

int main() {
  freopen("taiko.in", "r", stdin);
  freopen("taiko.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++) {
    k <<= 1;
  }
  Find(0);
  cout << ans.size() << ' ';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
  }
  cout << endl;

  return 0;
}