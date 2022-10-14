#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
	int x,y;
}a[200005],tmp[200005];
bool cmp(node x,node y){
	if(x.x==y.x)return x.y<y.y;
	return x.x<y.x;
} 
int calc(int lt,int rt){
	if(lt==rt)return 1e18;
	int mid=lt+rt>>1;
	int d=min(calc(lt,mid),calc(mid+1,rt));
	int k=0,l=lt,r=mid+1;
	for(int i=lt;i<=rt;++i){
		if((a[i].x-a[mid].x)*(a[i].x-a[mid].x)<d)tmp[++k]=a[i];
	}
	for(int i=1;i<=k;++i){
		for(int j=i+1;j<=k;++j){
			d=min(d,(tmp[i].x-tmp[j].x)*(tmp[i].x-tmp[j].x)+(tmp[i].y-tmp[j].y)*(tmp[i].y-tmp[j].y));
		}
	}
	return d;
}
signed main(){
	freopen("dark.in","r",stdin);
	freopen("dark.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1,cmp);
	printf("%.3lf",1.0*(calc(1,n))/2.0);
	return 0;
} 
