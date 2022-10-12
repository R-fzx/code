#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
FILE *fin=fopen("t2.in","r");
FILE *fout=fopen("t2.out","w");
long long f[63];
long z[63]={2,3,5,7,11,13,17,19,23,29,31};
long long a,b,x,y;
int main(){
	long i,j,k,m,n;
	fscanf(fin,"%I64d%I64d",&a,&b);
	while (a!=0LL){
		memset(f,0,sizeof(f));
		for (i=2;i<60;++i){
			x=(long long)(pow(a*1.0,1.0/(i*1.0))+0.999999999);
			// x-=5LL;
			// x=x>=0LL?x:0LL;
			// fprintf(fout,"%I64d\n",x);
			//while ((long long)(pow(x*1.0,i*1.0))<a) ++x;
			y=(long long)(pow(b*1.0,1.0/(i*1.0)));
			//y+=1LL;
			//fprintf(stdout,"%ld-%I64d\n",i,y);
			//while ((long long)(pow(y*1.0,i*1.0))>b) --y;
			// fprintf(fout,"%I64d %I64d\n",x,y);
			f[i]=y-x+1LL>0 && y>0?y-x+1LL:0;
		}
		/*for (i=2;i<=60;++i)
			fprintf(fout,"%I64d ",f[i]);
		fprintf(fout,"\n");*/
		for (i=60;i>1;--i)
			for (j=2;j<=30;++j)
				if (i%j==0)
					f[i/j]-=f[i];
		f[1]=b-a+1LL;
		for (i=2;i<60;++i){
			f[1]-=f[i];
			f[1]+=f[i]*(long long)(i);
		}
		fprintf(fout,"%I64d\n",f[1]);
		fscanf(fin,"%I64d%I64d",&a,&b);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
