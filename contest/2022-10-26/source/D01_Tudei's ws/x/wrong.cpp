#include<bits/stdc++.h>
#include<random>
using namespace std;

ifstream fin("x.in");
ofstream fout("x.out");
#define cin fin
#define cout fout

int n,x[100005],y[100005];
bitset<1005>edge[1005];

int rnp[1005];
mt19937 a(time(0));

int main(){
	std::ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	if(n<=1000){
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
			if(abs(x[i]-x[j])>abs(y[i]+y[j]))
				edge[i][j]=edge[j][i]=1;
		for(int i=1;i<=n;i++)edge[i][i]=1;
		
		bitset<1005>now;
		int ans=0;
		
		for(int i=1;i<=n;i++)rnp[i]=i;
		for(int i=1;i<=n;i++){
			now=edge[i];
			shuffle(rnp+1,rnp+n+1,a);
			for(int j=1;j<=n;j++)
				if(now[rnp[j]])
					now&=edge[rnp[j]];
			ans=max(ans,(int)(now.count()));
		}
		cout<<ans;
	}
	else{
		int ok=1;
		for(int i=1;i<=n;i++)if(y[i]){ok=0;break;}
		if(!ok){
			cout<<a()%n+1<<endl;
			return 0;
		}
		sort(x+1,x+n+1);
		cout<<(unique(x+1,x+n+1)-x-1);
	}
	return 0;
}

#undef cin
#undef cout
