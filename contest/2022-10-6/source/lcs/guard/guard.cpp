#include<bits/stdc++.h>
using namespace std;
int n,l,k,tot1,tot2;
struct node{
	int g,val;
}mp[205],bg[205];
int g[205];
double dp[205][205][205];
bool cmp(node x,node y){return x.g>y.g;}
double DT[205];
int main(){
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	scanf("%d%d%d",&n,&l,&k);
	for(int i=1;i<=n;++i)scanf("%d",&g[i]);
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		if(x==-1)mp[++tot1].g=g[i];
		else bg[++tot2].g=g[i],bg[tot2].val=x;
	}
	dp[0][0][k]=1;
	for(int i=1;i<=tot2;++i){
		for(int p=1;p<=200;++p){
			for(int q=0;q<=200;++q){
				dp[i][p][min(q+bg[i].val,200)]+=dp[i-1][p-1][q]*double(bg[i].g)/100;
				dp[i][p-1][q]+=dp[i-1][p-1][q]*double(100-bg[i].g)/100;
			}
		}
	}
	sort(mp+1,mp+tot1+1,cmp);
	double ans=0;
	DT[0]=1;
	for(int i=0;i<=tot1;++i){
		for(int j=tot2;j>=1;--j){
			DT[j]=DT[j]*(double)(100-mp[i].g)/100+DT[j-1]*(double)(mp[i].g)/100;
		}
		DT[0]*=(double)(100-mp[i].g)/100;
		double sum=0;
		for(int j=0;j<=tot2;++j){
			for(int p=l-j;p<=200;++p){
				for(int q=j;q<=200;++q){
					sum+=dp[tot2][p][q]*DT[j];
				}
			}
		}
		ans=max(ans,sum);
	}
	printf("%.6lf",ans);
	return 0;
}
