#include<bits/stdc++.h>
#define int long long 
#define printsp(x) print(x),putchar(' ')
#define printlf(x) print(x),putchar('\n')
using namespace std;
inline int read(){
	int x=0;bool w=0;char c=getchar();
	while(!isdigit(c))	w|=c=='-',c=getchar();
	while(isdigit(c))	x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return w?-x:x;
}
inline void print(int x){
	if(x>9)	print(x/10);
	if(x<0)	putchar('-'),x=-x;
	putchar('0'+x%10);
}
string s;
int p[100][100];
int zero,ans;
inline int A(int n,int m){
	if(p[n][m])	return p[n][m];
	int res=1;
	for(register int i=n;i>=n-m+1;--i)
		res*=i;p[n][m]=res;
	return res;
}
signed main(){
//	freopen("perm.in","r",stdin);
//	freopen("perm.out","w",stdout);
	cin>>s;
	int len=s.length()-1;
	for(register int i=0;i<len;++i){
		if(s[i]=='0')	++zero;
	}
	int zh=len-zero;
	ans+=A(len-1,zh);
	for(register int i=1;i<s[0];++i)
		ans+=A(len-1,zh-1);
	for(register int i=1;i<len;++i){
		if(s[i]==0){
			zero--;
		}
		else{
			zh--;
			int a=s[i]-'0'-1;
			ans+=a*A()
		}
	}
	
	print(ans);
	return 0;
}

