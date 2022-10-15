#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<iterator>
#include<iostream>
#define oo 0x7fffffff
using namespace std;
int N,K,A;
int B[10],L[10],t[10];
double ans=0;
double find(int sl,double gl,int jg,int wl)
{
	double dq=0;
	if(sl==N+1)
	{
	  if(jg>N/2)
	    return(gl);
	  else
	    return(gl*double(A)/double(A+wl));
	  }
	if(L[sl]!=100)
	{
	  t[sl]=0;
	  dq+=find(sl+1,gl*double(100-L[sl])/100.00,jg,wl+B[sl]);
	  }
	if(L[sl]!=0)
	{
	  t[sl]=1;
	  dq+=find(sl+1,gl*double(L[sl])/100.00,jg+1,wl);
	  }
	return(dq);
}
void ss(int sl,int lw)
{
	int i,j,k,l;
	double dq=0;
	if(sl==N+1)
	{
	  dq=find(1,1,0,0);
	  if(dq>ans) ans=dq;
	  return;
	  }
	for(i=(sl==N?min(lw,(100-L[sl])/10):0);i<=lw && i<=(100-L[sl])/10;i++)
	{
	  L[sl]+=i*10;
	  ss(sl+1,lw-i);
	  L[sl]-=i*10;
	  }
}
int main()
{
	freopen("assembly.in","r",stdin);
	freopen("assembly.out","w",stdout);/**/
	int i,j,k,l;
	scanf("%d%d%d",&N,&K,&A);
	for(i=1;i<=N;i++)
	  scanf("%d%d",&B[i],&L[i]);
	ss(1,K);
	printf("%0.6lf\n",ans);
	return(0);	
}
