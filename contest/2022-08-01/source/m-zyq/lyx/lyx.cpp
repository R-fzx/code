#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int n,m,ans,w[100009],id[100009],od[100009];
vector<int>v[100009];
queue<int>q;//ЩњВњеп
inline int read(){
	int r(0);char ch(getchar());
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch<='9'&&ch>='0')r=(r<<3)+(r<<1)+ch-'0',ch=getchar();
	return r;
}
inline int f(int num){
	if(w[num])return w[num];
	int sum(0);
	for(int i(0);i<v[num].size();i++)sum+=f(v[num][i]);
	return w[num]=sum;
}
signed main(){
	freopen("lyx.in","r",stdin),freopen("lyx.out","w",stdout);
	n=read(),m=read();
	for(int a,b;m--;){
		a=read(),b=read();
		v[a].push_back(b),id[b]++,od[a]++;
	}
	for(int i(1);i<=n;i++)if(!od[i])w[i]=1;
	for(int i(1);i<=n;i++)if(!id[i])q.push(i);
	for(;!q.empty();){
		ans+=f(q.front());
		q.pop();
	}
	cout<<ans;
	getch();
	return 0;
}

