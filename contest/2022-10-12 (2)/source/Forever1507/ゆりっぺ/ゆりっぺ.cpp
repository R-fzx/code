#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,A,B,C;
struct node{
	int a,b,c;
}x[500005];
int dp[105][105][105],sum[105][105][105];
bool cmp(node a,node b){
	return a.a+a.b+a.c>b.a+b.b+b.c;
}
//priority_queue<int>qa,qb,qc;
signed main(){
	freopen("ゆりっぺ.in","r",stdin);
	freopen("ゆりっぺ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>A>>B>>C;
	if(A+B+C>n){
		cout<<"woshishenben";
		return 0;
	}
	for(int i=1;i<=n;++i)cin>>x[i].a>>x[i].b>>x[i].c;
	sort(x+1,x+n+1,cmp);
//	for(int i=1;i<=n;++i){
//		for(int j=0;j<=A+B+C;++j){
//			
//		}
	for(int i=1;i<=n;++i){
		for(int _A=A;_A>=0;--_A){
//	puts("1");
			for(int _B=B;_B>=0;--_B){
				for(int _C=C;_C>=0;--_C){
	//				int numa=qa.top(),numb=qb.top(),numc=qc.top();
						if(_A&&dp[_A-1][_B][_C]+x[i].a>dp[_A][_B][_C]){
							dp[_A][_B][_C]=dp[_A-1][_B][_C]+x[i].a;
							sum[_A][_B][_C]=sum[_A-1][_B][_C]+x[i].a+x[i].b+x[i].c;
						}
						if(_B&&dp[_A][_B-1][_C]+x[i].b>dp[_A][_B][_C]){
							dp[_A][_B][_C]=max(dp[_A][_B][_C],dp[_A][_B-1][_C]+x[i].b);
							sum[_A][_B][_C]=sum[_A][_B-1][_C]+x[i].a+x[i].b+x[i].c;
						}
						if(_C&&dp[_A][_B][_C-1]+x[i].c>dp[_A][_B][_C]){
							dp[_A][_B][_C]=max(dp[_A][_B][_C],dp[_A][_B][_C-1]+x[i].c);
							sum[_A][_B][_C]=sum[_A][_B][_C-1]+x[i].a+x[i].b+x[i].c;
						}
//						cout<<_A<<' '<<_B<<' '<<_C<<' '<<dp[_A][_B][_C]<<'\n';
				}	
			}
		}
	}
	cout<<dp[A][B][C]<<'\n'<<sum[A][B][C];
	return 0;
}

