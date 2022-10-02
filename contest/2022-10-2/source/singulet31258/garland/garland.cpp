#include<cstdio>
#include<algorithm>
#define N 501
#define N_SQR 250000
#define SCAN for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
struct index{
	int x,y;
	bool operator<(const index&)const;
}indices[N_SQR];
int n,n_sqr,o[N][N],l[N][N],r[N][N],a[N][N];
long long s;
constexpr inline int min(const int&,const int&);
constexpr inline int max(const int&,const int&);
constexpr inline int abs(const int&,const int&);
int main(){
#ifndef ONLINE_JUDGE
	freopen("garland.in","r",stdin);
	freopen("garland.out","w",stdout);
#endif
	scanf("%d",&n);n_sqr=n*n;
	SCAN scanf("%d",o[i]+j);
	SCAN scanf("%d",l[i]+j);
	SCAN scanf("%d",r[i]+j);
	SCAN l[i][j]=l[j][i]=max(l[i][j],l[j][i]),r[i][j]=r[j][i]=min(r[i][j],r[j][i]);
	SCAN if(i==j)o[i][j]<<=1;else l[i][j]<<=1,r[i][j]<<=1;
	SCAN a[i][j]=r[i][j],s+=a[i][j];
	SCAN indices[(i-1)*n+j-1]={i,j};
	std::sort(indices,indices+n_sqr);
	for(int i=0,u;i<n_sqr;++i){
		if(s>r[indices[i].x][indices[i].y]-l[indices[i].x][indices[i].y])s-=r[indices[i].x][indices[i].y]-l[indices[i].x][indices[i].y],a[indices[i].x][indices[i].y]=l[indices[i].x][indices[i].y];
		else{
			a[indices[i].x][indices[i].y]=r[indices[i].x][indices[i].y]-s;
			if(a[indices[i].x][indices[i].y]&1){
				for(int j=1,t=0x3f3f3f3f;j<=n;++j){
					if(t>abs(o[indices[i].x][indices[i].y],o[j][j]))t=abs(o[indices[i].x][indices[i].y],o[j][j]),u=j;
				}
				if(o[indices[i].x][indices[i].y]>o[u][u])++a[indices[i].x][indices[i].y],--a[u][u];
				else--a[indices[i].x][indices[i].y],++a[u][u];
			}
			s=0;break;
		}
	}
	SCAN s+=a[i][j]*o[i][j];
	return!printf("%lld",s>>1);
}
bool index::operator<(const index& i)const{return o[x][y]<o[i.x][i.y];}
constexpr inline int min(const int& x,const int& y){return x<y?x:y;}
constexpr inline int max(const int& x,const int& y){return x>y?x:y;}
constexpr inline int abs(const int& x,const int& y){return x>y?x-y:y-x;}
