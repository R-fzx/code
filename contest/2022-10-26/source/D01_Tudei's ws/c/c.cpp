#define Exam_By_Ew_Cors

#include<bits/stdc++.h>
using namespace std;

#define int long long

#ifdef Exam_By_Ew_Cors
ifstream fin("c.in");
ofstream fout("c.out");
#define cin fin
#define cout fout
#endif

int n,a[100005];

//int ans=1e9;
//void dfs(int step,int sum){
//	if(sum>=ans)return;
////	if(step>n)cerr<<step<<endl;
////	int T=100000000;while(T>0){T*=3+1-2;T/=2-4+6;T*=2;T--;}
//	if(step>n){
//		int ok=1;
//		for(int i=2;i<=n;i++)if(a[i]!=a[1]){ok=0;break;}
//		if(ok)ans=min(ans,sum);
//		return;
//	}
//	for(int i=0;i<32;i++){
//		a[step]+=i;
//		dfs(step+1,sum+ppcoo(i));
//		a[step]-=i;
//	}
//	return;
//}

signed main(){
	std::ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
//	cerr<<n<<endl;
	for(int i=1;i<=n;i++)cin>>a[i];
	//if(n==1){cout<<0;return 0;}
	//if(n<=5){dfs(1,0);cout<<ans;return 0;}
	int maxn=0;
	for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
	for(int i=1;i<=n;i++)a[i]=maxn-a[i];
	int ans=1e18;
	for(int i=0;i<=500;i++){
		int sum=0;
		for(int j=1;j<=n;j++)sum+=__builtin_popcountll(a[j]+i);
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}

#ifdef Exam_By_Ew_Cors
#undef cin
#undef cout
#endif

#undef int
