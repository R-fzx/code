#include<stdio.h>
#include<map>
#include<queue>
using namespace std;

long long gethash1(short data[8])
{
	char yuan[8][10];
	int i,j,minx=100,miny=100,maxx=-1,maxy=-1;
	for(i=1;i<=6;++i)
		for(j=1;j<=8;++j)
			if(data[i]&(1<<j))
			{
				if(i<minx)	minx=i;
				if(i>maxx)	maxx=i;
				if(j<miny)	miny=j;
				if(j>maxy)	maxy=j;
			}
	
	for(i=minx;i<=maxx;++i)
		for(j=miny;j<=maxy;++j)
			yuan[i-minx][j-miny]=((data[i]&(1<<j))!=0);
	maxx-=minx,maxy-=miny;
	long long zhash,nowhash;
	
	for(nowhash=maxx*8+maxy,i=0;i<=maxx;++i)
		for(j=0;j<=maxy;++j)
			nowhash=(nowhash<<1)|yuan[i][j];
	zhash=nowhash;
	for(nowhash=maxx*8+maxy,i=0;i<=maxx;++i)
		for(j=maxy;j>=0;--j)
			nowhash=(nowhash<<1)|yuan[i][j];
	if(nowhash<zhash)
		zhash=nowhash;
	for(nowhash=maxx*8+maxy,i=maxx;i>=0;--i)
		for(j=0;j<=maxy;++j)
			nowhash=(nowhash<<1)|yuan[i][j];
	if(nowhash<zhash)
		zhash=nowhash;
	for(nowhash=maxx*8+maxy,i=maxx;i>=0;--i)
		for(j=maxy;j>=0;--j)
			nowhash=(nowhash<<1)|yuan[i][j];
	if(nowhash<zhash)
		zhash=nowhash;
	for(nowhash=maxy*8+maxx,j=0;j<=maxy;++j)
		for(i=0;i<=maxx;++i)
			nowhash=(nowhash<<1)|yuan[i][j];
	if(nowhash<zhash)
		zhash=nowhash;
	for(nowhash=maxy*8+maxx,j=0;j<=maxy;++j)
		for(i=maxx;i>=0;--i)
			nowhash=(nowhash<<1)|yuan[i][j];
	if(nowhash<zhash)
		zhash=nowhash;
	for(nowhash=maxy*8+maxx,j=maxy;j>=0;--j)
		for(i=0;i<=maxx;++i)
			nowhash=(nowhash<<1)|yuan[i][j];
	if(nowhash<zhash)
		zhash=nowhash;
	for(nowhash=maxy*8+maxx,j=maxy;j>=0;--j)
		for(i=maxx;i>=0;--i)
			nowhash=(nowhash<<1)|yuan[i][j];
	if(nowhash<zhash)
		zhash=nowhash;
	return zhash;
}
long long gethash2(short data[8])
{
	long long ans=0;
	for(int i=1;i<=6;++i)
		ans=(ans<<8)|(data[i]>>1);
	return ans;
}

map <long long,int> hash_bfs,hash_ans;
struct fb
{
	short data[8],size;
	fb()
	{
		for(int i=0;i<8;++i)
			data[i]=0;
		size=0;
	}
};
queue <fb> bfs;
char data[8][10];
int gox[4]={-1,1,0,0},goy[4]={0,0,-1,1};
int main()
{
	int n,m,k,i,j,l;
	freopen("かなで.in","r",stdin);
	freopen("かなで.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;++i)
	{
		scanf("%s",data[i]+1);
		for(j=1;j<=m;++j)
			data[i][j]-='0';
	}
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(data[i][j])
			{
				fb in;
				in.data[i]^=1<<j;
				in.size=1;
				hash_bfs[gethash2(in.data)]=1;
				bfs.push(in);
			}
	
	int ans=0;
	while(!bfs.empty())
	{
		fb now=bfs.front();
		bfs.pop();
		if(now.size==k)
		{
			long long hashz=gethash1(now.data);
			if(!hash_bfs[hashz])
			{
				ans++;
				hash_bfs[hashz]=1;
			}
			continue;
		}
		
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)
				if(now.data[i]&(1<<j))
					for(int k=0;k<4;++k)
						if(data[i+gox[k]][j+goy[k]]&&!(now.data[i+gox[k]]&(1<<(j+goy[k]))))
						{
							now.data[i+gox[k]]^=1<<(j+goy[k]);
							long long hashz=gethash2(now.data);
							if(!hash_bfs[hashz])
							{
								hash_bfs[hashz]=1;
								now.size++;
								bfs.push(now);
								now.size--;
							}
							now.data[i+gox[k]]^=1<<(j+goy[k]);
						}
	}
	printf("%d\n",ans);
	return 0;
}
