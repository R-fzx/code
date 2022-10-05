#include<bits/stdc++.h>
#define int long long
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
int n,A,B,C,D,x,y,M,ms[5][5],fk[15][2]={{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}},ans;
signed main()
{	freopen("crop.in","r",stdin);
	freopen("crop.out","w",stdout);
	n=read(),A=read(),B=read(),C=read(),D=read(),x=read(),y=read(),M=read();
	ms[x%3][y%3]++;
	for(register int i=1;i<n;++i)
	{	x=(A*x+B)%M;
		y=(C*y+D)%M;
		ms[x%3][y%3]++;
	}
	for(register int i=0;i<9;++i)
		for(register int j=i;j<9;++j)
			for(register int k=j;k<9;++k)
				if((fk[i][0]+fk[j][0]+fk[k][0])%3==0&&(fk[i][1]+fk[j][1]+fk[k][1])%3==0)
				{	if(i==j&&j==k)ans+=ms[fk[i][0]][fk[i][1]]*(ms[fk[i][0]][fk[i][1]]-1)*(ms[fk[i][0]][fk[i][1]]-2)/3/2;
					else if(i==j)ans+=ms[fk[i][0]][fk[i][1]]*(ms[fk[i][0]][fk[i][1]]-1)/2*ms[fk[k][0]][fk[k][1]];
					else if(j==k)ans+=ms[fk[j][0]][fk[j][1]]*(ms[fk[j][0]][fk[j][1]]-1)/2*ms[fk[i][0]][fk[i][1]];
					else if(i==k)ans+=ms[fk[i][0]][fk[i][1]]*(ms[fk[i][0]][fk[i][1]]-1)/2*ms[fk[j][0]][fk[j][1]];
					else ans+=ms[fk[i][0]][fk[i][1]]*ms[fk[j][0]][fk[j][1]]*ms[fk[k][0]][fk[k][1]];
				}
	cout<<ans;
	return 0;
}

