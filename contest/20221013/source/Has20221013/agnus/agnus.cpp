#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string s;
int x, ans;

int main() {
  freopen("agnus.in", "r", stdin);
  freopen("agnus.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> s;
  while ((x = s.find("agnus")) < s.size()) {
    ans += (x + 1) * (s.size() - (x + 4));
    s.erase(x, 5);
  }
  cout << ans;
  return 0;
}