#include <bits/stdc++.h>
using namespace std;
map<string, bool> m;
map<string, int> mm;
int t[205];
int main() {
  freopen("ppfish.in","r",stdin);
  freopen("ppfish.out","w",stdout);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string a, b;
    cin >> a;
    mm[a] = i;
    for (int j = 0; j < a.size(); j++) {
      b += a[j];
      m[b] = 1;
    }
  }
  string a,aa;
  cin >> aa;
  for(int i = 0;i < aa.size();i++){
    if(aa[i]>='a'&&aa[i]<='z'){
      a+=aa[i];
    }else if(aa[i]>='A'&&aa[i]<='Z'){
      a+=aa[i]+'a'-'A';
    }
  }
  for (int i = 0; i < a.size(); i++) {
    string b;
    int s = a.size();
    for (int j = i; j <= min(s - 1, i + 19); j++) {
      b += a[j];
      if (m[b] == 0) {
        break;
      }
      if (mm[b] != 0) {
        t[mm[b]]++;
      }
    }
  }
  for(int i = 1;i<= n;i++){
    cout << 0;
  }
}