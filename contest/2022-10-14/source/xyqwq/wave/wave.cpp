//wave
#include<bits/stdc++.h>
using namespace std;

int m,n,c,cnt;
bool bj[25];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

inline void dfs(int x,int y,int step,int *str)
{
	if(step==n)
	{
		++cnt;
		if(cnt==c)
		{
			for(int i=1;i<=n;++i)
				cout<<str[i]<<" ";
			cout<<endl;
			return ;
		}
//		for(int i=1;i<=n;++i)
//				cout<<str[i]<<" ";
//		cout<<"!!!"<<endl;
		return ;
	}
	
	if(y>x)
	{
		if(y==x+1)
			return ;
		
		for(int i=x+1;i<y;++i)
		{
			if(!bj[i])
			{
				bj[i]=1;
				str[++step]=i; 
				dfs(y,i,step,str);
				bj[i]=0;
			}	
		}
	}
	
	if(y<x)
	{
		if(y==x-1)
			return ;
		
		for(int i=x-1;i>y;--i)
		{
			if(!bj[i])
			{
				bj[i]=1;
				str[++step]=i; 
				dfs(y,i,step,str);
				bj[i]=0;
			}	
		}
	}
}

signed main()
{
	freopen("wave.in","r",stdin);
	freopen("wave.out","w",stdout);
	
	m=read();
	while(m--)
	{
		n=read(),c=read();
		
		if(n==1)
		{
			cout<<"1"<<endl;
			continue;
		}
		
		if(n==2)
		{
			if(c==1)
				cout<<"1 2"<<endl;
			else
				cout<<"2 1"<<endl;
			continue;
		}
		
		if(n==3)
		{
			switch(c)
			{
				case 1:
					{cout<<"1 3 2"<<endl;break;}
				case 2:
					{cout<<"2 1 3"<<endl;break;}
				case 3:
					{cout<<"2 3 1"<<endl;break;}
				case 4:
					{cout<<"3 1 2"<<endl;break;}
			}
			continue;
		}
		
		if(n==4)
		{
			switch(c)
			{
				case 1:
					{cout<<"1 3 2 4"<<endl;break;}
				case 2:
					{cout<<"1 4 2 3"<<endl;break;}
				case 3:
					{cout<<"2 1 4 3"<<endl;break;}
				case 4:
					{cout<<"2 3 1 4"<<endl;break;}
				case 5:
					{cout<<"2 4 1 3"<<endl;break;}
				case 6:
					{cout<<"3 1 4 2"<<endl;break;}
				case 7:
					{cout<<"3 2 4 1"<<endl;break;}
				case 8:
					{cout<<"3 4 1 2"<<endl;break;}
				case 9:
					{cout<<"4 1 3 2"<<endl;break;}
				case 10:
					{cout<<"4 2 3 1"<<endl;break;}
			}
			continue;
		}
		
		cnt=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(i==j || i==j+1 || i==j-1)
					continue;
				
				memset(bj,0,sizeof(bj));
				int tempp[25]={0,i,j};
				dfs(i,j,2,tempp);
			}
		}
	} 
	
	return 0;
}

