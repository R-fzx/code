#include<bits/stdc++.h>

using namespace std;
int n,k,a,b[9];
double l[9],p[9][9],ans;
unordered_map<int,double>v[9][9];
inline double work(){
	p[0][0]=1;
	for(int i(1);i<=n;i++){
		v[i][0].clear();
		p[i][0]=p[i-1][0]*(1-l[i]);
		for(int j(1);j<=i;j++){
			v[i][j].clear();
			p[i][j]=p[i-1][j]*(1-l[i])+p[i-1][j-1]*l[i];
		}
	}
	v[0][0][0]=1;
	for(int i(0);i<n;i++){
		for(int j(0);j<=i;j++){
			for(auto p(v[i][j].begin());p!=v[i][j].end();p++){
				v[i+1][j][p->first+b[i+1]]+=p->second*(1-l[i+1]);
				v[i+1][j+1][p->first]+=p->second*l[i+1];	
			}
		}
	}
	int m((n>>1)+1);
	double p1(0),p2(0);
	for(int i(m);i<=n;i++){
		//cout<<i<<','<<p[n][i]<<'\n';
		p1+=p[n][i];
	}
	for(int i(0);i<m;i++){
		for(auto p(v[n][i].begin());p!=v[n][i].end();p++){
			//cout<<p->first<<' '<<p->second<<'\n';
			p2+=a/(double)(a+p->first)*p->second;
		}
	}
	return p1+(1-p1)*p2;
} 
inline void f(int x,int k){
	if(x==n+1||k==0){
		if(k==0)ans=max(ans,work());//,puts("");
		return;
	}
	f(x+1,k);
	double cur(l[x]);
	for(int i(1);l[x]<1.0&&i<=k;i++)l[x]=min(1.0,l[x]+0.1),f(x+1,k-i);
	l[x]=cur;
}
int main(){
	freopen("assembly.in","r",stdin),freopen("assembly.out","w",stdout);	
	cin>>n>>k>>a;
	for(int i(1);i<=n;i++){
		cin>>b[i]>>l[i];
		l[i]/=100.0;
	}
	f(1,k);
	printf("%0.6f",ans);
	return 0;
} 
