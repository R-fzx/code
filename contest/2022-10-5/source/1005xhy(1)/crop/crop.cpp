#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
const int N=1e5+3;
int n,a,b,c,d,m,xx,yy,ans;
double zx[3],zy[3],tx,ty;
double k1,k2,b1,b2;
struct node{
	double x,y;
	bool operator<(const node &tmp)
	const {return x*y<tmp.x*tmp.y;}
}nd[N];
inline char gt()
{
    static char buf[1000000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
	re int x=0;
	re char ch=gt();
	while(ch<48||ch>57)ch=gt();
	while(ch>=48&&ch<=57)x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return x;
} 
inline void write(re int x)
{
	if(x>9)write(x/10);
	putchar(x%10+48);
}
signed main()
{
	freopen("crop.in","r",stdin);
	freopen("crop.out","w",stdout);
	n=read(),a=read(),b=read(),c=read(),d=read(),nd[1].x=xx=read(),nd[1].y=yy=read(),m=read();
	for(re int i=2; i<=n; i++)
		xx=(a*xx+b)%m,yy=(c*yy+d)%m,nd[i].x=xx,nd[i].y=yy;
	for(re int i=1; i<=n; i++)
		for(re int j=i+1; j<=n; j++)
			for(re int k=j+1; k<=n; k++)
			{
				zx[0]=1.0*(nd[i].x+nd[j].x)/2,zy[0]=1.0*(nd[i].y+nd[j].y)/2;
				zx[1]=1.0*(nd[i].x+nd[k].x)/2,zy[1]=1.0*(nd[i].y+nd[k].y)/2;
				k1=1.0*(nd[k].y-zy[0])/(nd[k].x-zx[0]);
				k2=1.0*(nd[j].y-zy[1])/(nd[j].x-zx[1]);
				b1=zy[0]-zx[0]*k1,b2=zy[1]-zx[1]*k2;
				tx=(b2-b1)/(k1-k2),ty=k1*tx+b1;
				xx=(long long)(tx+0.5),yy=(long long)(ty+0.5);
				if(fabs(xx-tx)==0&&fabs(yy-ty)==0)ans++;
			}
	write(ans);
	return 0;
}
