#pragma GCC optimize ("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using Pii = pair <int, int>;

const int kMaxL = 3e4 + 1;

vector <Pii> p;
vector <int> li;
int ne[kMaxL], l1, l2;
long long ans;
string s1, s2;

void CalcNext() {
  for (int i = 1, l; i < l2; i++) {
    for (l = ne[i]; l && s2[l] != s2[i]; l = ne[l]) {
    }
    ne[i + 1] = l + (s2[l] == s2[i]);
  }
}

void FindAns() {
  p.push_back ({0, 0});
  p.push_back ({l1 + 1, l1 + 1});
  for (int i = -1, j = -1; i < l1 - l2;) {
    for (; j - i < l2 && s1[j + 1] == s2[j - i]; j++) {
    }
    if (j - i == l2) {
      p.push_back ({i + 2, i + 6});
    }
    i = i == j ? ++j : j - ne[j - i];
  }
}

int main() {
  freopen ("agnus.in", "r", stdin);
  freopen ("agnus.out", "w", stdout);
  cin >> s1; s2 = "agnus";
  l1 = s1.size (), l2 = s2.size ();
  CalcNext ();
  FindAns ();
  sort (p.begin (), p.end ());
  for (int i = 1; i < p.size (); i++) {
    li.push_back (p[i].first - p[i - 1].second);
  }
  for (int i = 0; i < li.size (); i++) {
    for (int j = i + 1; j < li.size (); j++) {
      ans += li[i] * li[j];
    }
  }
  cout << ans;
  return 0;
}
