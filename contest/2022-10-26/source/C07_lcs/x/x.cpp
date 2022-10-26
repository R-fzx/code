#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int x,y;
}a[100005];
bool cmp(node x,node y){return x.x<y.x;}
struct que{
	int x,y,tot;
	bool operator < (const que &q)const{
		return q.x-q.y<x-y;
	}
};
priority_queue<que>q;
int ans;
signed main(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for(int i=n;i>=1;--i){
		if(q.empty()||q.top().x-q.top().y>a[i].x+a[i].y)q.push((que){a[i].x,a[i].y}),++ans;
		else if(q.top().x-q.top().y<a[i].x-a[i].y){
			q.pop();
			q.push((que){a[i].x,a[i].y});
		}
	}
	printf("%d",ans);
	return 0;
}
