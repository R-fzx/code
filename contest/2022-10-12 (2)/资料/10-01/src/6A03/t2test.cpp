#include<stdio.h>
#include<stdlib.h>
bool f[1000001];
long long g[1010196];
long v[1010196];
int main()
{
	long i,j,a,b,l=0;
	long long q,p,s1;
	FILE *fout=fopen("1.out","w");
	p=1000000;
	p*=1000000;
	for(i=2;i<=1000000;i++)
		if(f[i]==0)
		{
			s1=i;q=i;j=0;
			while(1)
			{
				s1=s1*q;
				j++;
				if(s1>p||s1<0)break;
				if(s1<=1000000)f[s1]=1;
				l++;g[l]=s1;v[l]=j;
			}
		}
	fprintf(fout,"%ld\n",l);
	fclose(fout);
	return 0;
}
