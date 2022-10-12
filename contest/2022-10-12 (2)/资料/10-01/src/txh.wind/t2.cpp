#include<stdio.h>
#include<math.h>
FILE *fin,*fout;
long long f[61];
int main()
{
	long long a,b,answer,i,j,l;
	fin=fopen("t2.in","r");
	fout=fopen("t2.out","w");
	while(1)
	{
		fscanf(fin,"%I64d%I64d",&a,&b);
		if(!a)
			break;
		for(i=1;i<60;++i)
			f[i]=0;
		answer=0;
		for(i=60;i>1;--i)
		{
			l=(int)pow(b,1.0/(double)i)-(int)(pow(a,1.0/(double)i)-0.00001);
			for(j=1;j<i;++j)
				if(i%j==0)
					f[j]+=l-f[i];
			answer+=i*(l-f[i]);
		}
		answer+=b-a+1-f[1];
		fprintf(fout,"%I64d\n",answer);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
