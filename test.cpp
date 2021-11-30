//NOIP rp++ orz lyyi2003 Bruce_W zfz sto
#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T read() {
  T r = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) r = (r << 3) + (r << 1) + (c ^ 48), c = getchar();
  return f ? -r : r;
}
const int N = 1e7 + 5, M = 1e7;
bool vv[N];
int nxt[N];
bool check(int x) {
  while (x) {
    int now = x % 10;
    if (now == 7) return 1;
    x /= 10;
  }
  return 0;
}
void init() {
  for (int i = 2; i <= M; ++i) {
    if (!vv[i]) vv[i] = check(i);
    if (vv[i])
      for (int j = i; j <= M; j += i) vv[j] = vv[i];
  }
  vector<int> t;
  for (int i = 1; i <= M + 1; ++i)
    if (!vv[i]) {
      while (t.size()) nxt[t.back()] = i, t.pop_back();
      t.push_back(i);
    }
}
void solve() {
  int x = read<int>();
  if (vv[x])
    puts("-1");
  else
    printf("%d\n", nxt[x]);
}
int main() {
  //freopen("number.in","r",stdin);
  //freopen("number.out","w",stdout);
  //clock_t s1=clock(),s2;
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  init();
  for (int T = read<int>(); T; --T) solve();
  //s2=clock();
  //cout<<"use time: "<<(s2-s1)*1.0/CLOCKS_PER_SEC<<" s"<<endl;
  return 0;
}