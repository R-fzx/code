#include<bits/stdc++.h>
using namespace std;
const double ex=1e-5;
struct node{
	int xa,ya,xb,yb;
}line[100005];
int n;
bool check(node a,node b){
	double k1;
	if(a.xa==a.xb)k1=1e10;
	else k1=1.0*(a.ya-a.yb)/(a.xa-a.xb);
	double k2;
	if(b.xa==b.xb)k2=1e10;
	else k2=1.0*(b.ya-b.yb)/(b.xa-b.xb);
	double b1=1.0*(a.yb-k1*a.xb),b2=1.0*(b.yb-k2*b.xb);
	if(k1==1e10){
		if(k2==1e10){
			if(a.xa!=b.xa)return 0;
			if(max(a.ya,a.yb)>min(b.ya,b.yb)&&max(b.ya,b.yb)>min(a.ya,a.yb))return 1;
			return 0;
		}
		if(1.0*min(b.xa,b.xb)>a.xa+ex||1.0*max(b.xa,b.xb)<a.xa-ex)return 0;
		if(k2*a.xa+b2>=min(a.ya,a.yb)&&k2*a.xa+b2<=max(a.ya,a.yb))return 1;
		return 0;
	}
	else if(k2==1e10){
		if(1.0*min(a.xa,a.xb)>b.xa+ex||1.0*max(a.xa,a.xb)<b.xa-ex)return 0;
		if(k1*b.xa+b1>=min(b.ya,b.yb)&&k1*b.xa+b1<=max(b.ya,b.yb))return 1;
		return 0;
	}
	else{
		if(fabs(k1-k2)<=ex){
			if(max(a.xa,a.xb)>min(b.xa,b.xb)&&min(a.xa,a.xb)<max(b.xa,b.xb))return 1;
			return 0;
		}
		double x=1.0*(b2-b1)/(k1-k2);
		if(1.0*min(a.xa,a.xb)<=x+ex&&x-ex<=1.0*max(a.xa,a.xb)&&1.0*min(b.xa,b.xb)<=x+ex&&x-ex<=1.0*max(b.xa,b.xb))return 1;
		return 0;
	}
}
int cnt[100005];
signed main(){
	freopen("cowjump.in","r",stdin);
	freopen("cowjump.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	//cout<<"wdnmd"<<'\n';
	for(register int i=1;i<=n;++i){
		cin>>line[i].xa>>line[i].ya>>line[i].xb>>line[i].yb;
		for(register int j=1;j<i;++j){ 
			if(check(line[i],line[j])){
				cnt[i]++;
				cnt[j]++;
				if(cnt[j]>1){
					cout<<j;
					return 0;
				}
				if(cnt[i]>1){
					cout<<i;
					return 0;
				}
			}
		} 
	}
	for(register int i=1;i<=n;++i){
		if(cnt[i]>=1){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
