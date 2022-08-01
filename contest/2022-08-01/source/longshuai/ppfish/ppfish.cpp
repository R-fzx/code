#include<bits/stdc++.h>
using namespace std;
const int N=200+5;
const int maxn=200*20+5;
int n,k,tim[N];
int nextt[maxn][26],book[maxn],cnt;
string word[N],sts;
int lsh[N];
double ans[N],p;
void build(string s,int id){
	int p=0,c;
	for(int i=0;i<s.size();i++){
		c=s[i]-'a';
		if(!nextt[p][c])nextt[p][c]=++cnt;
		p=nextt[p][c];
	}
	book[p]=id;
}
void count_time(string s){
	for(int i=0;i<s.size();i++){
		int c=s[i]-'a';
		int p=0,step=i;
		if(nextt[p][c])p=nextt[p][c];
		while(p&&step<s.size()-1){	
			if(book[p])
				tim[book[p]]++;
			step++;
			c=s[step]-'a';	
			p=nextt[p][c];
		}
		if(book[p])
			tim[book[p]]++;
	}
}
void getans(int s){
	for(int i=1;i<=s;i++)ans[i]=1.0;
	ans[1]=p;
	for(int j=2;j<=k;j++){
		for(int i=min(j,s);i>1;i--)
			ans[i]=ans[i-1]+(ans[i]-ans[i-1])*p;
		ans[1]*=p;
	}
}
int main(){
	freopen("ppfish.in","r",stdin);
	freopen("ppfish.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>word[i];
		build(word[i],i);
	}
	cin>>sts;
	count_time(sts);
	int tmp[n+1];
	for(int i=1;i<=n;i++)
		tmp[i]=tim[i];
	sort(tmp+1,tmp+1+n);
	tmp[0]=-1;
	int s=0;
	for(int i=1;i<=n;i++){
		if(tmp[i]!=tmp[i-1])s++;
		lsh[tmp[i]]=s;
	}
	scanf("%lf%d",&p,&k);
	getans(s);
	for(int i=1;i<=n;i++)
		printf("%0.3lf ",ans[lsh[tim[i]]]);
	printf("\n");
	return 0;
}
