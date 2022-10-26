//x
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int NUM=1e5+5;
const int LITTLE=105;

struct node
{
    int x,y;
}d[NUM];

int n,ans;
bool flagg;
int g[LITTLE][LITTLE];

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'||ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}

inline bool cmp(node a,node b)
{
    return a.x<b.x;
}

signed main()
{
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>d[i].x>>d[i].y;

        if(d[i].y!=0)
            flagg=1;
    }

    if(flagg==0)
    {
        sort(d+1,d+1+n,cmp);
//        ans=unique(d+1,d+1+n)-d-1;
		ans=1;
		for(int i=2;i<=n;++i)
		{
			if(d[i].x!=d[i-1].x)
				++ans;
		}
		cout<<ans;
		return 0;
    }
    else
    {
    	for(int i=1;i<n;++i)
		{
			for(int j=i+1;j<=n;++j)
			{
				g[i][j]=g[j][i]=(abs(d[i].x-d[j].x)>abs(d[i].y+d[j].y));
//				cout<<g[i][j]<<endl;
			}
		}
//		cout<<"!!!"<<endl;
		for(int s=1;s<=n;++s)
		{
			set<int> st;
			st.clear();
			st.insert(s);
//			cout<<"!!!"<<endl;
			for(int i=1;i<=n;++i)
			{
				if(!st.count(i))
				{
					bool flag=0;
					for(set<int>::iterator iter=st.begin();iter!=st.end();++iter)
					{
						if(g[i][*iter]==0)
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
						st.insert(i);
				}
			}
			int siz=st.size();
			ans=max(ans,siz);
//			cout<<siz<<endl;
//			for(set<int>::iterator iter=st.begin();iter!=st.end();++iter)
//				cout<<"!!! "<<*iter<<endl;
		}
		
		cout<<ans;
	}

    return 0;
}
