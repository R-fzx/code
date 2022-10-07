#include<bits/stdc++.h>
using namespace std;
long long gcd(long long m,long long n){
	long long r=m%n;
	if(!r) return n;
	return gcd(n,r);
}
map<long long,long long>p;
int main(){
	freopen("kubi.in","r",stdin);
	freopen("kubi.out","w",stdout);
	long long a,b,k,r;
	long long m,l;
	int t;cin>>t;
	while(t--){
		cin>>a>>b>>k;
		r=gcd(a,b);
		a/=r;b/=r;
		l=1;
		p.clear();
		while(p[a]==0){
			p[a]=l;
			a=a*k%b;
			l++;
		}
		m=p[a]-1;l=l-m-1;
		if(a==0) l=0;
		cout<<m<<' '<<l<<endl;
	}
	return 0;
}
