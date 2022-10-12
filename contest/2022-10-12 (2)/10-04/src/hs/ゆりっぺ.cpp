#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
void Read();
void Count();
void Write();
int main()
{
	freopen("ゆりっぺ.in","r",stdin);
	freopen("ゆりっぺ.out","w",stdout);
	Read();
	Count();
	Write();
	//system("pause");
	return 0;
}

int num_peo,need[3]={0};
struct PEO{	long long val[3],pos;	}peo[510000]={0};
void Read()
{
	scanf("%d%d%d%d",&num_peo,&need[0],&need[1],&need[2]);
	for(int i=1;i<=num_peo;i++)
		scanf("%I64d%I64d%I64d",&peo[i].val[0],&peo[i].val[1],&peo[i].val[2]),peo[i].pos=i;
	return;
}

int cp,num;
int list[3][510000]={0},heap[510000]={0};
bool choose[3][510000]={0};
inline bool Comp(int x,int y)
{
	return peo[x].val[cp] > peo[y].val[cp] || peo[x].val[cp]==peo[y].val[cp] &&
									peo[x].val[0]+peo[x].val[1]+peo[x].val[2] > peo[y].val[0]+peo[y].val[1]+peo[y].val[2];
}

inline void Up(int p)
{
	int s=heap[p];
	for(;p!=1 && Comp(s,heap[p>>1]);p>>=1)	heap[p]=heap[p>>1];
	heap[p]=s;
	return;
}

inline void Down(int p)
{
	int s=heap[p];
	for(int max=p<<1;max<=num;p=max,max=p<<1)
	{
		if( max+1<=num && Comp(heap[max+1],heap[max]) )		max++;
		if( Comp( s,heap[max] )	)		break;
		heap[p]=heap[max];
	}
	heap[p]=s;
	return;
}

inline int Pop()
{
	int s=heap[1];
	heap[1]=heap[num--];
	Down(1);
	return s;
}

void Sort(int n)
{
	cp=n,num=num_peo;
	int sum=need[0]+need[1]+need[2];
	for(int i=1;i<=num_peo;i++)		heap[i]=i;
	for(int i=num/2;i;i--)		Down(i);
	for(int i=1;i<=sum;i++)		list[n][i]=Pop();
	return;
}

long long ans,ans2;
long long f[110][110][110]={0},f2[110][110][110]={0};
long long can[310]={0};
inline int Min(int x,int y){	if(x<y)	return x;	else return y;	}
inline int Max(int x,int y){	if(x>y)	return x;	else return y;	}
inline void Update(int x,int y,int z,long long pre,long long pre2,int k,int p)
{
	//printf("%d,%d,%d   %I64d\n",x,y,z,pre);
	long long add1=pre+peo[ can[k] ].val[p];
	long long add2=pre2 +peo[ can[k] ].val[0] +peo[ can[k] ].val[1] +peo[ can[k] ].val[2];
	if( add1>f[x][y][z] || add1==f[x][y][z] && add2>f2[x][y][z] )
		f[x][y][z]=add1,f2[x][y][z]=add2;
	return;
}

void Count()
{
	int sum=need[0]+need[1]+need[2];
	if( sum>num_peo ){	ans=-1;	return;	}
	/*for(int i=1;i<=num_peo;i++)		list[0][i]=list[1][i]=list[2][i]=i;
	cp=0;std::sort(list[0]+1,list[0]+num_peo+1,Comp);
	cp=1;std::sort(list[1]+1,list[1]+num_peo+1,Comp);
	cp=2;std::sort(list[2]+1,list[2]+num_peo+1,Comp);*/
	Sort(0);
	Sort(1);
	Sort(2);
	int num=0;	
	for(int i=1;i<=sum;i++)
		choose[0][ list[0][i] ]=true,
		choose[1][ list[1][i] ]=true,
		choose[2][ list[2][i] ]=true;
	int sub0=0,sub1=0,sub2=0;
	long long pre=0,pre2=0;
	for(int i=1;i<=need[0];i++)
		if( !choose[1][ list[0][i] ] && !choose[2][ list[0][i] ] )
			pre+=peo[ list[0][i] ].val[0], sub0++,
			pre2+=peo[ list[0][i] ].val[0]
			     +peo[ list[0][i] ].val[1]
				 +peo[ list[0][i] ].val[2];
		else	can[++num]=list[0][i];
		
	for(int i=1;i<=need[1];i++)
		if( !choose[0][ list[1][i] ] && !choose[2][ list[1][i] ] )
			pre+=peo[ list[1][i] ].val[1], sub1++,
			pre2+=peo[ list[1][i] ].val[0]
			     +peo[ list[1][i] ].val[1]
				 +peo[ list[1][i] ].val[2];
		else if( !choose[0][ list[1][i] ] )	
			can[++num]=list[1][i];
	
	for(int i=1;i<=need[2];i++)
		if( !choose[0][ list[2][i] ] && !choose[1][ list[2][i] ] )
			pre+=peo[ list[2][i] ].val[2], sub2++,
			pre2+=peo[ list[2][i] ].val[0]
			     +peo[ list[2][i] ].val[1]
				 +peo[ list[2][i] ].val[2];
		else if( !choose[0][ list[2][i] ] && !choose[1][ list[2][i] ] )	
			can[++num]=list[2][i];
	
	
	//printf(" sub : %d,%d,%d\n",sub0,sub1,sub2);
	//printf(" %I64d %I64d\n",pre,pre2);
	for(int i=need[0]+1;i<=sum;i++)
		can[++num]=list[0][i];
	for(int i=need[1]+1;i<=sum;i++)
		if( !choose[0][ list[1][i] ] )
			can[++num]=list[1][i];
	for(int i=need[2]+1;i<=sum;i++)
		if( !choose[0][ list[2][i] ] && !choose[1][ list[2][i] ] )
			can[++num]=list[2][i];
	sum-=sub0+sub1+sub2;
	need[0]-=sub0;need[1]-=sub1;need[2]-=sub2;
	f[0][0][0]=1+pre;
	/*for(int i=1;i<=sum;i++)	printf("%d ",list[0][i]);printf("\n");
	for(int i=1;i<=sum;i++)	printf("%d ",list[1][i]);printf("\n");
	for(int i=1;i<=sum;i++)	printf("%d ",list[2][i]);printf("\n");
	printf("******\n");
	for(int i=1;i<=num;i++)	printf("%d ",can[i]);printf("\n");*/
	for(int k=1;k<=num;k++)
		for(int x=Min(need[0],k);x>=0 && need[0]-x<=num-k;x--)
			for(int y=Min(k-x,need[1]);y>=0 && sum-need[2]-x-y<=num-k;y--)
				for(int z=Min(k-x-y,need[2]);z>=0 && sum-x-y-z<=num-k;z--)
				{
					long long a=0,b=0;
					if( x&&f[x-1][y][z] )	Update(x,y,z,f[x-1][y][z],f2[x-1][y][z],k,0);
					if( y&&f[x][y-1][z] )	Update(x,y,z,f[x][y-1][z],f2[x][y-1][z],k,1);
					if( z&&f[x][y][z-1] )	Update(x,y,z,f[x][y][z-1],f2[x][y][z-1],k,2);
				}
	ans=f[need[0]][need[1]][need[2]]-1;
	ans2=f2[need[0]][need[1]][need[2]]+pre2;
	return;
}

void Write()
{
	if( ans<0 )	printf("I am a godlike cowcowcow\n");
	else printf("%I64d\n%I64d\n",ans,ans2);
	return;
}



		
