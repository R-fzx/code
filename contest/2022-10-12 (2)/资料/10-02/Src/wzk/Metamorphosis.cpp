#include <stdio.h>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define To0(a) (a)>0?(a):0
#define Debug 0
int x1,y1,x2,y2;
int ans;
void dfs(int x,int y,int a,int b,int task)
{
	int i,j;
	if(task==5)
	{
		if((x1<x&&x<x2&&y1<y&&y<y2)||(x1<x+a&&x+a<x2&&y1<y+b&&y+b<y2)||(x==x1&&x+a==x2&&y1<y&&y<y2)||(x==x2&&x+a==x1&&y1<y&&y<y2)||(y==y1&&y+b==y2&&x1<x&&x<x2)||(y==y2&&y+b==y1&&x1<x&&x<x2))
			ans+=331;
		else if((x1==x&&x+a==x2&&y<=y2&&y>=y1&&y+b<=y2&&y+b>=y1)||(x2==x&&x+a==x1&&y<=y2&&y>=y1&&y+b<=y2&&y+b>=y1)||(y1==y&&y+b==y2&&x<=x2&&x>=x1&&x+a<=x2&&x+a>=x1)||(y2==y&&y+b==y1&&x<=x2&&x>=x1&&x+a<=x2&&x+a>=x1))
			ans+=166;
		return;
	}
	if(a==0)
	{
		if(b>0&&x1<=x&&x<=x2)
			ans+=To0(Min(y2,y+b*2/3)-Max(y1,y));
		if(b<0&&x1<=x&&x<=x2) 
			ans+=To0(Min(y2,y)-Max(y1,y+b*2/3));
	}
	if(b==0)
	{
		if(a>0&&y1<=y&&y<=y2)
			ans+=To0(Min(x2,x+a*2/3)-Max(x1,x));
		if(a<0&&y1<=y&&y<=y2)
			ans+=To0(Min(x2,x)-Max(x1,x+a*2/3));	
	}
	dfs(x+a*2/3,y+b*2/3,a/3,b/3,task+1);
	dfs(x+a*2/3,y+b*2/3,-b/3,-a/3,task+1);
	dfs(x+a*2/3,y+b*2/3,b/3,a/3,task+1);
}

#define OpenFile 0
int main()
{
	#if OpenFile
	freopen("Metamorphosis.in","r",stdin);
	freopen("Metamorphosis.out","w",stdout);
	#endif
	int i,j;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	if(x1>x2)
	{
		int t;
		t=x1;
		x1=x2;
		x2=t;
	}
	if(y1>y2)
	{
		int t;
		t=y1;
		y1=y2;
		y2=t;
	}
	dfs(0,0,0,81,1);
	printf("%d.0\n",ans);
	return 0;
}
