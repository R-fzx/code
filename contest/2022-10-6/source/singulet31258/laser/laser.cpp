#include<cstdio>
#include<cstring>
#include<algorithm>
#define scan(i,a,b) for(int i=a;i<=b;++i)
#define _ long long
#define N 10001
int n,k,x,y;
bool e[10][10],bz[10],now[10];
_ a[N],b[N],p,l,r,pa,pb,sa,sb,ax,ay,bx,by;
inline int get(_ x){
	int t=std::upper_bound(a+1,a+n+1,x)-a-1;
	if(x<=b[t])return t;
	else return 0;
}
inline void update(int u,int v){
	x=get(sa);y=get(sb);
	e[u][v]=e[v][u]=u&&v&&u==v;
}
void dfs(int x){
	bz[x]=1;printf("%d",x);
	scan(y,1,9)now[y]&=e[x][y];
	scan(y,1,9)if(!bz[y]&&now[y])dfs(y);
}
int main(){
	freopen("laser.in","r",stdin);freopen("laser.out","w",stdout);
	scanf("%d%d",&n,&k);
	scan(i,1,n){
		scanf("%lld%lld",a+i,b+i);
		if(i>1&&a[i]-b[i-1]==1)b[i-1]=b[i],--i,--n;
	}memset(e,1,sizeof e);
	scan(i,1,n){
		p=1;scan(j,1,k){
			l=a[i]/p%10;r=b[i]/p%10;
			pa=a[i]/(p*10)*p*10;pb=b[i]/(p*10)*p*10;
			if(pa==pb)scan(x,l+1,r-1)scan(y,1,9)if(x!=y&&e[x][y]){
				sa=pa+p*y;sb=pb+p*(y+1)-1;
				update(x,y);
			}else{
				scan(x,l+1,9)scan(y,1,9)if(x!=y&&e[x][y]){
					sa=pa+p*y;sb=pb+p*(y+1)-1;
					update(x,y);
				}
				scan(x,1,r-1)scan(y,1,9)if(x!=y&&e[x][y]){
					sa=pa+p*y;sb=pb+p*(y+1)-1;
					update(x,y);
				}
			}
			ax=a[i]%p;ay=p-1;bx=0;by=b[i]%p;
			if(pa==pb&&l==r)ay=by,bx=ax;
			scan(k,1,9){
				if(k!=l&&e[l][k]){
					sa=pa+k*p+ax;sb=pa+k*p+ay;
					update(l,k);
				}
				if(k!=r&&e[r][k]){
					sa=pb+k*p+bx;sb=pb+k*p+by;
					update(r,k);
				}
			}
			p*=10;
		}
	}
	scan(i,1,9)if(!bz[i]){
		memset(now,1,sizeof now);
		dfs(i);
		putchar('\n');
	}
	return 0;
}
