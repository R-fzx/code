#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
int n;
int x[maxn],y[maxn];
int fx[maxn][2],fy[maxn][2];
double ans;
int main(){
	freopen("seventeen.in","r",stdin);
	freopen("seventeen.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	int sumx=0,sumy=0;
	for(int i=1;i<=n;i++){
		sumx+=x[i]*x[i];
		sumy+=y[i]*y[i];
	}
	fx[1][0]=x[1],fx[1][1]=-x[1];
	fy[1][0]=y[1],fy[1][1]=-y[1];
	for(int i=2;i<=n;i++){
		if(abs(x[i]+fx[i-1][0])>abs(x[i]+fx[i-1][1]))fx[i][0]=x[i]+fx[i-1][1];
		else fx[i][0]=x[i]+fx[i-1][0];
		if(abs(-x[i]+fx[i-1][0])>abs(-x[i]+fx[i-1][1]))fx[i][1]=-x[i]+fx[i-1][1];
		else fx[i][1]=-x[i]+fx[i-1][0];
		if(abs(y[i]+fy[i-1][0])>abs(y[i]+fy[i-1][1]))fy[i][0]=y[i]+fy[i-1][1];
		else fy[i][0]=y[i]+fy[i-1][0];
		if(abs(-y[i]+fy[i-1][0])>abs(-y[i]+fy[i-1][1]))fy[i][1]=-y[i]+fy[i-1][1];
		else fy[i][1]=-y[i]+fy[i-1][0];
	}
	int xx=min(fx[n][0],fx[n][1]),yy=min(fy[n][0],fy[n][1]);
	ans=xx*xx-sumx+yy*yy-sumy;
	printf("%.2lf\n",ans/2.0);
	return 0;
}
