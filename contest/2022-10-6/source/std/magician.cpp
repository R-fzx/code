#include<stdio.h>
int n,m,x,y,z=1,f[200020],mod=1000000009;
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;	
}
int main()
{
	freopen("magician.in","r",stdin);
	freopen("magician.out","w",stdout); 
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		if(F(x)==F(y))
			z=z*2%mod;
		else
			f[F(x)]=F(y);
		printf("%d\n",z-1);
	}
	return 0; 
}
