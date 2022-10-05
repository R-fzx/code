/*风向事先确定，如果风向相反需要3天，否则一步只需1天，问最坏情况要多少天能到达绿洲。
f[i][j]
每次决策时有2种选择，一种选最好的+3,一种选次好的+1，倒推sssp即可。

(出题）
*/
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <complex> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <cassert> 
using namespace std;

const int dx[8]={1,1,1,-1,-1,-1,0,0};
const int dy[8]={1,0,-1,1,0,-1,1,-1};
const int maxn=60;

int ex,ey,d[maxn][maxn],n,m,flg,n1,n2;
char g[maxn][maxn];

int ok(int x,int y){
	if((x<0)||(x>n-1)||(y<0)||(y>m-1))return 0;
	return 1;
}
int work(){
	int i,j;

	scanf("%d",&n);gets(g[0]);
	for(i=0;i<n;i++)gets(g[i]);
	m=strlen(g[0]);
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	d[i][j]=10000;
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	if(g[i][j]=='*')d[i][j]=0;else
	if(g[i][j]=='@'){ex=i;ey=j;}
	
	flg=1;
	while(flg){
		flg=0;
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		if((d[i][j])&&(g[i][j]!='X')){
			n1=10000;n2=10000;
			for(int k=0;k<8;k++)
			if(ok(i+dx[k],j+dy[k])){
				if(d[i+dx[k]][j+dy[k]]<n1){
					n2=n1;
					n1=d[i+dx[k]][j+dy[k]];
				}else if(d[i+dx[k]][j+dy[k]]<n2)
					n2=d[i+dx[k]][j+dy[k]];
			}
			int t=min(n1+3,n2+1);
			if(t<d[i][j]){
				d[i][j]=t;
				flg=1;
			}
		}
	}
	if(d[ex][ey]==10000)d[ex][ey]=-1;
	return d[ex][ey];
}

int main(){
	freopen("desert.in","r",stdin);
	freopen("desert.out","w",stdout);
	cout<<work()<<endl;	
	return 0;
}

