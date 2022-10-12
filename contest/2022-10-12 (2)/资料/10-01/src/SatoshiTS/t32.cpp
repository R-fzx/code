#include<stdio.h>
#include<stdlib.h>

typedef struct board
{
    bool b[201][201];
	int block;
}CHESS;
CHESS chess;

int ans,n;
FILE *fin;
FILE *fout;
int now;

int slove(CHESS bor,int x)
{
    ++now;
	int i,j,k;
	CHESS t1=bor,t2=bor;
	int x1,x2;
	
	if(x==0)
	    return 1;
	if(x>bor.block)
	    return 0;
	if(bor.block==1)
	    return 1;
	bool flag=false;
	for(i=1;i<=n && !flag;i++)
	{
		for(j=1;j<=n && !flag;j++)
		{
			if(t1.b[i][j])
			{
				int ii;
				
				for(ii=1;ii<=n;ii++)
				if(t1.b[i][ii])
				{
					t1.b[i][ii]=false;
					t1.block--;
				}
				for(ii=1;ii<=n;ii++)
				if(t1.b[ii][j])
				{
					t1.b[j][ii]=false;
					t1.block--;
				}
				
				t2.b[i][j]=0;
				t2.block--;
				flag=true;
			}
		}
	}
	x1=slove(t1,x-1);
	x2=slove(t2,x);
	return x1+x2;
}

int main()
{
	int i,j,k,m;
	fin=fopen("t3.in","r");
	fout=fopen("t3.out","w");
	
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;++i)
	    for(j=1;j<=n;++j)
		{
			fscanf(fin,"%d",&chess.b[i][j]);
			chess.block+=chess.b[i][j];
		}
	ans=slove(chess,n);
	fprintf(fout,"%d\n",ans);
	fclose(fin);
	fclose(fout);
	return 0;
}
