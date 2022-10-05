#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),putchar('\n')
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}
inline void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
const int N=8e2+9;
int n,cl,clk,v1[N],v2[N],v3[N],v4[N],ans,vis[N];
int dj(int x[],int y[],int len){
	int cnt=0;
	for(int i=1;i<=len;i++)cnt+=x[i]*y[i];
	return cnt;
}
bool cmp(int x,int y){return x>y;}
void write(int x[],int ln){
	for(int i=1;i<=ln;i++)cout<<x[i]<<" ";
	cout<<endl;
}
signed main(){
	freopen("scalar.in","r",stdin);
	freopen("scalar.out","w",stdout);
	cl=clock();
	cout<<clock()<<endl;
	n=read();
	for(int i=1;i<=n;i++)v1[i]=read();
	for(int i=1;i<=n;i++)v2[i]=read();
	sort(v1+1,v1+n+1);
	sort(v2+1,v2+n+1,cmp);
	ans=dj(v1,v2,n);
	cout<<ans<<endl;
	v1[0]=v1[n];
	v2[0]=v2[n];
	while(1){
		clk=clock();
		if(clk-cl>=800){printen(ans);cout<<clock()<<endl;return 0;}
		memset(vis,0,sizeof(vis));
		memset(v3,0,sizeof(v3));
		memset(v4,0,sizeof(v4));
		srand(clock());
		clk=clock();
		if(clk-cl>=800){printen(ans);cout<<clock()<<endl;return 0;}
		for(int i=1;i<=n;i++){
			clk=clock();
			if(clk-cl>=800){printen(ans);cout<<clock()<<endl;return 0;}
			int pos=rand()%n;
			while(vis[pos]){pos=(pos+1)%n;}
			vis[pos]=1;
			v3[i]=v1[pos];
		}
		int clk=clock();
		if(clk-cl>=800){printen(ans);cout<<clock()<<endl;return 0;}
		memset(vis,0,sizeof(vis));
		clk=clock();
		if(clk-cl>=800){printen(ans);cout<<clock()<<endl;return 0;}
		for(int i=1;i<=n;i++){
			clk=clock();
			if(clk-cl>=800){printen(ans);cout<<clock()<<endl;return 0;}
			int pos=rand()%n;
			while(vis[pos]){pos=(pos+1)%n;}
			vis[pos]=1;
			v4[i]=v2[pos];
		}
		clk=clock();
		if(clk-cl>=800){printen(ans);cout<<clock()<<endl;return 0;}
		ans=min(ans,dj(v3,v4,n));
		clk=clock();
		if(clk-cl>=800){printen(ans);cout<<clock()<<endl;return 0;}
	}
	return 0;
}
/*
6
1 1 4 5 1 4
1 9 1 9 8 1
*/
