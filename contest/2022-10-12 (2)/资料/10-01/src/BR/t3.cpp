#include<stdio.h>
#include<stdlib.h>
FILE *fin=fopen("t3.in","r");
FILE *fout=fopen("t3.out","w");
long f[203][1003];
void dT(long m){
	long i,j,k;
	f[m][0]=f[m-1][0];
	for (i=1;i<=f[m][0];++i)
		f[m][i]=f[m-1][i]+f[m-2][i];
	for (i=1;i<=f[m][0];++i)
		if (f[m][i]>9){
			f[m][i]-=10;
			++f[m][i+1];
			if (i==f[m][0]) ++f[m][0];
		}
	k=m-1;
	for (i=1;i<=f[m][0];++i)
		f[m][i]*=k;
	for (i=1;i<=f[m][0];++i)
		if (f[m][i]>9){
			f[m][i+1]+=f[m][i]/10;
			f[m][i]%=10;
			if (i==f[m][0]) ++f[m][0];
		}
	return ;
}
int main(){
	long i,j,k,m,n;
	fscanf(fin,"%ld",&n);
	f[1][0]=1;
	f[1][1]=0;
	f[2][0]=1;
	f[2][1]=1;
	for (i=3;i<=n;++i)
		dT(i);
	for (i=f[n][0];i>0;--i)
		fprintf(fout,"%ld",f[n][i]);
	fprintf(fout,"\n");
	fclose(fin);
	fclose(fout);
	return 0;
}
