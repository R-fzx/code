#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  for (int k = 1; k <= 1000; ++k) {
    for (int n = k + 1; n <= 1000; ++n) {
      if (k <= 100 && n <= 100) continue;
      ofstream in("G.in");
      in << n << " " << k << endl;
      system("Gstd.exe"), system("G.exe");
      ifstream out("G.out"), ans("G.ans");
      int xo, xa;
      out >> xo, ans >> xa;
      if (xo != xa) {
        cout << n << " " << k;
        return 0;
      }
    }
  }
  return 0;
}