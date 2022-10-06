#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int n, k;
long long a, b, Last = 1, temp;
bool z;
priority_queue<pair<int, int>> q;

int main() {
  freopen("laser.in", "r", stdin);
  freopen("laser.out", "w", stdout);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    temp = a - 1;
    for (int i = 0; i < k && temp; i++) {
      q.push({-(temp % 10), 1});
      temp /= 10;
    }
    for (int i = 0; i < k && (a || b); i++) {
      q.push({-(a % 10), 0});
      q.push({-(b % 10), 1});
      a /= 10;
      b /= 10;
    }
  }
  while (-q.top().first <= 1) {
    q.pop();
  }
  q.push({-9, 1});
  while (!q.empty()) {
    for (; Last < -q.top().first + q.top().second; Last++) {
      cout << Last;
      z = 1;
    }
    if (z) {
      cout << endl;
      z = 0;
    }
    q.pop();
  }
  return 0;
}