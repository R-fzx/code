#include<bits/stdc++.h>
using namespace std;

int k;

long long calc(int n,int x,int y,int u){
	if(x>y)swap(x,y);
	
//	cerr<<"Calc:"<<n<<' '<<x<<' '<<y<<' '<<u<<endl;
	
	return 1LL*min(y-x,n+x-y)*u;
}

long long change(int a[],int n){
	int bse=k/n;
	
	vector<pair<int,int> >gv,lv;//val,id
	
//	for(int i=1;i<=n;i++)
//		cerr<<a[i]<<' ';
//	cerr<<endl;
	
	for(int i=1;i<=n;i++){
		if(a[i]>bse)
			gv.push_back(make_pair(a[i]-bse,i));
		else if(a[i]<bse)
			lv.push_back(make_pair(bse-a[i],i));
	}
	
//	for(int i=0;i<lv.size();i++)
//		cerr<<lv[i].first<<' '<<lv[i].second<<endl;
//	cerr<<endl;
//	for(int i=0;i<gv.size();i++)
//		cerr<<gv[i].first<<' '<<gv[i].second<<endl;
//	cerr<<endl;
	
	int p=0;
	long long sum=0;
	
	for(int i=0;i<lv.size();i++){
		while(lv[i].first>gv[p].first){
			sum+=calc(n,
					  lv[i].second,
					  gv[p].second,
					  gv[p].first);
			
			lv[i].first-=gv[p].first;
			p++;
		}
		sum+=calc(n,
				  lv[i].second,
				  gv[p].second,
				  lv[i].first);
		
		gv[p].first-=lv[i].first;
	}
	return sum;
}

int n,m;
int h[100005],l[100005];

int main(){
	freopen("tanabata.in","r",stdin);
	freopen("tanabata.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1,x,y;i<=k;i++){
		cin>>x>>y;
		
		h[x]++,
		l[y]++;
	}
	
	if(k%n && k%m){
		cout<<"impossible";
	}
	else if(k%m){
		cout<<"row ";
		cout<<change(h,n);
	}
	else if(k%n){
		cout<<"column ";
		cout<<change(l,m);
	}
	else{
		cout<<"both ";
		cout<<(change(h,n)+change(l,m));
	}
	return 0;
}
