#include<iostream>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int maxn=100005;
int n,m,mx,mxcnt;
int cnt[maxn];

int main(){
	freopen("vote.in","r",stdin);
	freopen("vote.out","w",stdout);
	scanf("%d%d",&n,&m);
	REP(i,m){
		int x;scanf("%d",&x);
		cnt[x]++;
	}
	mx=0;
	REP(i,n){
		if(cnt[i]>mx)mx=cnt[i],mxcnt=1;
		else if(cnt[i]==mx)mxcnt++;
	}
	if(mx<=1){
		puts("0.0000");
		return 0;
	}
	cerr<<mxcnt<<endl;
	int cur=mxcnt;
	while(cur){
		if(cur==1)break;
		if(n%cur==0){
			puts("0.0000");
			return 0;
		}
		cur=n%cur;
	}
	printf("%.4lf\n",1.0/db(mxcnt));
	return 0;
}
