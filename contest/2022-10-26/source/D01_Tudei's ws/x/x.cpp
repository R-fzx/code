#include<bits/stdc++.h>
#include<random>
using namespace std;

ifstream fin("x.in");
ofstream fout("x.out");
#define cin fin
#define cout fout

int n,x[100005],y[100005];
struct node{int w,id;}p[100005];
int rns[100005],lns[100005];
int b[200005],bcnt;

int c[200005];
void add(int p,int k){for(;p<=bcnt;p+=p&-p)c[p]=max(c[p],k);}
int sum(int p){int s=0;for(;p;p-=p&-p)s=max(s,c[p]);return s;}

int main(){
	std::ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)b[i*2-1]=x[i]+y[i],b[i*2]=x[i]-y[i];
	sort(b+1,b+n*2+1);bcnt=unique(b+1,b+2*n+1)-b-1;
	
//	cerr<<"b:\n";for(int i=1;i<=bcnt;i++)cerr<<b[i]<<' ';cerr<<endl;
	
	memset(c,0,sizeof c);
	for(int i=1;i<=n;i++)p[i]=(node){lower_bound(b+1,b+bcnt+1,x[i]-y[i])-b,i};
	sort(p+1,p+n+1,[](node x,node y){return x.w<y.w;});
	
	for(int i=n;i;i--){
		int np=lower_bound(b+1,b+bcnt+1,x[p[i].id]+y[p[i].id])-b;
//		cerr<<p[i].id<<' '<<np<<endl;
		rns[p[i].id]=sum(bcnt-np);
		add(bcnt-p[i].w+1,rns[p[i].id]+1);
	}
	
	memset(c,0,sizeof c);
	for(int i=1;i<=n;i++)p[i]=(node){lower_bound(b+1,b+bcnt+1,x[i]+y[i])-b,i};
	sort(p+1,p+n+1,[](node x,node y){return x.w<y.w;});
	
	for(int i=1;i<=n;i++){
		int np=lower_bound(b+1,b+bcnt+1,x[p[i].id]-y[p[i].id])-b;
		lns[p[i].id]=sum(np-1);
		add(p[i].w,lns[p[i].id]+1);
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
//		cerr<<x[i]<<' '<<y[i]<<' '<<lns[i]<<' '<<rns[i]<<endl;
		ans=max(ans,lns[i]+rns[i]+1);
	}
	cout<<ans;
	return 0;
}
#undef cin
#undef cout
