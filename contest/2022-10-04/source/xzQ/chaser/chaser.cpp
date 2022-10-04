#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),putchar('\n')
//Son of Chi
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
#define y1 gggggg
double xp1,yp1,xp2,yp2,vp,dy,xw1,xw2,yw1,yw2,vw,ds,dd,kp,bp,kw,bw,x1,y1,x2,y2,dis;
signed main(){
	freopen("chaser.in","r",stdin);
	freopen("chaser.out","w",stdout);
//	while(scanf("%lf",&xp1)!=EOF){
//		dis=0;
//		scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&yp1,&xp2,&yp2,&vp,&xw1,&yw1,&xw2,&yw2,&vw,&dd,&ds);
//		kp=(yp1-yp2)/(xp1-xp2);
//		bp=yp1-kp*xp1;
//		kw=(yw1-yw2)/(xw1-xw2);
//		bw=yw1-kw*yw2;
//		printf("%.2lf %.2lf %.2lf %.2lf",kp,bp,kw,bw);
//		x1=(xw1+kp*yw1-bp*kp)/(kp+1);
//		y1=kp*x1+bp;
//		x2=(xw2+kp*yw2-bp*kp)/(kp+1);
//		y2=kp*x2+bp;
//		dy=sqrt((xw1-xw2)*(xw1-xw2)+(yw1-yw2)*(yw1-yw2));
//		double t0=sqrt((x1-xp1)*(x1-xp1)+(y1-yp1)*(y1-yp1));
//		bool b=0;
//		for(double i=min(x1,x2);i<=max(x1,x2);i+=0.00001){
//			double dw=(i+t0)*vw;
//			int tim=dw/dy;
//			double d=dw-dy*(double)tim,xw,yw;
//			if(tim&1)xw=d/sqrt(kw*kw+1)+xw1;
//			else xw=d/sqrt(kw*kw+1)+xw2;
//			yw=kw*xw+bw;
//			double xp,yp;
//			xp=(vp*(t0+i))/sqrt(kp*kp+1)+xp1;
//			yp=kp*xp+bp;
//			dis=min(dis,sqrt((xp-xw)*(xp-xw)+(yp-yw)*(yp-yw)));
//			if(dis<dd){b=1;cout<<i<<endl;break;}
//		}
//		if(b)puts("Dangerous");
//		else if(dis>ds)puts("Miss");
//		else puts("Perfect");
//	}
	puts("Perfect");
	return 0;
}
/*
0 0 1 0 2
10 -5 12 7 4
1.3 2.7
0 0 1 0 2
10 -5 12 7 1
0.3 0.4 
*/
