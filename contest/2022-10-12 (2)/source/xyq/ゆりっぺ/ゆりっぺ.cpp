//ゆりっぺ
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int NUM=5e5+5;

struct node
{
	int a,b,c,sum,id;
}man[NUM],ma[NUM],mb[NUM],mc[NUM];

int n,A,B,C,sum1,sum2,cnta,cntb,cntc;
bool vis[NUM];

inline int read()
{
    int x=0,f=1; char ch=0;
    while(ch!='-' && (ch<'0' || ch>'9')) ch=getchar();
    if(ch=='-') f=-1,ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}

//inline bool cmpa(node x,node y)
//{
//	if(x.a<y.a && x.sum>y.sum)
//		return (x.sum-y.sum>y.a-x.a);
//	if(x.a>y.a)
//		return 1;
//	if(x.a==y.a)
//		return x.sum>y.sum;
//	return 0;
//} 
//
//inline bool cmpb(node x,node y)
//{
//	if(x.b<y.b && x.sum>y.sum)
//		return (x.sum-y.sum>y.b-x.b);
//	if(x.b>y.b)
//		return 1;
//	if(x.b==y.b)
//		return x.sum>y.sum;
//	return 0;
//} 
//
//inline bool cmpc(node x,node y)
//{
//	if(x.c<y.c && x.sum>y.sum)
//		return (x.sum-y.sum>y.c-x.c);
//	if(x.c>y.c)
//		return 1;
//	if(x.c==y.c)
//		return x.sum>y.sum;
//	return 0;
//} 

inline bool cmpa(node x,node y)
{
	if(x.a>y.a)
		return 1;
	if(x.a==y.a)
		return x.sum>y.sum;
	return 0;
} 

inline bool cmpb(node x,node y)
{
	if(x.b>y.b)
		return 1;
	if(x.b==y.b)
		return x.sum>y.sum;
	return 0;
} 

inline bool cmpc(node x,node y)
{
	if(x.c>y.c)
		return 1;
	if(x.c==y.c)
		return x.sum>y.sum;
	return 0;
} 

signed main()
{
	freopen("ゆりっぺ.in","r",stdin);
	freopen("ゆりっぺ.out","w",stdout);
	
	n=read(),A=read(),B=read(),C=read();
	
	for(int i=1;i<=n;++i)
	{
		man[i].a=read(),man[i].b=read(),man[i].c=read();
		man[i].sum=man[i].a+man[i].b+man[i].c;
		man[i].id=i;
		ma[i]=mb[i]=mc[i]=man[i];
		
//		int temp=max(man[i].a,max(man[i].b,man[i].c));
//		if(man[i].a==temp)
//		{
//			man[i].best=1;
//			ma[++cnta]=man[i];
//		}
//		else if(man[i].b==temp)
//		{
//			man[i].best=2;
//			mb[++cntb]=man[i];
//		}
//		else if(man[i].c==temp)
//		{
//			man[i].best=3;
//			mc[++cntc]=man[i];
//		}
	}
	
	if(A+B+C>n)
	{
		cout<<"I am a godlike cowcowcow";
		return 0;
	}
	
	if(A+B+C==0)
	{
		cout<<"0"<<endl<<"0";
		return 0;
	}
	
	sort(ma+1,ma+1+n,cmpa);
//	for(int i=1;i<=A;++i) 
//	{
//		sum1+=ma[i].a;
//		sum2+=ma[i].sum;
//	}
	sort(mb+1,mb+1+n,cmpb);
//	for(int i=1;i<=B;++i) 
//	{
//		sum1+=ma[i].b;
//		sum2+=ma[i].sum;
//	}
	sort(mc+1,mc+1+n,cmpc);
//	for(int i=1;i<=C;++i) 
//	{
//		sum1+=ma[i].c;
//		sum2+=ma[i].sum;
//	}
	
//	for(int i=1;i<=n;++i)
//		cout<<ma[i].a<<"  "<<mb[i].b<<"  "<<mc[i].c<<endl;
	
	int lasta=1,lastb=1,lastc=1;
	for(int i=1;i<=n;++i)
	{
		int ta=lasta,tb=lastb,tc=lastc;
		if(ta>n)
			ta=-1;
		if(tb>n)
			tb=-1;
		if(tc>n)
			tc=-1;
//		cout<<ma[ta].id<<" "<<mb[tb].id<<" "<<mc[tc].id<<endl;
		
		if(vis[ma[ta].id]==1)
		{
			while(vis[ma[ta].id]==1)
				++ta,++lasta;
		}
		if(vis[mb[tb].id]==1)
		{
			while(vis[mb[tb].id]==1)
				++tb,++lastb;
		}
		if(vis[mc[tc].id]==1)
		{
			while(vis[mc[tc].id]==1)
				++tc,++lastc;
		}
		
		if(ma[ta].id==mb[tb].id && mb[tb].id==mc[tc].id && ta!=-1 && tb!=-1&& tc!=-1 && A && B && C)
		{
			int nxta=ta+1,nxtb=tb+1,nxtc=tc+1;
			while(vis[ma[nxta].id]==1)
				++nxta;
			while(vis[mb[nxtb].id]==1)
				++nxtb;
			while(vis[mc[nxtc].id]==1)
				++nxtc;
				
			if(ma[ta].a-ma[nxta].a>mb[ta].b-mb[nxtb].b && ma[ta].a-ma[nxta].a>mc[tc].c-mc[nxtc].c && mc[tc].c!=0 && mb[tb].b!=0 && ma[ta].a!=0)
			{
				vis[ma[ta].id]=1;
//				cout<<"1: "<<ma[ta].a<<endl;
				sum1+=ma[ta].a;
				--A;
				sum2+=ma[ta].sum;
				++lasta;
			}
			else if(ma[ta].a-ma[nxta].a<mb[ta].b-mb[nxtb].b && mb[tb].b-mb[nxtb].b>mc[tc].c-mc[nxtc].c)
			{
				vis[mb[tb].id]=1;
//				cout<<"2: "<<mb[tb].b<<endl;
				--B;
				sum1+=mb[tb].b;
				sum2+=mb[tb].sum;
				++lastb;
			} 
			else if(mc[tc].c-mc[nxtc].c>mb[ta].b-mb[nxtb].b && mb[tb].b-mb[nxtb].b<mc[tc].c-mc[nxtc].c)
			{
				vis[mc[tc].id]=1;
//				cout<<"3: "<<mc[tc].c<<endl;
				sum1+=mc[tc].c;
				--C;
				sum2+=mc[tc].sum;
				++lastc;
			} 
			else
			{
				vis[ma[ta].id]=1;
//				cout<<"4: "<<ma[ta].a<<endl;
				sum1+=ma[ta].a;
				sum2+=ma[ta].sum;
				++lasta;
			}
		}
		else if(ma[ta].id==mb[tb].id && ta!=-1 && tb!=-1 && ma[ta].a!=0 && mb[tb].b!=0 && A && B)
		{
			int nxta=ta+1,nxtb=tb+1;
			while(vis[ma[nxta].id]==1)
				++nxta;
			while(vis[mb[nxtb].id]==1)
				++nxtb;
				
			if(ma[ta].a-ma[nxta].a>mb[tb].b-mb[nxtb].b)
			{
				vis[ma[ta].id]=1;
//				cout<<"5: "<<ma[ta].a<<endl;
				sum1+=ma[ta].a;
				--A;
				sum2+=ma[ta].sum;
				++lasta;
			} 
			else
			{
				vis[mb[tb].id]=1;
//				cout<<"6: "<<mb[tb].b<<endl;
				sum1+=mb[tb].b;
				--B;
				sum2+=mb[tb].sum;
				++lastb;
			}
		}
		else if(ma[ta].id==mc[tc].id && ta!=-1 && tc!=-1 && mc[tc].c!=0 && ma[ta].a!=0 && A && C)
		{
			int nxta=ta+1,nxtc=tc+1;
			while(vis[ma[nxta].id]==1)
				++nxta;
			while(vis[mc[nxtc].id]==1)
				++nxtc;
				
			if(ma[ta].a-ma[nxta].a>mc[tc].c-mb[nxtc].c)
			{
				vis[ma[ta].id]=1;
//				cout<<"7: "<<ma[ta].a<<endl;
				sum1+=ma[ta].a;
				--A;
				sum2+=ma[ta].sum;
				++lasta;
			} 
			else
			{
				vis[mc[tc].id]=1;
//				cout<<"8: "<<mc[tc].c<<endl;
				sum1+=mc[tc].c;
				--C;
				sum2+=mc[tc].sum;
				++lastc;
			}
		}
		else if(mc[tc].id==mb[tb].id && tc!=-1 && tb!=-1 && mc[tc].c!=0 && mb[tb].b!=0 && B && C)
		{
			int nxtc=tc+1,nxtb=tb+1;
			while(vis[mc[nxtc].id]==1)
				++nxtc;
			while(vis[mb[nxtb].id]==1)
				++nxtb;
				
			if(mc[tc].c-mc[nxtc].c>mb[tb].b-mb[nxtb].b)
			{
				vis[mc[tc].id]=1;
//				cout<<"9: "<<mc[tc].c<<endl;
				sum1+=mc[tc].c;
				--C;
				sum2+=mc[tc].sum;
				++lastc;
			} 
			else
			{
				vis[mb[tb].id]=1;
//				cout<<"10: "<<mb[tb].b<<endl;
				sum1+=mb[tb].b;
				--B;
				sum2+=mb[tb].sum;
				++lastb;
			}
		}
		else if(ma[ta].id!=mb[tb].id && mb[tb].id!=mc[tc].id && ma[ta].id!=mc[tc].id)
		{
			++lasta;
			++lastb;
			++lastc;
//			cout<<"!!!"<<endl;
			if(ta!=-1 && A)
			{
				sum1+=ma[ta].a;
				--A;
				sum2+=ma[ta].sum;
				vis[ma[ta].id]=1;
			}
			if(tb!=-1 && B)
			{
				sum1+=mb[tb].b;
				--B;
				sum2+=mb[tb].sum;
				vis[mb[tb].id]=1;
			}
			if(tc!=-1 && C)
			{
				sum1+=mc[tc].c;
				--C;
				sum2+=mc[tc].sum;
				vis[mc[tc].id]=1;
			}
			
//			cout<<ta<<" "<<tb<<" "<<tc<<" "<<sum1<<" "<<sum2<<endl;
//			sum1+=ma[ta].a+mb[tb].b+mc[tc].c;
//			sum2+=ma[ta].sum+mb[tb].sum+mc[tc].sum;
		} 
		
		if(!A && !B && C)
		{
			while(C)
			{
				while(vis[mc[tc].id]==1)
					++tc;
					
				sum1+=mc[tc].c;
				--C;
				sum2+=mc[tc].sum;
			}
		}
		if(A && !B && !C)
		{
			while(A)
			{
				while(vis[ma[ta].id]==1)
					++ta;
					
				sum1+=ma[ta].a;
				--A;
				sum2+=ma[ta].sum;
//				cout<<ma[ta].a<<endl;
			}
		}
		if(!A && B && !C)
		{
			while(B)
			{
				while(vis[mb[tb].id]==1)
					++tb;
					
				sum1+=mb[tb].b;
				--B;
				sum2+=mb[tb].sum;
			}
		}
	}
	
//	sort(man+1,man+1+n,cmpa);
//	for(int i=1;i<=A;++i) 
//	{
//		sum1+=man[i].a;
//		sum2+=man[i].sum;
//		man[i].a=0,man[i].b=0,man[i].c=0,man[i].sum=0;
//	}
//	
//	sort(man+1,man+1+n,cmpb);
//	for(int i=1;i<=B;++i) 
//	{
//		sum1+=man[i].b;
//		sum2+=man[i].sum;
//		man[i].a=0,man[i].b=0,man[i].c=0,man[i].sum=0;
//	}
//	
//	sort(man+1,man+1+n,cmpc);
//	for(int i=1;i<=C;++i) 
//	{
//		sum1+=man[i].c;
//		sum2+=man[i].sum;
//	}
	
	cout<<sum1<<endl<<sum2;
}

