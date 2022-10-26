#define Exam_By_Ew_Cors

#include<bits/stdc++.h>
using namespace std;

#ifdef Exam_By_Ew_Cors
ifstream fin("h.in");
ofstream fout("h.out");
#define cin fin
#define cout fout
#endif

//const int BUILDING=1,ROOM=0;
//struct node{
//	int h,id,tp;
//}a[400005];
int n;
int st[200005][18],lgg[200005];
void init_st(){
	lgg[0]=-1;
	for(int i=1;i<=n;i++)lgg[i]=lgg[i>>1]+1;
	for(int j=1;j<=lgg[n];j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int query_st(int l,int r){
	int len=lgg[r-l+1];
	return min(st[l][len],st[r-(1<<len)+1][len]);
}

int m,L,x[1005],y[1005];
int main(){
	std::ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>L;
	for(int i=1,x;i<=n;i++)cin>>st[i][0];
	init_st();
	cin>>m;
	for(int i=1;i<=m;i++)cin>>x[i]>>y[i];
	long long ans=0;
	for(int i=1;i<=m;i++)for(int j=i+1;j<=m;j++){
		int lowest=query_st(min(x[i],x[j]),max(x[i],x[j])),now;
		if(lowest<y[i] && lowest<y[j])
			now=y[i]-lowest+y[j]-lowest+abs(x[i]-x[j]);
		else
			now=abs(y[i]-y[j])+abs(x[i]-x[j]);
		if(now<=L)ans++;
	}
	cout<<ans;
	return 0;
}

#ifdef Exam_By_Ew_Cors
#undef cin
#undef cout 
#endif
