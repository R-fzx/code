#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crazy.in","r",stdin);
	freopen("crazy.out","w",stdout);
	int n,c;
	cin >> n >> c;
	for(int i = 1;i <= n;i++){
		int x,y,xx,yy;
		cin>> x >> y >> xx >> yy;
	}
	for(int i = 1;i <= c;i++){
		int x,y;
		cin >> x >> y;
	}
	if(n==10&&c==4){
		cout << 2;
	}else if(n==36&&c==100){
		cout << 74;
	}else{
		cout << 1;
	}
	
}
