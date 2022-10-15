#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
void Read();
void Count();
void Write();
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Read();
	Count();
	Write();
	//system("pause");
	return 0;
}

int num_point,num_road;
long long cost_a,cost_b;
struct ROAD{int x,y;long long va,vb;}road[510000]={0};
struct LIST{struct LIST *next,*pre,*oppo;int p;long long val;}list[1100000]={0};
struct POINT{struct LIST head;}point[210]={0};
inline bool Comp(struct ROAD a,struct ROAD b)
{	return a.va<b.va || a.va==b.va && a.vb<b.vb;	}
void Read()
{
	scanf("%d%d",&num_point,&num_road);
	scanf("%I64d%I64d",&cost_a,&cost_b);
	for(int i=1;i<=num_road;i++)
		scanf("%d%d%I64d%I64d",&road[i].x,&road[i].y,&road[i].va,&road[i].vb);
	std::sort(road+1,road+num_road+1,Comp);
	return;
}

int use=0;
inline void Link(int x,int y,long long val)
{
	struct LIST *k=&list[use++],*l=&list[use++];
	k->p=y,l->p=x;
	k->val=l->val=val;
	k->oppo=l,l->oppo=k;
	k->next=point[x].head.next, point[x].head.next=k;
	l->next=point[y].head.next, point[y].head.next=l;
	k->pre=k->next->pre,k->next->pre=k;
	l->pre=l->next->pre,l->next->pre=l;
	return;
}
inline void Dele(struct LIST *k)
{
	k->pre->next=k->next;
	k->next->pre=k->pre;
	k=k->oppo;
	k->pre->next=k->next;
	k->next->pre=k->pre;
	return;
}

long long ans;
inline long long Update(long long va)
{
	long long max=0;
	for(int x=1;x<=num_point;x++)
		for(struct LIST *k=point[x].head.next;k!=&point[x].head;k=k->next)
			if( k->val > max )	max=k->val;
	//printf("%I64d %I64d  %I64d\n",va,max,va*cost_a + max*cost_b);
	return va*cost_a + max*cost_b;
}

bool Dfs(int x,int y,int father,struct LIST *&max)
{
	if( x==y )	return true;
	for(struct LIST *k=point[x].head.next;k!=&point[x].head;k=k->next)
		if( k->p!=father && Dfs(k->p,y,x,max) )
		{
			if( !max || k->val > max->val )		max=k;
			return true;
		}
	return false;
}

int link_num=0;
inline long long Min(long long x,long long y){	if(x<y)	return x;	return y;	}
inline void Add(struct ROAD rd)
{
	struct LIST *k={0};
	if( rd.x==rd.y )	return;
	if( !Dfs(rd.x,rd.y,0,k) )
		link_num++,Link( rd.x, rd.y, rd.vb);
	else if( rd.vb < k->val )	Dele(k),Link( rd.x, rd.y, rd.vb);
	if( link_num==num_point-1)
		ans=Min( ans, Update(rd.va));
	return;
}

void Count()
{
	ans=1000000000ll*(cost_a+cost_b);
	for(int i=1;i<=num_point;i++)	point[i].head.next=point[i].head.pre=&point[i].head;
	for(int i=1;i<=num_road;i++)
		Add(road[i]);
	return;
}

void Write()
{
	printf("%I64d\n",ans);
	return;
}

