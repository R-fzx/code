#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;
using ll = long long;

int t;
ll a, b, k;

int main() {
  ifstream cin("taiko.in");
  ofstream cout("taiko.out");

  for (cin >> t; t--;) {
    cin >> a >> b >> k;
    cout << "0 0\n";
  }
  return 0;
}