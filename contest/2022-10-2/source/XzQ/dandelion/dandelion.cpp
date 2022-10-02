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
const int N=4e4+9;
struct node{
	int l,r,col[N];
}s[(int)2e2+9];
int n,m,ans,cnt,a[N],Cnt,Tmp[N],T[N],stk[N],lstl,maxc,lstr;
map<int,int>co;
signed main(){
	freopen("dandelion.in","r",stdin);
	freopen("dandelion.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),maxc=max(a[i],maxc);
	cnt=1;
	s[1].l=1;
	for(int i=1;i<=n;i++){
		s[cnt].col[a[i]]++;
		stk[i]=cnt;
		if(i%((int)sqrt(n))==0)s[cnt].r=i,cnt++,s[cnt].l=i+1;
	}
	while(m--){
		int l=read(),r=read();
		l=(l+ans-1)%n+1,r=(r+ans-1)%n+1;
		if(l>r)swap(l,r);
		while(lstl<l)co[a[lstl++]]--;
		while(lstl>l)co[a[--lstl]]++;
		while(lstr<r)co[a[++lstr]]++;
		while(lstr>r)co[a[lstr--]]--;
		for(int i=1;i<=maxc;i++)ans=co[ans]<co[i]?i:ans;
		printen(ans);
	}
	return 0;
}
