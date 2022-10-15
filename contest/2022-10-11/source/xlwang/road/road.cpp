#include<bits/stdc++.h>
#define int long long
#define fr(i,j,k) for(register int i=j;i<=k;++i)
#define rf(i,j,k) for(register int i=j;i>=k;--i)
using namespace std;
inline int read(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?-x:x;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline void writepl(int x){write(x);putchar(' ');}
inline void writeln(int x){write(x);putchar('\n');}
const int Maxn=2e2+10,Maxm=5e4+10,inf=1e18;
int n,m,p,q;
struct node{
	int u,v;
	int val1,val2;
}e[Maxm];
int fa[Maxn];
map<int,int> mp1,mp2;
int to1[Maxm],to2[Maxm];
int num1,num2;
inline bool cmp1(node a,node b){return a.val1<b.val1;}
inline bool cmp2(node a,node b){return a.val2<b.val2;}
inline void add(){
	sort(e+1,e+m+1,cmp1);
	fr(i,1,m) if(!mp1[e[i].val1]) mp1[e[i].val1]=++num1,to1[num1]=e[i].val1;
	sort(e+1,e+m+1,cmp2);
	fr(i,1,m) if(!mp2[e[i].val2]) mp2[e[i].val2]=++num2,to2[num2]=e[i].val2; 
}
inline int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
inline void init(){
	n=read(),m=read(),p=read(),q=read();
	fr(i,1,m) e[i].u=read(),e[i].v=read(),e[i].val1=read(),e[i].val2=read();
}
inline bool check1(int x,int y){
//	printf("check1:");
//	writepl(x);
//	writeln(y);
	fr(i,1,n) fa[i]=i;
	fr(i,1,m) if(e[i].val1<=x && e[i].val2<=y) fa[find(e[i].u)]=find(e[i].v);
	fr(i,1,n) fa[i]=find(fa[i]);
//	fr(i,1,n) writepl(i),writeln(fa[i]);
	fr(i,1,n) if(fa[i]!=fa[1]) return false;
	return true;
}
inline void into(int x){
	int l,r;
	l=0,r=num2+1;
	int ans=0;
	while(l<=r){
		int mid;
		mid=(l+r)>>1;
		if(check1(to1[x],to2[mid])) r=mid-1,ans=mid;
		else l=mid+1;
	}
	writeln(to1[x]*p+to2[ans]*q);
}
inline int check(int x){
	int l,r;
	l=0,r=num2+1;
	int ans=0;
	while(l<=r){
		int mid;
		mid=(l+r)>>1;
		if(check1(to1[x],to2[mid])) r=mid-1,ans=mid;
		else l=mid+1;
	}
	if(ans==0) return inf;
//	writepl(x);
//	writeln(ans);
	return to1[x]*p+to2[ans]*q;
}
inline void work(){
	add();
	int l=0,r=num1+1;
//	writeln(check(5));
	while(l<=r && l<=num1){
//		writepl(l),writeln(r);
		int ll,rr;
		if(l>=(r-1)){
//			printf("check:");
//			writepl(l);
//			writeln(r);
			if(check(l)==inf && check(r)==inf) {
				puts("-1");
				return;
			}
			if(check(l)<=check(r)){
				into(l);
				return;
			}
			else {
				into(r);
				return;
			}
		}
		int mid1,mid2;
		mid1=(l+l+r)/3,mid2=(r+r+l)/3;
		if(check(mid1)<check(mid2)) r=mid2-1;
		else if(check(mid1)>check(mid2)) l=mid1+1;
		else l=mid1,r=mid2;
//		writepl(l),writeln(r);
	}
	writeln(-1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	work();
	return 0;
}
