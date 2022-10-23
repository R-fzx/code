#include<bits/stdc++.h>
using namespace std;
long long n, q, l, r, a[100005]; 
map<pair<int, int>, int> mp;
int main(){
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	while(q--){
		cin >> l >> r;
		if(mp[{l, r}] == 1){
			cout << "No\n";
		}else if(mp[{l, r}] == 2){
			cout << "Yes\n";
		}else if(r - l <= 2){
			cout << "No\n";
		}else{
			bool flag = 0;
			for(int i = l; i <= r - 2; i++){
				for(int j = i + 1; j <= r - 1; j++){
					for(int k = j + 1; k <= r; k++){
						if(a[i] + a[j] > a[k] && a[i] + a[k] > a[j] && 
						a[j] + a[k] > a[i]){
							flag = 1;
							continue;
						}
					}
				}
			}
			if(!flag){
				cout << "No\n";
				mp[{l, r}] = 1;
			}else{
				cout << "Yes\n";
				mp[{l, r}] = 2;
			}
		}
	}
	return 0;
}
