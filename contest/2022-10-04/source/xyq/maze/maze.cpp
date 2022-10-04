//maze
#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
const int NUM=105;

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

priority_queue<pair<double,int> > q;
vector<int> nxt[NUM*NUM];
vector<double> w[NUM*NUM];

int T,R,C,s,e;
double L;
char mapp[NUM][NUM];
double dis[NUM*NUM];
bool vis[NUM*NUM];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void add(int u,int v,double val)
{
    nxt[u].push_back(v);
	nxt[v].push_back(u);
	w[u].push_back(val);
	w[v].push_back(val);
}

void Dijkstra()
{
	for(int i=1; i<=R*C;++i)
        dis[i]=INF,vis[i]=0;
    while(!q.empty())
		q.pop();
	
//	cout<<"!!!"<<endl;
	dis[s]=0;
//	cout<<"!!!"<<endl;
	q.push(make_pair(0,s));
	
//	cout<<"!!!"<<endl; 
	
	while(!q.empty())
	{
		int x=q.top().second;
//		cout<<x<<endl;
		q.pop();
		
		if(vis[x]==1)
			continue;
		
		vis[x]=1;
		
//		cout<<nxt[x].size()<<endl;

		int temp=nxt[x].size();
		for(int i=0;i<temp;++i)
		{
			if(dis[nxt[x][i]]>dis[x]+w[x][i])
			{
				 dis[nxt[x][i]]=dis[x]+w[x][i];
				 
				 q.push(make_pair(-dis[nxt[x][i]],nxt[x][i]));
			}
		}
	}
}

signed main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	
	T=read();
	while(T--)
	{
		cin>>L;
		R=read(),C=read();
//		cout<<L<<" "<<R<<" "<<C<<endl; 
		
		for(int i=1;i<=R;++i)
		{
			char ch;
			for(int j=1;j<=C;++j)
			{
		        scanf("%c",&ch);  
		        while(ch=='\n')
					scanf("%c",&ch);  
				
				mapp[i][j]=ch;
				
				if(ch=='S')
					s=(i-1)*C+j;
				if(ch=='E')
					e=(i-1)*C+j;
			}
		}
		
//		for(int i=1;i<=R;++i)
//		{
//			for(int j=1;j<=C;++j)
//				cout<<mapp[i][j];
//			cout<<endl;
//		}
		
		double tl=0.0,tr=10.0;
		while(tr-tl>0.0000001)
		{
			double mid=(tl+tr)/2;
			
			for(int i=1;i<=R*C;++i)
			nxt[i].clear(),w[i].clear();
			
			for(int i=1;i<=R;++i)
			{
				for(int j=1;j<=C;++j)
				{
					for(int k=0;k<4;++k)
					{
						if(mapp[i][j]!='#' && mapp[i+dir[k][0]][j+dir[k][1]]!='#')
						{
							if(k<2)
								add((i-1)*C+j,(i+dir[k][0]-1)*C+j+dir[k][1],mid);
							else
								add((i-1)*C+j,(i+dir[k][0]-1)*C+j+dir[k][1],1.0);
							
//							cout<<i<<" "<<j<<" "<<(i-1)*C+j<<" "<<(i+dir[k][0]-1)*C+j+dir[k][1]<<" "<<mid<<endl;
						}
					}
				} 
			}
			
//			cout<<"!!!"<<endl;
			
			Dijkstra();
			
//			cout<<"!!!"<<endl;
			
//			cout<<dis[e]<<endl;
			
			if(dis[e]>L)
				tr=mid;
            else
				tl=mid;
		}
		
		printf("%.5lf\n",tl);
	}
	
	return 0;
}

