#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=210;
int n,ans;
int a[M][M][M];
int main(){
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x0,y0,z0,x1,y1,z1;
		scanf("%d%d%d%d%d%d",&x0,&y0,&z0,&x1,&y1,&z1);
		x0+=60;y0+=60;z0+=60;x1+=60;y1+=60;z1+=60;
		for(int k=z0;k<=z1;k++){
			a[x0][y0][k]++;
			a[x0][y1+1][k]--;
			a[x1+1][y0][k]--;
			a[x1+1][y1+1][k]++;
		}
//		for(int j=x0;j<=x1;j++){
//			for(int k=y0;k<=y1;k++){
//				for(int o=z0;o<=z1;o++){
//					a[j][k][o]++;
//				}
//			}
//		}
	}
//	for(int k=0;k<=111;k++){
//		for(int i=0;i<=111;i++){
//			for(int j=0;j<=111;j++){
//				cout<<a[i][j][k]<<" ";
////				ans+=a[i][j][k];
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//	}
	for(int k=0;k<=120;k++){
		for(int i=1;i<=120;i++){
			for(int j=1;j<=120;j++){
				a[i][j][k]+=a[i-1][j][k]+a[i][j-1][k]-a[i-1][j-1][k];
			}
		}
	}
	
	for(int k=0;k<=120;k++){
		for(int i=0;i<=120;i++){
			for(int j=0;j<=120;j++){
//				cout<<a[i][j][k]<<" ";
				if(a[i][j][k]>=n-1)ans++;
			}
//			cout<<endl;
		}
//		cout<<endl;
	}
	cout<<ans;



	return 0;
}

