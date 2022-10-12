#include<stdio.h>
#include<string.h>
FILE *fin,*fout;
int left[2010],right[2010],f[2010],zuhe[2200][2200];
int work(int a)
{
	int p=0,q=0;
	if(left[a])
  		p=work(left[a]);
	if(right[a])
		q=work(right[a]);	
	f[a]=zuhe[p+q][p];
	f[a]*=f[left[a]];
	f[a]%=10007;
	f[a]*=f[right[a]];
	f[a]%=10007;
	return p+q+1;
}
int main()
{
	int t,n,i,j,k,m,a,b,p,q,now;
	fin=fopen("t1.in","r");
	fout=fopen("t1.out","w");
	fscanf(fin,"%d",&t);
	for(i=0;i<2200;++i)
		zuhe[i][0]=1;
	for(i=1;i<2200;++i)
		for(j=1;j<=i;++j)
		{
			zuhe[i][j]=zuhe[i-1][j]+zuhe[i-1][j-1];
			zuhe[i][j]%=10007;
		}
	while(t)
	{
		--t;
		fscanf(fin,"%d",&n);
		memset(left,0,8040);
		memset(right,0,8040);
		memset(f,0,8040);
		f[0]=1;
		for(i=1;i<=n;++i)
		{
			fscanf(fin,"%d",&m);
			if(m)
			{
				fscanf(fin,"%d",&a);
				left[i]=a;
				for(j=1;j<m;++j)
				{					
					fscanf(fin," %d\n",&b);
					right[a]=b;
					a=b;
				}
			}
		}
		work(1);
		fprintf(fout,"%d\n",f[1]);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
