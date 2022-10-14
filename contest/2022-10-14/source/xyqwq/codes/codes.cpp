//codes
#include<bits/stdc++.h>
using namespace std;

const int NUM=25;

int n;
string a[NUM];
map<string,int>	mapp;
queue<string> q;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

inline bool cmp(string x,string y)
{
	int sizex=x.size(),sizey=y.size();
	if(sizex==sizey)
		return x<y;
	else
		return sizex<sizey;
}

/*
cin>>a+1;
    cin>>b+1;
    la=strlen(a+1);
    lb=strlen(b+1);
    for (int i=2;i<=lb;i++)
	   {     
	   while(j&&b[i]!=b[j+1])
        j=kmp[j];    
       if(b[j+1]==b[i])j++;    
        kmp[i]=j;
       }
    j=0;
    for(int i=1;i<=la;i++)
	   {
          while(j>0&&b[j+1]!=a[i])
           j=kmp[j];
          if (b[j+1]==a[i]) 
           j++;
          if (j==lb) {cout<<i-lb+1<<endl;j=kmp[j];}
       }

    for (int i=1;i<=lb;i++)
    cout<<kmp[i]<<" ";
*/

inline void bfs()
{
	string str,tempp;
	while(!q.empty())
	{
		str=q.front();
		q.pop();
		for(int i=1;i<=n;++i)
		{
			tempp=str+a[i];
			if(mapp[tempp]==1)
			{
				cout<<tempp.size()<<endl<<tempp;
				exit(0);
			}
			q.push(tempp);	
			mapp[tempp]=1;
		} 
	}
}

signed main()
{
	freopen("codes.in","r",stdin);
	freopen("codes.out","w",stdout);
	
	n=read();
	for(int i=1;i<=n;++i)
		cin>>a[i];
//	for(int i=1;i<=n;++i)
//		cout<<a[i]<<endl;

	sort(a+1,a+1+n,cmp);
//	for(int i=1;i<=n;++i)
//		cout<<a[i]<<endl;

/*
	for(int i=1;i<n;++i)
	{
		if(a[i]==a[i+1])
		{
			for(int j=i+2;j<=n;++j)
				a[i-1]=a[i];
		}
	}

	for(int i=n;i>1;--i)
	{
		for(int j=1;j<n;++j)
			kmp(a[i],a[j]);
	}
*/	
	
	for(int i=1;i<=n;++i)
	{
		q.push(a[i]);
		mapp[a[i]]=1;
	}
	
	bfs();

	return 0;
}

