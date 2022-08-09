#include<bits/stdc++.h>
#define re register
using namespace std;
const int N=1e3+100;
int n,m,id;
int ttx[4]={1,0,-1,0},tty[4]={0,1,0,-1};
bool f1[N][N],f2[N][N];
bool flag[N][N];
inline int read()
{
	re int x=0;
	re char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
void write(re int x)
{
	if(x>=10)write(x/10);
	putchar(x%10+48);
}
bool remove1(re int x,re int y)
{
	re int i;
	flag[x][y]=true;
	bool tt[4]={false,false,false,false};
	for(i=0; i<=3; i++)
	{
		if(flag[x+ttx[i]][y+tty[i]]){tt[i]=true;continue;}
		if(!f1[x+ttx[i]][y+tty[i]]&&!f2[x+ttx[i]][y+tty[i]])return false;
		if(f1[x+ttx[i]][y+tty[i]])tt[i]=remove1(x+ttx[i],y+tty[i]);
		if(f2[x+ttx[i]][y+tty[i]])tt[i]=true;
	}
	for(i=0; i<=3; i++)
		if(!tt[i])break;
	if(i==4)f1[x][y]=false;
	return (i==4);
}
bool remove2(re int x,re int y)
{
	re int i;
	flag[x][y]=true;
	bool tt[4]={false,false,false,false};
	for(i=0; i<=3; i++)
	{
		if(flag[x+ttx[i]][y+tty[i]]){tt[i]=true;continue;}
		if(!f1[x+ttx[i]][y+tty[i]]&&!f2[x+ttx[i]][y+tty[i]])return false;
		if(f2[x+ttx[i]][y+tty[i]])tt[i]=remove2(x+ttx[i],y+tty[i]);
		if(f1[x+ttx[i]][y+tty[i]])tt[i]=true;
	}
	for(i=0; i<=3; i++)
		if(!tt[i])break;
	if(i==4)f2[x][y]=false;
	return (i==4);
}
bool check1(re int x,re int y)
{
	re int i;
	flag[x][y]=true;
	bool tt[4]={false,false,false,false};
	for(i=0; i<=3; i++)
	{
		if(flag[x+ttx[i]][y+tty[i]]){tt[i]=true;continue;}
		if(!f1[x+ttx[i]][y+tty[i]]&&!f2[x+ttx[i]][y+tty[i]])return false;
		if(f1[x+ttx[i]][y+tty[i]])tt[i]=check1(x+ttx[i],y+tty[i]);
		if(f2[x+ttx[i]][y+tty[i]])tt[i]=true;
	}
	for(i=0; i<=3; i++)
		if(!tt[i])break;
	return (i==4);
}
bool check2(re int x,re int y)
{
	re int i;
	flag[x][y]=true;
	bool tt[4]={false,false,false,false};
	for(i=0; i<=3; i++)
	{
		if(flag[x+ttx[i]][y+tty[i]]){tt[i]=true;continue;}
		if(!f1[x+ttx[i]][y+tty[i]]&&!f2[x+ttx[i]][y+tty[i]])return false;
		if(f2[x+ttx[i]][y+tty[i]])tt[i]=check2(x+ttx[i],y+tty[i]);
		if(f1[x+ttx[i]][y+tty[i]])tt[i]=true;
	}
	for(i=0; i<=3; i++)
		if(!tt[i])break;
	return (i==4);
}
inline bool solve(re int x,re int y)
{
	if(id%2)f1[x][y]=true;
	else f2[x][y]=true;
	re int step;
	if(id%2)
	{
		memset(flag,0,sizeof(flag));
		for(re int i=0; i<4; i++)
			if(f2[x+ttx[i]][y+tty[i]])remove2(x+ttx[i],y+tty[i]);
		memset(flag,0,sizeof(flag));
		if(check1(x,y)){puts("illegal");return true;}
		step=0;
		for(re int i=x; f1[i][y]; i++)step++;
		for(re int i=x-1; f1[i][y]; i--)step++;
		if(step>=m){
			putchar('I'),putchar('T'),putchar('e'),putchar('r'),putchar(' ');
			write(id);
			return true;
		}
		step=0;
		for(re int j=y; f1[x][j]; j++)step++;
		for(re int j=y-1; f1[x][j]; j--)step++;
		if(step>=m){
			putchar('I'),putchar('T'),putchar('e'),putchar('r'),putchar(' ');
			write(id);
			return true;
		}
		step=0;
		for(re int i=x,j=y; f1[i][j]; i++,j++)step++;
		for(re int i=x-1,j=y-1; f1[i][j]; i--,j--)step++;
		if(step>=m){
			putchar('I'),putchar('T'),putchar('e'),putchar('r'),putchar(' ');
			write(id);
			return true;
		}
		step=0;
		for(re int i=x,j=y; f1[i][j]; i++,j--)step++;
		for(re int i=x-1,j=y+1; f1[i][j]; i--,j++)step++;
		if(step>=m){
			putchar('I'),putchar('T'),putchar('e'),putchar('r'),putchar(' ');
			write(id);
			return true;
		}
	}
	else
	{
		memset(flag,0,sizeof(flag));
		for(re int i=0; i<4; i++)
			if(f1[x+ttx[i]][y+tty[i]])remove1(x+ttx[i],y+tty[i]);
		memset(flag,0,sizeof(flag));
		if(check2(x,y)){puts("illegal");return true;}
		step=0;
		for(re int i=x; f2[i][y]; i++)step++;
		for(re int i=x-1; f2[i][y]; i--)step++;
		if(step>=m){
			putchar('K'),putchar('i'),putchar('t'),putchar('t'),putchar('y'),putchar(' ');
			write(id);
			return true;
		}
		step=0;
		for(re int j=y; f2[x][j]; j++)step++;
		for(re int j=y-1; f2[x][j]; j--)step++;
		if(step>=m){
			putchar('K'),putchar('i'),putchar('t'),putchar('t'),putchar('y'),putchar(' ');
			write(id);
			return true;
		}
		step=0;
		for(re int i=x,j=y; f2[i][j]; i++,j++)step++;
		for(re int i=x-1,j=y-1; f2[i][j]; i--,j--)step++;
		if(step>=m){
			putchar('K'),putchar('i'),putchar('t'),putchar('t'),putchar('y'),putchar(' ');
			write(id);
			return true;
		}
		step=0;
		for(re int i=x,j=y; f2[i][j]; i++,j--)step++;
		for(re int i=x-1,j=y+1; f2[i][j]; i--,j++)step++;
		if(step>=m){
			putchar('K'),putchar('i'),putchar('t'),putchar('t'),putchar('y'),putchar(' ');
			write(id);
			return true;
		}
	}
	return false;
}
signed main()
{
	freopen("FIR.in","r",stdin);
	freopen("FIR.out","w",stdout);
	n=read(),m=read();
	re int x,y;
	for(id=1; id<=n; id++)
	{
		x=read(),y=read();
		if(f1[x][y]||f2[x][y]){puts("illegal");return 0;}
		if(solve(x,y))return 0;
	}
	puts("draw");
	return 0;
}
