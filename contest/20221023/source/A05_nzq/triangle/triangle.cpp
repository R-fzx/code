#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+10;
struct node{int l,r,id,ans;}qq[maxn];
int n,q,vis_r[maxn],vis_l[maxn];
LL a[maxn],tmp[maxn];
bool cmp_id(node a,node b){return a.id<b.id;}
bool cmp_l(node a,node b){return a.l==b.l?a.r>b.r:a.l<b.l;}
int main(){
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	memset(vis_r,127,sizeof(vis_r));
	memset(vis_l,-1,sizeof(vis_l));
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>tmp[i];
	for(int i=1;i<=q;i++) cin>>qq[i].l>>qq[i].r,qq[i].id=i;
	sort(qq+1,qq+1+q,cmp_l);
	for(int i=1;i<=q;i++){
		int l=qq[i].l,r=qq[i].r;
//		cout<<l<<' '<<r<<endl;
		if(vis_r[r]<=l||vis_l[l]>=r){
			qq[i].ans=0;
			continue;
		}
		memcpy(a,tmp,sizeof(a));
		sort(a+l,a+1+r);
		int f=0;
//		for(int i=l;i<=r;i++) cout<<a[i]<<' ';
//		cout<<endl;
		for(int i=l+2;i<=r;i++) if(a[i-1]+a[i-2]>a[i]){
			f=1;
//			cout<<a[i]<<' '<<a[i-1]<<' '<<a[i-2]<<endl;
			break;
		}
		if(f==1){
			qq[i].ans=1;
			continue;
		}else{
			qq[i].ans=0;
			vis_r[r]=min(vis_r[r],l);
			vis_l[l]=max(vis_l[l],r);
		}
	}
	sort(qq+1,qq+1+q,cmp_id);
	for(int i=1;i<=q;i++) cout<<(qq[i].ans?"Yes\n":"No\n");
	return 0;
}
