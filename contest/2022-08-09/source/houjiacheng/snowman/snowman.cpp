# include <bits/stdc++.h>
# define mod 998244353ll
# define nex 300000007ll
# define int long long

using namespace std;

int n;
int in[100100];
int c[100100];
map <int, int>mpl;
map <int, int>mpr;

int mi(int x, int y) {
  int re = 1;
  while (y) {
    if (y & 1) {
      re = re * x % mod;
    }
    x = x * x % mod;
    y >>= 1;
  }
  return re;
}

int Mod (int x) {
  return x >= mod ? x - mod : x;
}

bool ck(int len) {
  int mg = mi(nex, len - 1);
  mpl.clear();
  mpr.clear();
  int now = 0;
  for (int i = 1; i <= len; i++) {
    now = (now * nex + c[i]) % mod;
  }
  mpl[now] = 1;
  mpr[now] = 1;
  for (int i = 2; i <= n - len + 1; i++) {
    now = (Mod(mod + now - mg * c[i - 1] % mod) * nex + c[i + len - 1]) % mod;
    if (mpl.find(now) == mpl.end()) {
      mpl[now] = i;
      mpr[now] = i;
    } else {
      mpl[now] = min(mpl[now], i);
      mpr[now] = max(mpr[now], i);
    }
  }
  vector<int> l;
  vector<int> r;
  for (auto i : mpl) {
    l.push_back(i.second);
    // printf("%d %d  ", i.first, i.second);
  }
  // printf("\n");
  for (auto i : mpr) {
    r.push_back(i.second);
    // printf("%d %d  ", i.first, i.second);
  }
  for (int i = 0; i < l.size(); i++) {
    if (r[i] - l[i] > len) {
      return 1;
    }
  }
  return 0;
}

signed main() {
  freopen("snowman.in", "r", stdin);
  freopen("snowman.out", "w", stdout);
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", in + i);
  }
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  --n;
  int mic = 0;
  for (int i = 1; i <= n; i++) {
    c[i] = in[i + 1] - in[i];
    mic = min(mic, c[i]);
  }
  for (int i = 1; i <= n; i++) {
    c[i] = c[i] - mic;
  }
  // for (int i = 1; i <= n; i++) {
  //   printf("\n%lld\n", ck(i));
  // }
  // for (int i = 1; i <= n; i++) {
  //   printf("%lld ", c[i]);
  // }
  int l = 0, r = n / 2;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (ck(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  printf("%lld", l + 1);
}

/*

10
1 2 3 4 5 6 7 8 9 10

*/