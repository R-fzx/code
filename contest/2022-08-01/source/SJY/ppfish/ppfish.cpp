#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

const int N = 2e2 + 5; 
const int M = 1e6 + 5;

struct NODE {
  int c;
  int id;
  double p;
} c[N];

map<string, int> f;
int n, k;
double p;
string a[N], b;

bool cmp(NODE a, NODE b) { 
  return a.c < b.c; 
}

bool cmp2(NODE a, NODE b) {
  return a.id < b.id;
}

int main() {
  freopen("ppfish.in", "r", stdin);
  freopen("ppfish.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  cin >> b >> p >> k;
  int m = b.size();
  for (int i = 0; i < m; ++i) {
    for (int j = 1; i + j <= m && j <= 20; ++j) {
      string c = b.substr(i, j);
      f[c]++;
    } 
  } 
  
  for (int i = 1; i <= n; ++i) {
    c[i].c = f[a[i]];
    c[i].id = i;
    c[i].p = 1;
  } 
  
  sort(c + 1, c + n + 1, cmp);
  
  for (int x = 1; x <= k; ++x) {
    for (int i = n; i >= 1; --i) {
      int flag = 0, j;
      for (j = i - 1; j >= 1; --j) {
        if (c[j].c < c[i].c) {
          flag = 1;
          break;
        } 
      }
      
      if (flag == 0) {
        c[i].p *= p;
      } else {
        c[i].p = c[j].p + (c[i].p - c[j].p) * p;;
      }
    }
  }
  
  sort(c + 1, c + n + 1, cmp2);
  
  for (int i = 1; i <= n; ++i) {
    printf("%.3lf ", c[i].p);
  }

}
