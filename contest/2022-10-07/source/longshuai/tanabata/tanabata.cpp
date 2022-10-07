#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m,k;
int r[maxn<<1],c[maxn<<1];
long long row(){
	long long ans=0,sum=1e15;
	int tmp[maxn<<1];
	for(int i=1;i<=n;i++)tmp[i]=tmp[i+n]=r[i]=r[i+n]=r[i]-k/n;
	for(int j=1;j<=n;j++){
		for(int i=j;i<j+n;i++)r[i]=tmp[i];
		queue<int> q;ans=0;
//		cout<<endl;
		for(int i=j;i<j+n;i++){
//			cout<<r[i]<<' ';
			if(r[i]<0){
				while(r[i]<0&&!q.empty()&&r[q.front()]>0){
					int t=q.front();
					if(r[i]+r[t]>0){
						r[t]+=r[i];
						ans+=(-r[i])*(i-t);
						r[i]=0;
					}else{
						ans+=r[t]*(i-t);
						r[i]+=r[t];
						q.pop();
					}
				}
				if(q.empty()&&r[i]<0)q.push(i);
			}else if(r[i]>0){
				while(r[i]>0&&!q.empty()&&r[q.front()]<0){
					int t=q.front();
					if(r[i]+r[t]>=0){
						r[i]+=r[t];
						ans+=(-r[t])*(i-t);
						q.pop();
					}else{
						r[t]+=r[i];
						ans+=r[i]*(i-t);
						r[i]=0;
					}
				}
				if(q.empty()&&r[i]>0)q.push(i);
			}
		}
		sum=min(sum,ans);
	}
//	cout<<sum<<endl;
	return sum;
}
long long column(){
	long long ans=0,sum=1e15;
	int tmp[maxn<<1];
	for(int i=1;i<=m;i++)tmp[i]=tmp[i+m]=c[i]=c[i+m]=c[i]-k/m;
	for(int j=1;j<=m;j++){
		for(int i=j;i<j+m;i++)c[i]=tmp[i];
		queue<int> q;ans=0;
		for(int i=j;i<j+m;i++){
			if(c[i]<0){
				while(c[i]<0&&!q.empty()&&c[q.front()]>0){
					int t=q.front();
					if(c[i]+c[t]>0){
						c[t]+=c[i];
						ans+=(-c[i])*(i-t);
						c[i]=0;
					}else{
						ans+=c[t]*(i-t);
						c[i]+=c[t];
						q.pop();
					}
				}
				if(q.empty()&&c[i]<0)q.push(i);
			}else if(c[i]>0){
				while(c[i]>0&&!q.empty()&&c[q.front()]<0){
					int t=q.front();
					if(c[i]+c[t]>=0){
						c[i]+=c[t];
						ans+=(-c[t])*(i-t);
						q.pop();
					}else{
						c[t]+=c[i];
						ans+=c[i]*(i-t);
						c[i]=0;
					}
				}
				if(q.empty()&&c[i]>0)q.push(i);
			}
//			cout<<ans<<endl;
		}
		sum=min(sum,ans);
	}
	return sum;
}
long long both(){
	return row()+column();
}
int main(){
	freopen("tanabata.in","r",stdin);
	freopen("tanabata.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		r[a]++;c[b]++;
	}
	if(k%n==0&&k%m==0){
		printf("both %lld\n",both());
		return 0;
	}
	if(k%n==0){
		printf("row %lld\n",row());
		return 0;
	}
	if(k%m==0){
		printf("column %lld\n",column());
		return 0;
	}
	printf("impossible\n");
	return 0;
}
