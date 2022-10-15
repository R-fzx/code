#include<stdio.h>
#include<stdlib.h>
void Read();
void Count();
void Write();
int main()
{
	freopen("assembly.in","r",stdin);
	freopen("assembly.out","w",stdout);
	Read();
	Count();
	Write();
	//system("pause");
	return 0;
}

int num_peo,num_pre,pre_val;
struct PEOPLE{	int v1,v2;	}peo[15]={0};
void Read()
{
	scanf("%d%d%d",&num_peo,&num_pre,&pre_val);
	for(int i=0;i<num_peo;i++)
		scanf("%d%d",&peo[i].v2,&peo[i].v1);
	return;
}

double ans=0;
long long divv,max;
inline void Cnt(double &get,long long state)
{
	int num=0;
	long long val=1,sum=pre_val;
	for(int i=0;i<num_peo;i++)
		if( state&(1<<i) )
			num++,val=val*peo[i].v1;
		else	
			val=val*(100-peo[i].v1), sum+=peo[i].v2;
	double add=(double)val/divv;
	if( num*2<=num_peo )	add=add*pre_val/sum;
	get+=add;
	//printf("%I64d %I64d %d %I64d\n",val,divv,pre_val,sum);
	//printf("%lf %lf\n",add,get );
	return;
}

void Dfs(int rest,int point)
{
	if( !rest || point>=num_peo )
	{
		double get=0;
		for(long long i=0;i<max;i++)
			Cnt(get,i);
		if( get>ans )	ans=get;
	}
	else
	{
		int save=peo[point].v1;
		for(; rest && peo[point].v1<100 ;rest--,peo[point].v1+=10)
			Dfs(rest,point+1);
		if( peo[point].v1>100 )	peo[point].v1=100;
		Dfs(rest,point+1);
		peo[point].v1=save;
	}
	return;
}

void Count()
{
	//printf("%d\n",pre_val);
	max=1<<num_peo;
	divv=1;
	for(int i=1;i<=num_peo;i++)	divv*=100;
	Dfs(num_pre,0);
	return;
}

void Write()
{
	printf("%lf\n",ans);
	return;
}

