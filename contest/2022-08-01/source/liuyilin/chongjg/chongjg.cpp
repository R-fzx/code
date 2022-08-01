#include<bits/stdc++.h>
using namespace std;
char paint[4]="ABC";
int n,m,nn,mm;
char h[105][105];
int main(){
	freopen("chongjg.in","r",stdin);
	freopen("chongjg.out","w",stdout);
	scanf("%d%d",&n,&m);
	nn=n;mm=m;
	int u=2,l=2;
	int pt;
	while(nn&&mm){
		if(nn<=mm){
			for(int i=2;i>=0;i--)
				if(i!=u&&i!=l) pt=i;
			for(int i=n-nn+1;i<=n;i++)
				for(int j=m-mm+1;j<=m-mm+nn;j++)
					h[i][j]=paint[pt];
			l=pt;
			mm-=nn;
		}
		else{
			for(int i=2;i>=0;i--)
				if(i!=u&&i!=l) pt=i;
			for(int i=n-nn+1;i<=n-nn+mm;i++)
				for(int j=m-mm+1;j<=m;j++)
					h[i][j]=paint[pt];
			u=pt;
			nn-=mm;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<h[i][j];
		cout<<endl;
	}
	return 0;
}
