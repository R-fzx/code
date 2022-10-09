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
int n,m,ans,len;
void dfs(int num,int cnt,int l){
	if(l==len)return;
	for(int i=1;i<10;++i){
		int nm=num*10+i;
		int k=nm*cnt*i;
		if(k>m)break;
		if((k>=n)&&(k<=m))ans++;
		dfs(nm,cnt*i,l+1);
	}
	return;
}
void work2(){
//	cout<<clock()<<endl;
	int t=m;
	while(t){
		len++;
		t/=10;
	}
	dfs(0,1,0);
	print(ans);
//	cout<<endl<<clock()<<endl;
}
signed main(){
	freopen("sillyz.in","r",stdin);
	freopen("sillyz.out","w",stdout);
	n=read(),m=read();
	if(m<n)swap(n,m);
	return work2(),0;
	return 0;
}
