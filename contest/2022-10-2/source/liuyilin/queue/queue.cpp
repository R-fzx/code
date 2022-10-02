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
int a[305];
int main(){
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	srand(587675860);
	int n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	a[0]=1000;
	register int t=0,s=0;
	while(clock()<960){
		t++;
		random_shuffle(a+1,a+n+1);
		for(register int i=1;i<=n;i++){
			register int j=i-1;
			s++;
			while(a[j]<a[i]){
				j--;s++;
			}
		}
	}
	cout<<fixed<<setprecision(2)<<s*1.0/t<<endl;
	return 0;
}
