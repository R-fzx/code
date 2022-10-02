#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int n,sum;
int num[maxn][maxn],L[maxn][maxn],R[maxn][maxn];
int tmp[maxn*maxn];
bool cmp(int a,int b){
	int x=R[a%n==0?a/n:a/n+1][(a-1)%n+1]*num[a%n==0?a/n:a/n+1][(a-1)%n+1],
		y=R[b%n==0?b/n:b/n+1][(b-1)%n+1]*num[b%n==0?b/n:b/n+1][(b-1)%n+1];
	if(x==y)return L[a/n+1][a%n]<L[b/n+1][b%n];
	return x<y;
}
int main(){
	freopen("garland.in","r",stdin);
	freopen("garland.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&num[i][j]);
			tmp[(i-1)*n+j]=(i-1)*n+j;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&L[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&R[i][j]);
			sum+=R[i][j];
		}
	sort(tmp+1,tmp+1+n*n,cmp);
//	for(int i=1;i<=n*n;i++)
//		cout<<tmp[i]<<' ';
//	cout<<endl<<endl;
	for(int i=1;i<=n*n;i++){
		int x=tmp[i]%n==0?tmp[i]/n:tmp[i]/n+1,y=(tmp[i]-1)%n+1;
		if(R[x][y]-L[x][y]>=sum){
			R[x][y]-=sum;
			break;
		}else{
			sum-=R[x][y]-L[x][y];
			R[x][y]=L[x][y];
		}
//		getchar();
//		cout<<sum<<endl;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++)
//				cout<<R[i][j]<<' ';
//			cout<<endl;
//		}
//		cout<<endl;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans+=num[i][j]*R[i][j];
	printf("%d\n",ans);
	return 0;
}
