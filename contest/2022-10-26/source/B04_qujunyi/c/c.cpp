#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main() {
  //freopen("c.in", "r", stdin);
  //freopen("c.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  long long n;
  cin >> n;
  long long maxn = 0;
  for(int i = 1;i <= n;i++){
  	maxn=max(maxn,a[i]);
  }
  long long mini = 1e18;
  for(int i = max(maxn-500,(long long)1);i <= maxn+500;i++){
  	long long sum = 0;
  	for(long long j = 1;j <= n;j++){
  		if(i>a[j]){
  			long long p = i-a[j];
  			while(p>0){
  				if(p%2==1){
  					sum++;
				  }
				  p/=2;
			  }
		  }else{
  			long long p = a[j]-i;
  			while(p>0){
  				if(p%2==1){
  					sum++;
				  }
				  p/=2;
			  }
		  }
	  }
  mini=min(mini,sum);
}
cout << mini;
}
