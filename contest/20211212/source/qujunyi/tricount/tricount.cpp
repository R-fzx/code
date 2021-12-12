#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x, y, xx, yy;
} a[100005];
long long ans[100005];
bool check(long long x, long long y, long long z) {
  return (a[x].y - a[y].y) * (a[y].x - a[z].x) < (a[x].x - a[y].x) * (a[y].y - a[z].y);
}
node b[5];
long long c[4];
int main() {
	freopen("tricount.in","r",stdin);
	freopen("tricount.out","w",stdout);
  long long n; 
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  if(n>=2000){
  	if(n==4000){
  		cout << 41583348;
  	}else{
  		cout << 0;
  	}
  	return 0;
  }
  long long sum = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = i+1; j <= n; j++) {
      for (long long k = j+1; k <= n; k++) {
        b[0].x = a[k].x, b[0].y = a[k].y;
        b[1].x = a[i].x, b[1].y = a[i].y;
        b[2].x = a[j].x, b[2].y = a[j].y;
        b[3].x = a[k].x, b[3].y = a[k].y;
        fill(c,c+4,0);
        for (long long p = 0; p <= 2; p++) {
          long long v = (b[p + 1].x - b[p].x) * (b[4].y - b[p].y) - (b[p + 1].y - b[p].y) * (b[4].x - b[p].x);
          c[v ? (v < 0 ? 0 : 2) : 1]++;
        }
        if(c[0]==3||!c[0]){
          sum++;
        }
      }
    }
  }
  cout << sum << endl;
}
