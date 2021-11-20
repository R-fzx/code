#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  freopen(argv[1], "r", stdin);
  cout << "{\n  \"Polygon template\": {\n    \"scope\": \"cpp\",\n    \"prefix\": \"polygon\",\n    \"body\": [\n";
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
      "    \"description\": \"Polygon template\"\n"
      "  }\n"
      "}\n";
  return 0;
}