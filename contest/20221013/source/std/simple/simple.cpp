#include <iostream> 
#include <algorithm>
#define ll long long 
using namespace std; 
const int MAXBUF=20000005; 
char B[MAXBUF],*Si=B,*Ti=B; 
inline char getc() {
	if (Si==Ti) Ti=(Si=B)+fread(B,1,MAXBUF,stdin); 
	if (Si==Ti) return 0; 
	return *Si++; 
}
template <class T> 
inline void read(T &a) {
	static char c; 
	while ((c=getc())<'0'||c>'9');a=c-'0'; 
	while ((c=getc())>='0'&&c<='9') a=(a<<3)+(a<<1)+c-'0'; 
}
char Buff[MAXBUF],*sti=Buff; 
template <class T> 
inline void write(T a) {
	if (a==0) {*sti++='0';return;} 
	int t[21],cnt=0; 
	while (a) t[++cnt]=a%10,a/=10; 
	for (int i=cnt;i>=1;i--) *sti++='0'+t[i]; 
}
const int N=1000000; 
int px[N+5],py[N+5]; 
ll sx[N+5],sy[N+5]; 
inline int max(int a,int b) {return a>b?a:b;} 
inline int cal(int a) { return a<0?-a:a; } 

int main (){ 
	freopen("simple.in","r",stdin);
	freopen("simple.out","w",stdout);
	
	int T;read(T); 
	while (T--) {
		int i,n,q,x,y,tx,ty; 
		read(n);read(q); 
		for (i=1;i<=n;i++) {
			read(x);read(y); 
			px[i]=x+y;py[i]=x-y; 
		}
		sort(px+1,px+n+1); 
		sort(py+1,py+n+1); 
		for (i=1;i<=n;i++) {
			sx[i]=sx[i-1]+px[i]; 
			sy[i]=sy[i-1]+py[i]; 
		}
		while (q--) {
			ll ans=0; 
			read(tx);read(ty); 
			x=tx+ty;y=tx-ty;
			int l=1,r=n; 
			while (l<=r) {
				int mid=(l+r)>>1; 
				if (px[mid]<=x) { l=mid+1;} 
				else { r=mid-1;} 
			}
			ans+=1ll*r*x-sx[r]; 
			ans+=(sx[n]-sx[r])-1ll*(n-r)*x; 
			l=1,r=n; 
			while (l<=r) {
				int mid=(l+r)>>1; 
				if (py[mid]<=y) { l=mid+1;} 
				else { r=mid-1;} 
			}
			ans+=1ll*r*y-sy[r]; 
			ans+=(sy[n]-sy[r])-1ll*(n-r)*y; 
			ans>>=1ll; 
			write(ans),*sti++='\n'; 
		}
	}
	fwrite(Buff,1,sti-Buff,stdout); 
	return 0; 
}

