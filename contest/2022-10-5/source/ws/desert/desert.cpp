#include<bits/stdc++.h>
using namespace std;

int n,m;
int sx,sy;
char mz[55][55];

vector<pair<int,int> >q,tq;

const int dx[8]={1,1,1,0,-1,-1,-1,0},dy[8]={1,0,-1,-1,-1,0,1,1};

int dis[55][55],vis[55][55];

bool check(int x,int y){
	return x<1 || x>n
		|| y<1 || y>m
		|| vis[x][y]
		|| mz[x][y]=='X';
}

void work(){
	int tm=0;
	while(!q.empty()){
		tm++;
		for(int i=0;i<q.size();i++){
			pair<int,int>u=q[i];
			int ux=u.first,
				uy=u.second;
			bool isov=0;
			for(int k=0,nx,ny;k<8;k++){
				nx=ux+dx[k],
				ny=uy+dy[k];
				if(check(nx,ny))continue;
				isov=1;
				tq.push_back(make_pair(nx,ny));
			}
		}
		sort(tq.begin(),tq.end());
		for(int i=0;i<tq.size();i++){
			
		}
	}
}

int main(){
	freopen("desert.in","r",stdin);
	freopen("desert.out","w",stdout);
	
	string s;
	
	cin>>n;
	getline(cin,s);
	
	getline(cin,s);
	for(int i=0;i<s.size();i++)
		if(s[i]!='-' || s[i]=='*' || s[i]=='X' || s[i]=='@'){
			m++;
			mz[i][m]=s[i];
		}
	
	for(int i=2;i<=n;i++){
		getline(cin,s);
		for(int j=1;j<=m;j++)
			mz[i][j]=s[2*j-2];
	}
	
	memset(dis,-1,sizeof dis);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(mz[i][j]=='@')
				sx=i,sy=j;
			else if(mz[i][j]=='*'){
				dis[i][j]=0;
				vis[i][j]=1;
				q.push_back(make_pair(i,j));
			}
		}
	
	work();
	
	cout<<dis[sx][sy]<<endl;
	return 0;
}
