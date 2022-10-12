#include<bits/stdc++.h>
using namespace std;
int xa,ya,xb,yb,cnt;
double ans=0.0;
struct node{
	bool opt;//0:横着的  1:竖着的 
	double x1,y1,x2,y2;
}sp[10000005];
void split(node x,int tot){
	if(tot>=14)return;
//	cout<<x.opt<<' '<<x.x1<<' '<<x.y1<<' '<<x.x2<<' '<<x.y2<<'\n';
	if(x.opt==0){
		double base=(x.x2-x.x1)/3;
		double pos=x.x2-base;
		node to={0,pos,x.y1,x.x2,x.y2};
		sp[++cnt]={1,pos,x.y1,pos,x.y1+base};
		sp[++cnt]={1,pos,x.y1,pos,x.y1-base};
		split(to,tot+1);
		split(sp[cnt-1],tot+1);
		split(sp[cnt],tot+1);
	}
	else{
		double base=(x.y2-x.y1)/3;
		double pos=x.y2-base;
		node to={1,x.x1,pos,x.x2,x.y2};
		sp[++cnt]={0,x.x1,pos,x.x1+base,pos};
		sp[++cnt]={0,x.x1,pos,x.x1-base,pos};
		split(to,tot+1);
		split(sp[cnt-1],tot+1);
		split(sp[cnt],tot+1);
	}
}
int main(){
	freopen("Metamorphosis.in","r",stdin);
	freopen("Metamorphosis.out","w",stdout);
	cin>>xa>>ya>>xb>>yb;
	sp[++cnt]={1,0,0,0,81};
	split(sp[1],1);
	for(int i=1;i<=cnt;++i){
		if(sp[i].opt==0){
//			if(sp[i].y1>=ya&&sp[i].y1<=yb){
//				cout<<sp[i].opt<<' '<<sp[i].x1<<' '<<sp[i].y1<<' '<<sp[i].x2<<' '<<sp[i].y2<<' ';
//				cout<<min(1.0*xb,max(sp[i].x1,max(sp[i].x2,1.0*xa)))<<' '<<min(1.0*xb,max(1.0*xa,min(sp[i].x1,sp[i].x2)))<<'\n';
//			}
			if(sp[i].y1>=ya&&sp[i].y1<=yb)ans+=min(1.0*xb,max(sp[i].x1,max(sp[i].x2,1.0*xa)))-min(1.0*xb,max(1.0*xa,min(sp[i].x1,sp[i].x2)));
		}
		else{
//			if(sp[i].x1>=xa&&sp[i].x2<=xb){
//				cout<<sp[i].opt<<' '<<sp[i].x1<<' '<<sp[i].y1<<' '<<sp[i].x2<<' '<<sp[i].y2<<' ';
//				cout<<min(1.0*yb,max(sp[i].y1,max(sp[i].y2,1.0*ya)))<<' '<<min(1.0*yb,max(1.0*ya,min(sp[i].y1,sp[i].y2)))<<'\n';
//			}
			if(sp[i].x1>=xa&&sp[i].x2<=xb)ans+=min(1.0*yb,max(sp[i].y1,max(sp[i].y2,1.0*ya)))-min(1.0*yb,max(1.0*ya,min(sp[i].y1,sp[i].y2)));
		}
	}
	printf("%.1lf",ans);
	return 0;
}

