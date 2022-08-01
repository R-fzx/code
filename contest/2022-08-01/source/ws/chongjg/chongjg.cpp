#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005][5005];
int main(){
	freopen("chongjg.in","r",stdin);
	freopen("chongjg.out","w",stdout);
	cin>>n>>m;
	int nowx=1,nowy=1,lenx=n,leny=m;
	while(nowx<=n || nowy<=m){
		if(lenx>leny){
			for(int i=nowx;i<=nowx+leny-1;i++)for(int j=nowy;j<=nowy+leny-1;j++)a[i][j]=1;
			nowx+=leny;lenx-=leny;int now=((a[nowx-1][nowy]!=2 && a[nowx][nowy-1]!=2)?2:3);
			for(int i=nowy;i<=m;i++,now^=1)a[nowx][i]=now;
			nowx++;lenx--;
		}
		else if(lenx<leny){
			for(int i=nowx;i<=nowx+lenx-1;i++)for(int j=nowy;j<=nowy+lenx-1;j++)a[i][j]=1;
			nowy+=lenx;leny-=lenx;int now=((a[nowx-1][nowy]!=2 && a[nowx][nowy-1]!=2)?2:3);
			for(int i=nowx;i<=n;i++,now^=1)a[i][nowy]=now;
			nowy++;leny--;
		}
		else{
			for(int i=nowx;i<=nowx+lenx-1;i++)for(int j=nowy;j<=nowy+leny-1;j++)a[i][j]=1;
			nowx+=lenx;lenx-=lenx;nowy+=leny;leny-=leny;
		}
	}
	for(int i=1;i<=n;i++,cout<<endl)for(int j=1;j<=m;j++)cout<<(char)(a[i][j]+'A'-1);
	return 0;
}
/*
8 5
AAAAA
AAAAA
AAAAA
AAAAA
AAAAA
BCBCB
AACAA
AABAA
*/
