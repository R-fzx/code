//c
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int NUM=1e5+5;
const int INF=0x3f3f3f3f;

int n,maxn;
int a[NUM],tsort[NUM],f[2][NUM];

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'||ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}

void msort(int bit)
{
    int ncnt=0;
    for(int i=0;i<n;++i)
        tsort[i]=a[i];

    for(int i=0;i<n;++i)
    {
        if(tsort[i]&bit)
            a[ncnt++]=tsort[i];
    }
    
    for(int i=0;i<n;++i)
    {
        if(!(tsort[i]&bit))
            a[ncnt++]=tsort[i];
    }
}

signed main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	
    scanf("%lld",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%lld",&a[i]);
        // return 0;
        maxn=max(a[i],maxn);
    }
	
//	return 0;
	
    memset(f[0],INF,sizeof(f[0]));
    f[0][0]=0;

    for(int i=0;;++i)
    {
		int tl=0,tr=0,tempp=(1ll<<i);
        bool tf=(i&1);

        memset(f[tf^1],INF,sizeof(f[tf^1]));

        for(int j=0;j<n;++j)
		{
			if(a[j]&tempp)
				++tr;
		}

        for(int j=0;j<=n;++j)
        {
            if(f[tf][j]!=INF)
            {
                f[tf^1][j+tr]=min(f[tf^1][j+tr],f[tf][j]+tr-tl+j);
                f[tf^1][tl]=min(f[tf^1][tl],f[tf][j]+n+tl-tr-j);
            }

            if(a[j]&tempp)
            {
                ++tl;
                --tr;
            }
        }

        if(tf && tempp>maxn)
            break;

        msort(tempp);
    }
    
    cout<<f[0][0];

    return 0;
}