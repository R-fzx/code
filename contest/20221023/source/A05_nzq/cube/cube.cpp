#include<bits/stdc++.h>
using namespace std;
const int X=210,maxn=1e5+10;
int n,sum,a[X][X][X],mx,my,mz,xx,xy,xz;
int main(){
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x1,x2,y1,y2,z1,z2;
		cin>>x1>>y1>>z1;
		cin>>x2>>y2>>z2;
		x1+=100;
		x2+=100;
		y1+=100;
		y2+=100;
		z1+=100;
		z2+=100;
		mx=max(mx,x2);
		my=max(my,y2);
		mz=max(mz,z2);
		xx=min(xx,x1);
		xy=min(xy,y1);
		xz=min(xz,z1);
		for(int x=x1;x<=x2;x++){
			for(int y=y1;y<=y2;y++){
				for(int z=z1;z<=z2;z++){
					a[x][y][z]++;
				}
			}
		}
	}
	for(int i=xx;i<=mx;i++)
	for(int j=xy;j<=my;j++)
	for(int k=xz;k<=mz;k++) sum+=(a[i][j][k]>=n-1);
	cout<<sum<<endl;
	return 0;
}
