#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  freopen(argv[1], "r", stdin);
  freopen("translate.out", "w", stdout);
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