#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();
	bool f=false;
	int r=0;
	while(c<'0'||c>'9') f=c=='-',c=getchar();
	while(c>='0'&&c<='9') {
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar(); 
	}
	return f?-r:r;
} 
struct fpair{
	int x,y;
	int t;
}a[505*505];
int l[505][505];
int r[505][505];
bool cmp(fpair p,fpair q){
	return p.t>q.t;
}
int main(){
	freopen("garland.in","r",stdin);
	freopen("garland.out","w",stdout);
	int n=read();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			a[i*n+j].t=read();
			a[i*n+j].x=i;
			a[i*n+j].y=j;
		}
	sort(a,a+n*n,cmp);
	int s=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			l[i][j]=read();
			s+=l[i][j];
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			r[i][j]=read();
	int ans=0;
	for(int i=0;s<0;i++){
		int dt=min(-s,r[a[i].x][a[i].y]-l[a[i].x][a[i].y]);
		int p=l[a[i].x][a[i].y]+dt;
		ans+=p*a[i].t;
		s+=dt;
	}
	cout<<ans<<endl;
	return 0;
}
