#include<stdio.h>
#include<string.h>
#define IN "wave.in"
#define OUT "wave.out"
FILE *fo,*fp;
int m,n,c;
int sum;
int hash[29],work[29];
bool pan()
{
	int i;
	if(n<=2)return true;
	for(i=0;i<=n-3;i++)
	{
		if(work[i]<work[i+1]&&work[i+1]<work[i+2])
		return false;
		if(work[i]>work[i+1]&&work[i+1]>work[i+2])
		return true;
	}
	return true;
}
void print()
{
	int i;
	for(i=0;i<n-1;i++)
	{fprintf(fo,"%d ",work[i]);
	}
	fprintf(fo,"%d\n",work[n-1]);
}
bool dfs(int st)
{
	if(st==n)
	{if(pan()){
	  sum++;
	  if(sum==c){print();return true;}
	  }
	}
	int i;
	for(i=1;i<=n;i++)
	{
		if(!hash[i])
		{work[st]=i;
		 hash[i]=true;
		 if(dfs(st+1))return true;
		 hash[i]=false;
		 work[st]='0';
		}
	}
	return false;
}
bool init()
{
	if((fp=fopen(IN,"r"))==NULL)return 1;
	if((fo=fopen(OUT,"w"))==NULL)return 1;
}
void exit()
{
	fclose(fo);
	fclose(fp);
}
int main()
{
	if(init())return 1;
	fscanf(fp,"%d",&m);
	int i;
	for(i=0;i<m;i++)
	{ memset(work,0,sizeof(work));
	  memset(hash,0,sizeof(hash));
	  sum=0;
	  fscanf(fp,"%d%d",&n,&c);
	  dfs(0);
	}
	exit();
	return 0;
}
