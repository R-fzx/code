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
ULL p, q, c, d, Max_m, Max_l;
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
    if (line[i] _c <= x && line[i] _d <= y) {
      if (f[GetF(line[i] _a)] != f[GetF(line[i] _b)]) {
        f[GetF(line[i] _a)] = f[GetF(line[i] _b)];
      }
    }
  }
}

short Check(ULL x, ULL y) {
  Reset();
  Find(x, y);
  ULL z = 0;
  for (ULL i = 1; i <= n; i++) {
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
  ans_a = temp > Max_l ? 1000000001 : v1[a] * p + temp * q;
  temp = Find_l(v1[b]);
  ans_b = temp > Max_l ? 1000000001 : v1[b] * p + temp * q;
  temp = Find_l(v1[c]);
  ans_c = temp > Max_l ? 1000000001 : v1[c] * p + temp * q;
  while (c - a > 1 || b - c > 1) {
    mid = a + c >> 1;
    k = Find_l(v1[mid]);
    if (k == 1000000001) {
      a = mid + 1;
    } else if (v1[mid] * p + k * q < ans_c) {
      ans_a = ans_c;
      ans_c = v1[mid] * p + k * q;
      a = c;
      c = mid;
    } else if (v1[mid] * p + k * q < ans_a) {
      ans_a = min(ans_a, (ULL)v1[mid] * p + k * q);
      a = mid;
    }
    mid = b + c >> 1;
    k = Find_l(v1[mid]);
    if (k == 1000000001) {
      a = mid + 1;
    } else if (v1[mid] * p + k * q < ans_c) {
      ans_b = ans_c;
      ans_c = v1[mid] * p + k * q;
      b = c;
      c = mid;
    } else if (v1[mid] * p + k * q < ans_b) {
      ans_b = min(ans_b, (ULL)v1[mid] * p + k * q);
      b = mid;
    }
  }
  return ans_c;
}

int main() {
  cout << kMaxN;
  return 0;
}