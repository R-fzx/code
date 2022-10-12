#include<stdio.h>
#include<stdlib.h>
void Read();
void Count();
void Write();
int main()
{
	freopen("t2.in","r",stdin);
	freopen("t2.out","w",stdout);
	Read();
	Count();
	Write();
	//system("pause");
	return 0;
}

int num_point;
struct ROAD{ struct ROAD *next;int p;long long val;}road[2100000]={0};
struct POINT{struct ROAD *head;int num;bool in;long long dist;}point[1100]={0};

int use=0;
inline void Link(int x,int y,long long v)
{
	if( x==y )	return;
	struct ROAD *k=&road[use++],*l=&road[use++];
	k->p=y,l->p=x;
	k->val=l->val=v;
	k->next=point[x].head,point[x].head=k;
	l->next=point[y].head,point[y].head=l;
	return;
}

void Read()
{
	int n;
	long long v;
	scanf("%d%d",&num_point,&n);
	for(int i=1,x,y;i<=n;i++)
		scanf("%d%d%I64d",&x,&y,&v),Link(x,y,v);
	return;
}

void Spfa();
void Rebuild();
void Cnt_ans();
void Count()
{
	Spfa();
	Rebuild();
	Cnt_ans();
	return;
}


int queue[1100000]={0},front,rear;
inline void Push(int x){	point[x].in=true; queue[++rear]=x;	return;		}
inline int Pop(){	point[ queue[front] ].in=false; return queue[front++];	}
inline bool Empty(){	return rear<front;	}
inline void Update(int x,long long v)
{
	if( point[x].dist==-1 || v<point[x].dist )
	{
		point[x].dist=v;
		if( !point[x].in )	Push(x);
	}
	return;
}

void Spfa()
{
	for(int i=2;i<=num_point;i++)	point[i].dist=-1;
	front=1;
	Push(1);
	for(int x;!Empty();)
		for(struct ROAD *k=point[x=Pop()].head;k;k=k->next)
			Update(k->p, point[x].dist+k->val);
	return;
}

bool link[1100][1100]={0};
void Rebuild()
{
	for(int x=1;x<=num_point;x++)
		for(struct ROAD *k=point[x].head;k;k=k->next)
			if( point[x].dist+k->val == point[k->p].dist && !link[x][k->p])
				point[k->p].num++,link[x][k->p]=true;
	return;
}

long long ans;
void Cnt_ans()
{
	long long mod=(1ll<<31)-1;
	ans=1;
	for(int x=2;x<=num_point;x++)
		ans*=point[x].num,ans%=mod;
	return;
}

void Write()
{
	printf("%I64d\n",ans);
	return;
}

