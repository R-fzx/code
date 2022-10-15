#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

#define ULL unsigned long long 
#define _a .first.first
#define _b .first.second
#define _c .second.first
#define _d .second.second

using namespace std;

const ULL kMaxN = LONG_LONG_MAX;

int f[201], n, m, a, b;
ULL p, q, c, d;
vector<ULL> v1, v2;
vector<pair<pair<int, int>, pair<ULL, ULL>>> line;

int GetF(int x) {
  if (f[x] != x) {
    f[x] = GetF(f[x]);
  }
  return f[x];
}

void Reset() {
  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }
}

void Find(ULL x, ULL y) {
  for (ULL i = 0; i < m; i++) {
    if (line[i]_c <= x && line[i]_d <= y) {
      if (f[GetF(line[i]_a)] != f[GetF(line[i]_b)]) {
        f[GetF(line[i]_a)] = f[GetF(line[i]_b)];
      }
    }
  }
}

short Check(ULL x, ULL y) {
  Reset();
  Find(x, y);
  for (ULL i = 1, z = 0; i <= n; i++) {
    if (f[x] == x) {
      if (z) {
        return 0;
      }
      z = 1;
    }
  }
  return 1;
}

ULL Find_l(ULL x) {
  int l = 0, r = m;
  while ((r - l) > 1) {
    int mid = l + r >> 1;
    if (Check(x, v2[mid])) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return Check(x, v2[min(l, r)]) ? v2[min(l, r)] : v2[max(l, r)];
}

ULL Find_m() {
  int a = 0, b = m - 1, c = a + b >> 1, mid;
  ULL ans_a, ans_b, ans_c, k, temp;
  temp = Find_l(v1[a]);
  ans_a = (temp == kMaxN ? kMaxN : v1[a] * p + temp * q);
  temp = Find_l(v1[b]);
  ans_b = (temp == kMaxN ? kMaxN : v1[b] * p + temp * q);
  temp = Find_l(v1[c]);
  ans_c = (temp == kMaxN ? kMaxN : v1[c] * p + temp * q);
  while (c - a > 1 || b - c > 1) {
    mid = a + c >> 1;
    k = Find_l(v1[mid]);
    if (k == kMaxN) {
      a = mid + 1;
    } else if (v1[mid] * p + k * q < ans_c) {
      ans_c = v1[mid] * p + k * q;
      c = mid;
    } else if (v1[mid] * p + k * q < ans_a) {
      ans_a = (ULL)v1[mid] * p + k * q;
      a = mid;
    }
    mid = b + c >> 1;
    k = Find_l(v1[mid]);
    if (k == kMaxN) {
      c = mid + 1;
    } else if (v1[mid] * p + k * q < ans_c) {
      ans_c = v1[mid] * p + k * q;
      c = mid;
    } else if (v1[mid] * p + k * q < ans_b) {
      ans_b = (ULL)v1[mid] * p + k * q;
      b = mid;
    }
  }
  return ans_c;
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  scanf("%d%d%lld%lld", &n, &m, &p, &q);
  for (ULL i = 0; i < m; i++) {
    scanf("%d%d%lld%lld", &a, &b, &c, &d);
    v1.push_back(c);
    v2.push_back(d);
    line.push_back({{a, b}, {c, d}});
  }
  if (m) {
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    v2.push_back(kMaxN);
    ULL temp = Find_m();
    if (temp == kMaxN) {
      printf("-1\n");
    } else {
      printf("%lld\n", temp);
    }
  }else {
    printf("%d\n", n == 0 ? 0 : -1);
  }
  return 0;
}