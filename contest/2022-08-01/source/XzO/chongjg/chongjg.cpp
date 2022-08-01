//fuck ccf
//fuck ccf
//fuck ccf
//fuck ccf
//fuck ccf
//fuck ccf
//fuck ccf
//fuck ccf
//fuck ccf
//fuck ccf
//fuck ccf
//fuck ccf
//fuck ccf

#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0)x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
int n,m,len[29],cnt=0;
char ans[1009][1009];
void work(int x,int y,int begx,int begy){
	char ch='%';
	for(int i=1;i<=27;i++)
		if(min(x,y)==len[i]&&ans[begx-1][begy]!='A'+i-1&&ans[begx][begy-1]!='A'+i-1){ch='A'+i-1;break;}
	if(ch=='%'){
		len[++cnt]=min(x,y);
		ch='A'+cnt-1;
	}
	for(int i=begx;i<=begx+min(x,y)-1;i++)
		for(int j=begy;j<=begy+min(x,y)-1;j++){
			ans[i][j]=ch;
		}
	if(x==y)return;
	if(x>y)work(x-y,y,begx+y,begy);
	if(x<y)work(x,y-x,begx,begy+x);
	return;
}
int main(){
	freopen("chongjg.in","r",stdin);
	freopen("chongjg.out","w",stdout);
	n=read(),m=read();
	work(n,m,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)putchar(ans[i][j]);
		putchar('\n');
	}
	return 0;
}
