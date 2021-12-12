#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  freopen(argv[1], "r", stdin);
  cout << "{\n  \"Code template\": {\n    \"scope\": \"cpp\",\n    \"prefix\": \"code\",\n    \"body\": [\n";
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
  cout << "    ],\n"
      "    \"description\": \"Code template\"\n"
      "  }\n"
      "}\n";
  return 0;
}