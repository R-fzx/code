#include <bits/stdc++.h>

using namespace std;

struct node{
  int to, next, left, right;
}v[6010];
int n, m, tot, tail, head, ansl, ansr;
int q[6010], h[6010];
bool f[6010];
int ri[3010];

void add(int f,int t,int l, int r) {
  v[++tot].to = t, v[tot].next = h[f], v[tot].left = l, v[tot].right = r, h[f] = tot;
}

void find(int l) {
  memset(ri, 0, sizeof(ri));
  ri[1] = (1 << 20); 
  while (head <= tail) {
    int root = q[head];
    f[q[head]] = 0;
    head++;
    for (int jump = h[root]; jump; jump = v[jump].next) {
      if ((v[jump].left <= l) && (v[jump].right >= l) && (ri[v[jump].to] < min(v[jump].right, ri[root]))) {
        ri[v[jump].to] = min(v[jump].right, ri[root]);
        if (!f[v[jump].to]) {
            q[++tail] = v[jump].to;
            f[v[jump].to] = 1;
        }
      }
    }   
  }
  if ((ri[n] - l > ansr - ansl) || (ri[n] - l == ansr - ansl && l < ansl)) {
    ansr = ri[n];
    ansl = l;
  }
}

int main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, l, r;
    cin >> a >> b >> l >> r;
    add(a, b, l, r);
    add(b, a, l , r);
  }
  ansr = -1; 
  for (int i = 1; i <= tot; i += 2) {
    head = 1, tail = 1;
    q[tail] = 1;
    f[1] = 1;
    find(v[i].left);
  }
  if (ansr==-1) {
    cout << 0;
    return 0;
  }
  cout << ansr - ansl + 1 << endl;
  for (int i = ansl; i < ansr; i++) {
    cout << i << ' ';
  }
  cout << ansr;
  return 0;
}
