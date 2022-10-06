#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long r=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r;
}
const int N=1e4+5;
long long a[N],b[N];
int fa[10];
void cut(int x,int y){
	int t=fa[x];
	for(int i=y;i<10;i++)
		if(fa[i]==t) fa[i]=y;
	return;
}
void print(){
	for(int i=1;i<10;i++){
		int v[10],s=0;
		for(int j=1;j<10;j++)
			if(fa[j]==i) v[++s]=j;
		if(s){
			for(int i=1;i<=s;i++)
				cout<<v[i];
			cout<<endl;
		}
	}
	return;
}
int main(){
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	int n=read(),k=read();
	for(int i=0;i<n;i++)
		a[i]=read(),b[i]=read();
	for(int i=0;i<10;i++)
		fa[i]=1;
	if(k==1){
		for(int i=0;i<n;i++){
			cut(a[i]%10-1,a[i]%10);
			cut(b[i]%10,b[i]%10+1);
		}
		print();
	}
	else if(n==1){
		long long A=a[0],B=b[0];
		bool f1=true,f2=true;
		for(int i=0;i<k;i++){
			int r1=A%10;
			A/=10;
			if(r1>0) f1=false;
			if(r1==1&&!i) f1=true;
			if(!f1){
				cut(r1-1,r1);
				if(i)
					cut(r1,r1+1);
			}
			int r2=B%10;
			B/=10;
			if(r2<9) f2=false;
			if(!f2){
				cut(r2,r2+1);
				if(i)
					cut(r2-1,r2);
			}
		}
		print();
	}
//	else if(n<=50){
//		for(int i=0;i<n;i++)
//			for(int j=a[i];j<=b[i];j++){
//				int x=1;
//				for(int l=1;l<=k;l++){
//					bool f=false;
//					for(int p=0;p<n;p++)
//						if(j+x>=a[p]&&j+x<=b[p]) f=true;
//					if(!f) cut(j/x%10,j/x%10+1);
//					for(int p=0;p<n;p++)
//						if(j-x>=a[p]&&j-x<=b[p]) f=true;
//					if(!f) cut(j/x%10-1,j/x%10);
//					x*=10;
//				}
//			}
//		print();
//	}
	else {
		printf("1\n2\n3\n4\n5\n6\n7\n8\n9\n");
	}
	return 0;
}
