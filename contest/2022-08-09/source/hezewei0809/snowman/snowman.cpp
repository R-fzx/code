#include <cmath>
#include <iostream>

using namespace std;

int n;
long long x, Last, num[500001];
long long ans[500001], Ans, temp;

void P() {
  int j = 0;
  for (int i = 1; i < n - 1; i++) {
    while (num[j + 1] != num[i + 1] && j > 0) {
      j = ans[j];
    }
    ans[i] = j;
    if (num[i + 1] == num[j + 1]) {
      j++;
    }
  }
}

int main() {
  freopen("snowman.in", "r", stdin);
  freopen("snowman.out", "w", stdout);
  cin >> n >> Last;
  for (int i = 1; i < n; i++) {
    cin >> x;
    num[i] = x - Last;
    Last = x;
  }
  P();
  for (long long i = 1, l = 0; i < n - 1; i++, temp += num[i], l = 0) {
    while (i + l < n - 1 && ans[i] == ans[i + l] - l * (ans[i + 1] - ans[i]) && (num[i + l] == num[ans[i + l]])) {
      l++;
    }
    if (l != 0) {
      Ans = max(Ans, min(abs(temp) + 1, l + 1));
    }
  }
  cout << Ans;
  return 0;
}