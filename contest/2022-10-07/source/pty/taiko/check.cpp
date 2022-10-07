#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>

using namespace std;

ifstream fin("taiko.in");
ifstream fout("taiko.out");

set<string> s;
int k, n;
string str;

int main() {
  fin >> k;
  fout >> str, n = str.length();
  str += str;
  for (int i = 0; i < n; i++) {
    string shit = str.substr(i, k);
    if (s.count(shit)) {
      cout << "shit";
    }
    s.insert(shit);
  }
  return 0;
}
