#include<bits/stdc++.h>
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
int x,n,fx[4][2]={{-1,0},{1,0},{0,-1},{0,1}},fx2[8][2]={{1,0},{0,1},{1,1},{1,-1},{-1,0},{0,-1},{-1,-1},{-1,1}};
int bj[1005][1005];//-1Îª°×£¬1ÎªºÚ
bool jf[1005][1005];
bool pd(int sx,int sy,int color)
{	bool flag=1;
	for(register int i=0;i<4;++i)
	{	int ex=sx+fx[i][0],ey=sy+fx[i][1];
		if(jf[ex][ey])continue;
		if(bj[ex][ey]==0)return 0;
		if(bj[ex][ey]==color)
		{	jf[ex][ey]=1;
			flag=min(flag,pd(ex,ey,color));
			jf[ex][ey]=0; 
		}
	}
	return flag;
}
int winner(int sx,int sy,int color,int omg)
{	int res=0;
	if(bj[sx][sy]==color)res=1;
	int ex=sx+fx2[omg-1][0],ey=sy+fx2[omg-1][1];
	if(bj[ex][ey]==color&&!jf[ex][ey])
	{	jf[ex][ey]=1;
		res+=winner(ex,ey,color,omg);
		jf[ex][ey]=0;
	}
	ex=sx+fx2[4+omg-1][0],ey=sy+fx2[4+omg-1][1];
	if(bj[ex][ey]==color&&!jf[ex][ey])
	{	jf[ex][ey]=1;
		res+=winner(ex,ey,color,omg);
		jf[ex][ey]=0;
	}
	return res;
}
void eat(int sx,int sy,int color)
{	bj[sx][sy]=0;
	for(register int i=0;i<4;++i)
	{	int ex=sx+fx[i][0],ey=sy+fx[i][1];
		if(bj[ex][ey]==color)eat(ex,ey,color);
	}
}
int main()
{	freopen("FIR.in","r",stdin);
	freopen("FIR.out","w",stdout);
	n=read(),x=read();
	for(register int i=1;i<=n;++i)
	{	int X=read(),Y=read();
		if(bj[X][Y]!=0)
		{	cout<<"illegal";
			return 0;
		}
		bj[X][Y]=(i%2==0?-1:1);
		for(register int j=0;j<4;++j)
		{	int px=X+fx[j][0],py=Y+fx[j][1];
			if(bj[px][py]!=(i%2==0?-1:1)&&bj[px][py]!=0)
			{	jf[px][py]=1;
				if(pd(px,py,bj[px][py]))eat(px,py,bj[px][py]);
				jf[px][py]=0;
			}
		}
		jf[X][Y]=1;
		if(pd(X,Y,(i%2==0?-1:1)))
		{	cout<<"illegal";
			return 0;
		}	
		jf[X][Y]=0;
		for(register int j=1;j<=4;++j)
		{	jf[X][Y]=1;
			if(winner(X,Y,(i%2==0?-1:1),j)>=x)
			{	printf(i%2==0?"Kitty ":"ITer ");
				printf("%d\n",i);
				return 0;
			}
			jf[X][Y]=0;
		}
	}
	cout<<"draw";
	return 0;
}
