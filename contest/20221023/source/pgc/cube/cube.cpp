#include<bits/stdc++.h>
using namespace std;
const int mi = 1e7;
int n, ans, minx = mi, miny = mi, minz = mi, maxx = -mi, maxy = -mi, maxz = -mi;
struct A{
	int x1, y1, z1, x2, y2, z2;
}a[1000005];
int main(){
	freopen("cube.in", "r", stdin);
	freopen("cube.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].x1 >> a[i].y1 >> a[i].z1 >> a[i].x2 >> a[i].y2 >> a[i].z2;
		minx = min(minx, a[i].x1), maxx = max(maxx, a[i].x2);
		miny = min(miny, a[i].y1), maxy = max(maxy, a[i].y2);
		minz = min(minz, a[i].z1), maxz = max(maxz, a[i].z2);
	}
	for(int i = minx; i <= maxx; i++){
		for(int j = miny; j <= maxy; j++){
			for(int k = minz; k <= maxz; k++){
				int sum = 0;
				for(int l = 1; l <= n; l++){
					if(i >= a[l].x1 && i <= a[l].x2 && j >= a[l].y1 && j <= a[l].y2 && k >= a[l].z1 && k <= a[l].z2){
						sum++;
					}
				}
				if(sum >= n - 1){
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
