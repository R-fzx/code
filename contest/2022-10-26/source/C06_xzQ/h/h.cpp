#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),puts("")
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
void print(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
const int N=2e5+9;
struct node{
	int l,r,minn;
}stk[(int)sqrt(N)];
struct node2{
	int x,y;
}q[N];
int n,k,m,a[N],T,qmin[N<<2],cnt=1,ans,pos[N],g[N];
//int qmin(int L,int R){
//	if(L>R)swap(L,R);
//	int pl=pos[L],pr=pos[R],tmp=INT_MAX;
//	if(pr-pl<=1){
//		for(int i=L;i<=R;i++)tmp=min(tmp,a[i]);
//		return tmp;
//	}
//	for(int i=pl+1;i<=pr-1;i++)tmp=min(tmp,stk[i].minn);
//	for(int i=L;i<=stk[pl].r;i++)tmp=min(tmp,a[i]);
//	for(int i=R;i>=stk[pr].l;i--)tmp=min(tmp,a[i]);
//	return tmp;
//}
void update(int x){qmin[x]=min(qmin[x<<1],qmin[x<<1|1]);}
void build(int l,int r,int x){
	if(l==r){qmin[x]=a[l];return;}
	int mid=l+r>>1;
	build(l,mid,x<<1);
	build(mid+1,r,x<<1|1);
	update(x);
}
int query(int l,int r,int L,int R,int x){
	if(l==L&&r==R)return qmin[x];
	int mid=l+r>>1;
	if(R<=mid)return query(l,mid,L,R,x<<1);
	else if(L>mid)return query(mid+1,r,L,R,x<<1|1);
	else return min(query(l,mid,L,mid,x<<1),query(mid+1,r,mid+1,R,x<<1));
}
bool check(int u,int v){
	if(v==m+1||u==v)return 0;
	int xa=q[u].x,xb=q[v].x,ya=q[u].y,yb=q[v].y,mh=min(min(ya,yb),query(1,n,xa,xb,1));
	if(xb-xa+ya-mh+yb-mh<=k)return 1;
	return 0;
}
bool cmp(node2 u,node2 v){return (u.x!=v.x)?(u.x<v.x):(u.y<v.y);}
signed main(){
	freopen("h.in","r",stdin);
	freopen("h.out","w",stdout);
	n=read(),k=read();
	T=(int)sqrt(n);
	for(int i=1;i<=n;i++)a[i]=read();
//	stk[1].l=1;
//	for(int i=1;i<=n;i++){
//		pos[i]=cnt;
//		if(i%T==0)stk[cnt].r=i,stk[++cnt].l=i+1;
//	}
//	if(stk[cnt].l>n)cnt--;
//	else stk[cnt].r=n;
//	for(int i=1;i<=cnt;i++){
//		int miin=INT_MAX;
//		for(int j=stk[i].l;j<=stk[i].r;j++)miin=min(miin,a[j]);
//		stk[i].minn=miin;
//	}
	build(1,n,1);
	m=read();
	for(int i=1;i<=m;i++)q[i].x=read(),q[i].y=read();
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++)if(q[j].y>=q[i].y){g[i]=j;break;}
		if(!g[i])g[i]=m+1;
	}
	for(int i=1;i<=m;i++){
		int tmp=i;
		while(1){
			if(check(i,g[tmp]))tmp=g[tmp];
			else break;
		}
		ans+=tmp-i;
		for(int j=tmp+1;j<=g[tmp];j++)ans+=check(i,j);
	}
	print(ans);
	return 0;
}
/*
5 7
4 1 1 3 1
3
1 4
3 1
4 3
*/
