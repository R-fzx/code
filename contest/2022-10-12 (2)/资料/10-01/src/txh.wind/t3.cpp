#include<stdio.h>
#include<string.h>
FILE *fin,*fout;
int a[20000],b[20000],t[20000],lt=1,la,lb=1;
int jia()
{
	int i;
	for(i=0;i<lt;++i)
		t[i]=0;
	for(i=0;i<lt;++i)
	{
		t[i]+=(a[i]+b[i]);
		if(t[i]>9)
		{
			++t[i+1];
			t[i]-=10;
		}
	}
	if(t[lt])
		++lt;
}
void cheng(int p)
{
	int tmp=0,i;
	for(i=0;i<lt;++i)
	{
		t[i]*=p;
		t[i]+=tmp;
		tmp=t[i]/10;
		t[i]%=10;
	}
	while(tmp)
	{
		t[lt]=tmp%10;
		tmp/=10;
		++lt;
	}
	lb=lt;
	for(i=0;i<lt;++i)
		b[i]=t[i];
}
int main()
{
	int i,j,n;
	fin=fopen("t3.in","r");
	fout=fopen("t3.out","w");
	fscanf(fin,"%d",&n);
	b[0]=1;
	for(i=3;i<=n;++i)
	{
		jia();
		la=lb;
		for(j=0;j<lb;++j)
			a[j]=b[j];
		cheng(i-1);
	}
	for(i=lb-1;i>=0;--i)
		fprintf(fout,"%d",b[i]);
	fprintf(fout,"\n");
	fclose(fin);
	fclose(fout);
	return 0;
}

