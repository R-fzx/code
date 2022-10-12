#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif
#define int long long

using namespace std;


int n, A, B, C;

namespace S1 {
const int kMaxN = 101;

int a[kMaxN], b[kMaxN], c[kMaxN];
pair<int, int> f[kMaxN][kMaxN][kMaxN];

pair<int, int> add(pair<int, int> p1, pair<int, int> p2) {
  return make_pair(p1.first + p2.first, p1.second + p2.second);
}

int Main() {
  for (int i = 1; i <= n; ++i) {
    scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
  }
  for (int i = 0; i <= A; ++i) {
    for (int j = 0; j <= B; ++j) {
      for (int k = 0; k <= C; ++k) {
        f[i][j][k] = make_pair(-1e18, -1e18);
      }
    }
  }
  f[0][0][0] = make_pair(0, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = min(i, A); ~j; --j) {
      for (int k = min(i, B); ~k; --k) {
        for (int s = min(i, C); ~s; --s) {
          if (j) f[j][k][s] = max(f[j][k][s], add(f[j - 1][k][s], make_pair(a[i], a[i] + b[i] + c[i])));
          if (k) f[j][k][s] = max(f[j][k][s], add(f[j][k - 1][s], make_pair(b[i], a[i] + b[i] + c[i])));
          if (s) f[j][k][s] = max(f[j][k][s], add(f[j][k][s - 1], make_pair(c[i], a[i] + b[i] + c[i])));
        }
      }
    }
  }
  cout << f[A][B][C].first << endl << f[A][B][C].second << endl;  
}
} // namespace S1

namespace S2 {

const int kMaxN = 5e5 + 5;

struct Node {
  int a, b, c;
} d1[kMaxN], d2[kMaxN], d3[kMaxN], d4[kMaxN], d5[kMaxN], d6[kMaxN];

struct NN {
  int a, b, c;
} dd[kMaxN];

int a[kMaxN], b[kMaxN], c[kMaxN];

bool cmp1(Node n1, Node n2) {
  if (max(n1.a, max(n1.b, n1.c)) != max(n2.a, max(n2.b, n2.c))) return max(n1.a, max(n1.b, n1.c)) > max(n2.a, max(n2.b, n2.c));
  return n1.a + n1.b + n1.c > n2.a + n2.b + n2.c;
}

bool cmp2(Node n1, Node n2) {
  if (max(n1.a, n1.b) != max(n2.a, n2.b)) return max(n1.a, n1.b) > max(n2.a, n2.b);
  return n1.a + n1.b > n2.a + n2.b;
}

bool cmp3(Node n1, Node n2) {
  return n1.a > n2.a;
}

bool cmp4(Node n1, Node n2) {
  if (n1.a != n2.a) return n1.a > n2.a;
  return n1.a + n1.b + n1.c > n2.a + n2.b + n2.c;
}
bool cmp5(Node n1, Node n2) {
  if (n1.b != n2.b) return n1.b > n2.b;
  return n1.a + n1.b + n1.c > n2.a + n2.b + n2.c;
}
bool cmp6(Node n1, Node n2) {
  if (n1.c != n2.c) return n1.c > n2.c;
  return n1.a + n1.b + n1.c > n2.a + n2.b + n2.c;
}

// pair<int, int> g(int A, int B, int C, Node d[kMaxN]) {
//   sort(d + 1, d + 1 + n, cmp1);
//   int sum1 = 0, sum2 = 0, nw;
//   for (int i = 1; i <= n; ++i) {
//     if (!A || !B || !C) {
//       nw = i; break ;
//     }
//     int mx = max(d[i].a, max(d[i].b, d[i].c));
//     if (d[i].a == mx) {
//       --A, sum1 += d[i].a, sum2 += d[i].a + d[i].b + d[i].c;
//     } else if (d[i].b == mx) {
//       --B, sum1 += d[i].b, sum2 += d[i].a + d[i].b + d[i].c;
//     } else {
//       --C, sum1 += d[i].c, sum2 += d[i].a + d[i].b + d[i].c;
//     }
//   }
//   if (!A) {
//     swap(A, C);
//     for (int i = 1; i <= n; ++i) {
//       swap(d[i].a, d[i].c);
//     }
//   } else if (!B) {
//     swap(B, C);
//     for (int i = 1; i <= n; ++i) {
//       swap(d[i].b, d[i].c);
//     }
//   }
//   sort(d + nw, d + 1 + n, cmp2);
//   for (int i = nw; i <= n; ++i) {
//     if (!A || !B) {
//       nw = i; break ;
//     }
//     int mx = max(d[i].a, d[i].b);
//     if (d[i].a == mx) {
//       --A, sum1 += d[i].a, sum2 += d[i].a + d[i].b + d[i].c;
//     } else {
//       --B, sum1 += d[i].b, sum2 += d[i].a + d[i].b + d[i].c;
//     }
//   }
//   if (!A) {
//     swap(A, B);
//     for (int i = 1; i <= n; ++i) {
//       swap(d[i].a, d[i].b);
//     }
//   }
//   sort(d + nw, d + 1 + n, cmp3);
//   for (int i = nw; i <= n; ++i) {
//     if (!A) {
//       nw = i; break ;
//     }
//     --A, sum1 += d[i].a , sum2 += d[i].a + d[i].b + d[i].c;
//   }
//   return make_pair(sum1, sum2);
// }

pair<int, int> f(int A, int B, int C, Node d[kMaxN]) {
  sort(d + 1, d + 1 + n, cmp4);
  int sum1 = 0, sum2 = 0;
  for (int i = 1; i <= A; ++i) {
    sum1 += d[i].a, sum2 += d[i].a + d[i].b + d[i].c;
  }
  sort(d + 1 + A, d + 1 + n, cmp5);
  for (int i = A + 1; i <= A + B; ++i) {
    sum1 += d[i].b, sum2 += d[i].a + d[i].b + d[i].c;
  }
  sort(d + 1 + A + B, d + 1 + n, cmp6);
  for (int i = A + B + 1; i <= A + B + C; ++i) {
    sum1 += d[i].c, sum2 += d[i].a + d[i].b + d[i].c;
  }
  // debug(sum1, sum2);
  return make_pair(sum1, sum2);
}

int Main() {
  for (int i = 1; i <= n; ++i) {
    scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
    d1[i].a = a[i], d1[i].b = b[i], d1[i].c = c[i];
    d2[i].a = a[i], d2[i].b = c[i], d2[i].c = b[i];
    d3[i].a = b[i], d3[i].b = a[i], d3[i].c = c[i];
    d4[i].a = b[i], d4[i].b = c[i], d4[i].c = a[i];
    d5[i].a = c[i], d5[i].b = a[i], d5[i].c = b[i];
    d6[i].a = c[i], d6[i].b = b[i], d6[i].c = a[i];
  }
  auto f1 = f(A, B, C, d1), f2 = f(A, C, B, d2), f3 = f(B, A, C, d3);
  auto f4 = f(B, C, A, d4), f5 = f(C, A, B, d5), f6 = f(C, B, A, d6);
  auto ans = max(f1, max(f2, max(f3, max(f4, max(f5, f6)))));
  cout << ans.first << endl << ans.second << endl;
  return 0;
}

} // namespace S2

signed main() {
  freopen("yxy.in", "r", stdin);
  freopen("yxy.out", "w", stdout);
  scanf("%lld%lld%lld%lld", &n, &A, &B, &C);
  if (A + B + C > n) {
    puts("woshishenben");
    return 0;
  }
  if (n <= 100) S1::Main();
  else S2::Main();
  return 0;
}