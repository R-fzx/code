#include<stdio.h>
#include<stdlib.h>
void Read();
void Count();
void Write();
int main()
{
	freopen("Metamorphosis.in","r",stdin);
	freopen("Metamorphosis.out","w",stdout);
	Read();
	Count();
	Write();
	//system("pause");
	return 0;
}

int min_x,min_y,max_x,max_y;
void Read()
{
	scanf("%d%d%d%d",&min_x,&min_y,&max_x,&max_y);
	return;
}

double ans;
struct POINT{int x,y;}flag[5]={0};
inline struct POINT operator *(struct POINT p,int l){	p.x*=l,p.y*=l;return p;		}
inline struct POINT operator /(struct POINT p,int l){	p.x/=l,p.y/=l;return p;		}
inline struct POINT operator +(struct POINT a,struct POINT b){struct POINT c={a.x+b.x,a.y+b.y};return c;	}
inline int Min(int x,int y){	if(x<y)	return x;else return y;}
inline int Max(int x,int y){	if(x>y)	return x;else return y;}
inline void Cheak(struct POINT p,int f,int dist)
{
	int v=0;
	struct POINT k={0};
	if(f>1)		k=p,p=k+flag[f]*dist;
	else		k=p+flag[f]*dist;
	f&=1;
	if(!f && p.x<=max_x && p.x>=min_x )
		v=Min( max_y, k.y ) - Max( min_y, p.y);
	else if( f && p.y<=max_y && p.y>=min_y )
		v=Min( max_x, k.x ) - Max( min_x, p.x);
		
	if( v>0 )	ans+=v;
	return;
}

void Dfs(int deep,struct POINT p,int f,int dist)
{
	if(deep)
	{
		Cheak(p,f,dist*2/3);
		struct POINT c=p+flag[f]*dist*2/3;
		Dfs(deep-1,c,  f,    dist/3);
		Dfs(deep-1,c,(f+1)&3,dist/3);
		Dfs(deep-1,c,(f+3)&3,dist/3);
	}
	else
	{
		struct POINT k={0};
		if(f>1)		k=p,p=k+flag[f]*dist;
		else		k=p+flag[f]*dist;
		f&=1;
		if(!f)
			if( p.y>=max_y || k.y<=min_y || p.x>max_x || p.x<min_x )	return;
			else if( min_x<p.x && p.x<max_x )	ans+= 1.0 + 495*2.0/3;
			//else if( min_x==p.x && p.x==max_x)	ans+= 1.0;
			else								ans+= 1.0 + 495.0/3;
		else
			if( p.x>=max_x || k.x<=min_x || p.y>max_y || p.y<min_y )	return;
			else if( min_y<p.y && p.y<max_y )	ans+= 1.0 + 495*2.0/3;
			//else if( min_y==p.y && p.y==max_y)	ans+= 1.0;
			else								ans+= 1.0 + 495.0/3;
	}	
	return;
}

void Count()
{
	flag[0].x=0, flag[0].y=1 ;
	flag[1].x=1, flag[1].y=0 ;
	flag[2].x=0, flag[2].y=-1;
	flag[3].x=-1,flag[3].y=0 ;
	struct POINT star={0};
	Dfs(4,star,0,81);
	return;
}

void Write()
{
	printf("%.1lf\n",ans);
	return;
}

