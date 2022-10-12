#include<stdio.h>

int x1,y1,x2,y2;
int answer;
int out;

int line_long(int xa,int ya,int xb,int yb);
inline int dist(int xa,int ya,int xb,int yb);

int min(int a,int b)
{
	return a<b?a:b;
}

int max(int a,int b)
{
	return a>b?a:b;
}

double fabs(double a)
{
	if(a>0)return a;
	else return -a;
}

int fabs(int a)
{
	if(a>0)return a;
	else return -a;
}

int same(int a,int b)
{
	return a==b;
}

void init()
{
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	//printf("%d %d %d %d\n",x1,y1,x2,y2);
	if(x1>x2)
	{
		int t=x1;x1=x2;x2=t;
	}
	if(y1>y2)
	{
		int t=y1;y1=y2;y2=t;
	}
}

double ans(int time,int t)
{
	return double(t)+double(time-1)*t*2.0/3.0;
}

inline int check_v(int xa,int ya)
{//printf("%d %d\n",x1,y1);
	//return xa>=x1&&xa<=x2&&ya>=y1&&ya<=y2;
	if(xa<x1)return 0;
	if(xa>x2)return 0;
	if(y1>ya)return 0;
	if(ya>y2)return 0;
	return 1;
}

inline int check_line(int xa,int ya,int xb,int yb)
{
	//printf("%d %d\n",check_v(xa,ya),check_v(xb,yb));
	return check_v(xa,ya)&&check_v(xb,yb);
}

double doit(int xa,int ya,int xb,int yb)
{
	//printf("%d %d %d %d %lf\n",xa,ya,xb,yb,ans(496,1)*81);
	if(xa>xb)
	{
		int t=xa;xa=xb;xb=t;
	}
	if(ya>yb)
	{
		int t=ya;ya=yb;yb=t;
	}
	if(!check_line(xa,ya,xb,yb))
	{
		return 0;
	}
	//printf("%d %d %d %d\n",xa,ya,xb,yb);
	if((xa==xb&&(xa==x1||xa==x2))||(ya==yb&&(ya==y1||ya==y2)))
		return (ans(496,1)-1)/2+1;
	//printf("%d %d %d %d\n",xa,ya,xb,yb);
	return ans(496,1);
}

double work(int xa,int ya,int xb,int yb,int time)
{
	//printf("%d %d %d %d\n",xa,ya,xb,yb);
	if(time==5)
	{//return 0;
		return doit(xa,ya,xb,yb);
	}
	double tot=0;
	if(xa==xb)
	{
		int ny=ya+(yb-ya)*2/3;
		int l=fabs(yb-ya)/3;
		tot+=work(xa,ny,xb,yb,time+1);
		tot+=work(xa,ny,xb-l,ny,time+1);
		tot+=work(xa,ny,xb+l,ny,time+1);
		//printf("%d %d %d %d %d\n",xa,ya,xb,ny,dist(xa,ya,xb,ny));
		tot+=(long long)dist(xa,ya,xb,ny);
		//if(dist(xa,ya,xb,ny))
		//	printf("%d %d %d %d %d\n",xa,ya,xb,ny,dist(xa,ya,xb,ny));
	}else if(ya==yb)
	{
		int nx=(xb-xa)*2/3+xa;
		int l=fabs(xb-xa)/3;
		tot+=work(nx,ya,xb,yb,time+1);
		tot+=work(nx,ya,nx,yb+l,time+1);
		tot+=work(nx,ya,nx,yb-l,time+1);
		//if(dist(xa,ya,nx,yb))
		//	printf("%d %d %d %d %d\n",xa,ya,nx,yb,dist(xa,ya,nx,yb));
		//printf("%d %d %d %d %d\n",xa,ya,nx,yb,dist(xa,ya,nx,yb));
		tot+=(long long)dist(xa,ya,nx,yb);
	}
	tot=fabs(tot);
	return tot;
}

int main()
{
	freopen("Metamorphosis.in","r",stdin);
	freopen("Metamorphosis.out","w",stdout);
	init();
	//printf("%d %d %d %d\n",x1,y1,x2,y2);
	printf("%.1llf\n",fabs(work(0,0,0,81,1)));
	//printf("%lf",ans(500,81));
}

int line_long(int xa,int ya,int xb,int yb)
{
	if(same(xa,xb))return fabs(yb-ya);
	if(same(ya,yb))return fabs(xb-xa);
}

inline int dist(int xa,int ya,int xb,int yb)
{
	int t=0;
	if(xa>xb)
	{
		t=xa;xa=xb;xb=t;
	}
	if(ya>yb)
	{
		t=ya;ya=yb;yb=t;
	}
	int dis=0;
	if(ya==yb&&ya>=y1&&yb<=y2)
	{
		return max(min(xb,x2)-max(xa,x1),0);
	}	
	if(xa==xb&&xa>=x1&&xb<=x2)
	{
		return max(min(yb,y2)-max(ya,y1),0);	
	}
	return 0;
}
