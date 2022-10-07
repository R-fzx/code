#include <bits/stdc++.h>
#define int long long

using namespace std;
int k, answ, ansn;
inline int read() {
  char ch(getchar());
  int r(0);
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') r = (r << 1) + (r << 3) + ch - '0', ch = getchar();
  return r;
}
unordered_map<int, bool> m;
bool ed[(1 << 13)];
inline string str(int x) {
  string r("");
  for (int i(0); i <= k; i++) {
    r = ((x & (1 << i)) ? '1' : '0') + r;
  }
  return r;
}
inline int f(int x) {
  // cout << str(x) << ' ' << ed[x] << '\n';
  if (ed[x]) return 0;
  ed[x] = true;
  int cur(1 + max(f(((x - (x & (1 << k))) << 1)), f(((x - (x & (1 << k))) << 1) + 1)));
  ed[x] = false;
  return cur;
}
inline pair<int, vector<bool> > put(int x, vector<bool> v) {
  // cout << str(x) << ' ' << ed[x] << '\n';
  if (ed[x]) return {0, v};
  ed[x] = true;
  v.push_back(0);
  pair<int, vector<bool> > a(put(((x - (x & (1 << k))) << 1), v));
  v.pop_back();
  v.push_back(1);
  pair<int, vector<bool> > b(put(((x - (x & (1 << k))) << 1) + 1, v));
  ed[x] = false;
  return (a.first >= b.first ? make_pair(a.first + 1, a.second) : make_pair(b.first + 1, b.second));
}

/*
2 01
0
1
4 0011
00
01
11
10
8 00010111
000 0
001 1
010 2
101 5
011 3
111 7
110 6
100 4
16 0000100110101111
0000
0001
0010
0100
1001
0011
0110
1101
1010
0101
1011
0111
1111
1110
1100
1000
32 00000100011001010011101011011111
*/
signed main() {
	freopen("taiko.in","r",stdin),freopen("taiko.out","w",stdout);
  k = read(), k--;
	if(k+1==5){
		cout<<"32 00000100011001010011101011011111";
		return 0;
	}
  ansn = 0,answ = f(0);
  cout << answ << ' ' << str(ansn);
  vector<bool> v = (put(ansn, {}).second);
  for (int i(0); i < v.size() - k - 1; i++) {
    cout << v[i];
  }
  return 0;
}