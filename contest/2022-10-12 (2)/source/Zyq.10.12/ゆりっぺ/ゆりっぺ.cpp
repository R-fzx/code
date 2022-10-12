#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N(2e6 + 7);
int a, b, c, n, cnt, del[N];
struct E {
  int x, y, z;
} p[N];
struct Nodea {
  int rnk;
  inline int w() { return p[rnk].x; }
  inline const bool operator<(const Nodea x)const { return p[rnk].x < p[x.rnk].x; }
};
struct Nodeb {
  int rnk;
  inline int w() { return p[rnk].y; }
  inline const bool operator<(const Nodeb x)const { return p[rnk].y < p[x.rnk].y; }
};
struct Nodec {
  int rnk;
  inline int w() { return p[rnk].z; }
  inline const bool operator<(const Nodec x)const { return p[rnk].z < p[x.rnk].z; }
};
inline bool cmp(E a, E b) {
  return a.x + a.y + a.z > b.x + b.y + b.z;
}
priority_queue<Nodea> qa;
priority_queue<Nodeb> qb;
priority_queue<Nodec> qc;
signed main() {
  freopen("ゆりっぺ.in", "r", stdin), freopen("ゆりっぺ.out", "w", stdout);
  cin >> n >> a >> b >> c;
  if (a + b + c > n) {
    cout << "I'm God Ben";
    return 0;
  }
  for (int i(0); i < n; i++) {
    cin >> p[i].x >> p[i].y >> p[i].z;
  }
  p[n] = {LONG_LONG_MIN, LONG_LONG_MIN, LONG_LONG_MIN};
  sort(p, p + n, cmp);
  cnt = a + b + c;
  for (int i(0); i < n; i++) {
//  	cout<<cnt<<'\n';
    if (!(cnt--))
      break;
    qa.push({i}), qb.push({i}), qc.push({i});
  }
  int an(0), bn(0), cn(0);
  while (an < a || bn < b || cn < c) {
    if (an == a) {
      while (!qa.empty())
        qa.pop();
    }
    if (qa.empty())
      qa.push({n});
    if (bn == b) {
      while (!qb.empty())
        qb.pop();
    }
    if (qb.empty())
      qb.push({n});
    if (cn == c) {
      while (!qc.empty())
        qc.pop();
    }
    if (qc.empty())
      qc.push({n});
    Nodea ta(qa.top());
    Nodeb tb(qb.top());
    Nodec tc(qc.top());
//    cout<<qa.size()<<' '<<qb.size()<<qc.size()<<' '<<an<<' '<<bn<<' '<<cn<<' '<<ta.w()<<' '<<tb.w()<<' '<<tc.w()<<'\n';
    if (ta.w() >= tb.w() && ta.w() >= tc.w()) {
      if (!del[ta.rnk]) {
        del[ta.rnk] = 1, an++;
      }
      qa.pop();
    } else if (tb.w() >= tc.w()) {
      if (!del[tb.rnk]) {
        del[tb.rnk] = 2, bn++;
      }
      qb.pop();
    } else {
      if (!del[tc.rnk]) {
        del[tc.rnk] = 3, cn++;
      }
      qc.pop();
    }
  }
  int sum1(0), sum2(0);
  for (int i(0); i < n; i++) {
    if (del[i] == 1) {
      sum1 += p[i].x;
    } else if (del[i] == 2) {
      sum1 += p[i].y;
    } else if (del[i] == 3) {
      sum1 += p[i].z;
    }
    if (del[i])
      sum2 += p[i].x + p[i].y + p[i].z;
  }
  cout << sum1 << '\n' << sum2;
  return 0;
}
/*
3 1 1 1 
100 0 0 
0 100 0 
0 0 100
*/
