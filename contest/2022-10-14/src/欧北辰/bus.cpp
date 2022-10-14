#include<cstdio>
#define IN "bus.in"
#define OUT "bus.out"
FILE *fo,*fp;
typedef unsigned long long u64;

int n,c[100003];
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
    int i;
	fscanf(fp,"%d\n",&n);
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d\n",&c[i]);
	}
	u64 sum=0;
	int s;
	for(i=0;i<n;i++)
	{s=1;
		while(c[i+s]>=c[i]&&i+s<n)
		{
			s++;
		}
		sum+=(u64)c[i]*s;
		i+=s;
		i--;
	}
	fprintf(fo,"%I64d",sum);
	exit();
	return 0;
}
