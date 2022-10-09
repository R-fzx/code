#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
double a,eps;

void ft(int ax,int ay,int bx,int by){
	int cx=ax+bx,cy=ay+by;
	if(fabs(a-(double)(cx)/cy)<=eps){
		cout<<cy<<endl;
		return;
	}
	if(a-(double)(cx)/cy>eps)
		ft(cx,cy,bx,by);
	else
		ft(ax,ay,cx,cy);
}

signed main(){
	freopen("baseball.in","r",stdin);
	freopen("baseball.out","w",stdout);
	
	while(cin>>n>>a){
		eps=1;
		for(int i=1;i<=n;i++)eps/=10;
		eps/=2;
		
		if(a<eps){
			cout<<"1\n";
			continue;
		}
		
		ft(0,1,1,1);
	}
	return 0;
}
