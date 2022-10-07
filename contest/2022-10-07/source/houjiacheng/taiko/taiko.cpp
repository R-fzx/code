# include <stdio.h>

using namespace std;

bool vis[3000];

int n, m;

int main() {
  freopen("taiko.in", "r", stdin);
  freopen("taiko.out", "w", stdout);
  scanf("%d", &n);
  m = (1 << n);
  printf("%d\n", m);
  for (int i = m - 1; i; i = (i << 1) ^ (1 << n)) {
    vis[i] = 1;
  }
  for (int i = 1; i < n; i++) {
    printf("0");
  }
  int i = 0;
  while (i != m - 1) {
    if (vis[(i + i) & (m - 1)] == 0) {
      printf("0");
      vis[(i + i) & (m - 1)] = 1;
      i = (i + i) & (m - 1);
    } else {
      vis[(i + i + 1) & (m - 1)] = 1;
      printf("1");
      i = (i + i + 1) & (m - 1);
    }
  }
  printf("\n");
}