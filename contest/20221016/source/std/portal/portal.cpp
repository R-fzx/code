#include<algorithm>
#include<utility>
#include<queue>
#include<iostream>
using namespace std;
char mat[1005][1005];
int ply[1005][1005];
int pry[1005][1005];
int pux[1005][1005];
int pdx[1005][1005];
int r,c;
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > pq;
int v[1005][1005];
void make_portal()
{
    for(int i=0;i<r;i++) 
	{
        int piv=0;
        for(int j=0;j<c;j++) 
		{
            if(mat[i][j]=='#') 
				piv=j+1;
            pry[i][j]=piv;
        }
    }
    for(int i=0;i<r;i++) 
	{
        int piv=c-1;
        for (int j=c-1;j>=0;j--) 
		{
            if(mat[i][j]=='#') 
				piv=j-1;
            ply[i][j]=piv;
        }
    }
    for(int j=0;j<c;j++) 
	{
        int piv=0;
        for(int i=0;i<r;i++) 
		{
            if(mat[i][j]=='#') 
				piv=i+1;
            pdx[i][j]=piv;
        }
    }
    for(int j=0;j<c;j++) 
	{
        int piv=r-1;
        for(int i=r-1;i>=0;i--) 
		{
            if(mat[i][j]=='#') 
				piv = i-1;
            pux[i][j]=piv;
        }
    }
} 
void push(int x,int y,int d)
{
    if(x<0||x>=r||y<0||y>=c) 
		return;
    if(v[x][y]) 
		return;
    if(mat[x][y]=='#') 
		return;
    pq.push(make_pair(d,make_pair(x,y)));
}
 
int main()
{
	freopen("portal.in","r",stdin);
	freopen("portal.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
    cin>>r>>c;
    for(int i=0;i<r;i++)
	{
		cin>>mat[i];
        for(int j=0;j<c;j++) 
		{
            if(mat[i][j]=='C')
			{
                pq.push(make_pair(0,make_pair(i,j)));
            }
        }
    }
    make_portal();
    while(!pq.empty()) 
	{
        pair<int,pair<int,int> > c=pq.top();
        pq.pop();
        int x=c.second.first;
        int y=c.second.second;
        int d=c.first;
        if(v[x][y]) 
			continue;
        if(mat[x][y]=='F')
		{
            cout<<d<<endl;
            return 0;
        }
        v[x][y]=1;
        push(x-1,y,d+1);
        push(x,y-1,d+1);
        push(x+1,y,d+1);
        push(x,y+1,d+1);
        int dist=min(abs(ply[x][y]-y),abs(y-pry[x][y]));
        dist=min(dist,min(abs(pux[x][y]-x),abs(pdx[x][y]-x)));
        push(x,ply[x][y],d+dist+1);
        push(x,pry[x][y],d+dist+1);
        push(pux[x][y],y,d+dist+1);
        push(pdx[x][y],y,d+dist+1);
    }
	cout<<"nemoguce"<<endl;
	return 0;
}
