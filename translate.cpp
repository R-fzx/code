#include <iostream>
using namespace std;
int main() {
  freopen("template.cpp", "r", stdin);
  freopen("template.out", "w", stdout);
  string s;
  while (getline(cin, s)) {
    cout << "      \"";
    for (char c : s) {
      if (c == '\\') {
        cout << "\\\\";
      } else if (c == '\"') {
        cout << "\\\"";
      } else {
        cout << c;
      }
    }
    cout << "\",\n";
  }
  return 0;
}