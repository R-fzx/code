#include<stdio.h>
#include<math.h>
FILE *fin,*fout;
int facs[1001],facn;
long long ans;
bool chk(long long x)
{
	long long i;
	for (i=1;i<=facn;++i)
		if (facs[i]%x!=0)
			return false;
	return true;
}
void fac(long long x)
{
	long long i,k,last,x2=x,min=2147483647;
	bool change;
	i=2;last=-1;facn=0;
	while (x>1)
	{
		change=false;
		while (x%i==0)
		{
			if (i==last) ++facs[facn];
			else {++facn;facs[facn]=1;last=i;change=true;}
			x/=i;
		}
		if (change) {min=(min>facs[facn] && last!=-1)?facs[facn]:min;change=false;}
		++i;
	}
	if (chk(min)) ans+=min;
	else ans+=1;
	return;
}
int main()
{
	fin=fopen("t2.in","r");
	fout=fopen("t2.out","w");
	long long a,b,i;
	while (1)
	{
		fscanf(fin,"%I64d%I64d",&a,&b);
		if (a==0 && b==0) break;
		ans=0;
		for (i=a;i<=b;++i) fac(i);
		fprintf(fout,"%I64d\n",ans);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
