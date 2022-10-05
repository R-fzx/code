#include<bits/stdc++.h>
#define int long long
//#define double long double
#define gt getchar
using namespace std;
int read(){
	int x=0,f=1;
	char ch=gt();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gt();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return x*f;
}
struct point{
	double x,y;
};
struct line{
	double k,b;
};
const int N=1e5+100;
double eps=1e-5;
point a[N];
int n,ans;
int A,B,C,D,M;
line jxs(point x,point y){
	return (line){1.0*(x.y-y.y)/(x.x-y.x),y.y-(y.x*1.0*(x.y-y.y)/(x.x-y.x))};
}
point qjd(line x,line y){
	return (point){1.0*(y.b-x.b)/(x.k-y.k),x.k*1.0*(y.b-x.b)/(x.k-y.k)+x.b};
}
bool check(int i,int j,int k){
	double x=a[i].x,y=a[i].y,x2=a[j].x,y2=a[j].y,x3=a[k].x,y3=a[k].y;
	point z1=(point){1.0*(x+x2)/2,1.0*(y+y2)/2},z2=(point){1.0*(x3+x2)/2,1.0*(y3+y2)/2};
	line p1=jxs(z1,(point){x3,y3}),p2=jxs(z2,(point){x,y});
	point jd=qjd(p1,p2);
	double xx=jd.x,yy=jd.y;
	int xxx=(long long)(xx+0.5),yyy=(long long)(yy+0.5);
	if(fabs(xxx-xx)<eps&&fabs(yyy-yy)<eps)return 1;
	return 0;
}
signed main(){
	freopen("crop.in","r",stdin);
	freopen("crop.out","w",stdout);
	n=read(),a[1].x=read(),a[1].y=read(),A=read(),B=read(),C=read(),D=read(),M=read();
	for(int i=2;i<=n;i++){
		a[i].x=double((long long)(A*a[i-1].x+B)%M);
		a[i].y=double((long long)(C*a[i-1].y+D)%M);
	}
	for(int i=1;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<=n;k++)
				ans+=check(i,j,k);
	cout<<ans;
	return 0;
}

