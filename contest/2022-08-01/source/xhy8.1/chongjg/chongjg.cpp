#include<bits/stdc++.h>
#define re register
using namespace std;
const int NM=110;
char ch[NM][NM];
bool p[3];
int n,m,ii,jj;
inline int read()
{
	re int x=0;
	re char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+ch-48,ch=getchar(); 
	return x;
}
inline void cchh(int k,char cc)
{
	re int a=ii+1,b=jj+1,c=ii+k,d=jj+k;
	for(int i=a; i<=c; i++)
		for(int j=b; j<=d; j++)
			ch[i][j]=cc;
	return;
}
inline char chen(int k)
{
	p[0]=p[1]=p[2]=false; 
	int a=ii,b=jj,c=ii+k+1,d=jj+k+1;
	for(re int i=a+1; i<=c-1; i++)
		p[ch[i][b]-'A']=p[ch[i][d]-'A']=true;
	for(re int j=b+1; j<=d-1; j++)
		p[ch[a][j]-'A']=p[ch[c][j]-'A']=true;
	for(re int i=0; i<3; i++)if(!p[i])return char(i+'A');
	return char(3+'A');
}
void solve(int x,int y)
{
	int k=min(x,y);
	if(x<y)k=x;
	else k=y;
	cchh(k,chen(k));
	if(x==y)return;
	if(x<y)jj+=k,solve(x,y-k);
	else ii+=k,solve(x-k,y);
}
int main()
{
	freopen("chongjg.in","r",stdin);
	freopen("chongjg.out","w",stdout);
	n=read(),m=read();
	solve(n,m);
	for(re int i=1; i<=n; i++)
	{
		for(re int j=1; j<=m; j++)
			putchar(ch[i][j]);
		puts("");
	}
	return 0;
}
