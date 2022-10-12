#include<stdio.h>
#include<stdlib.h>
FILE *fin=fopen("t1.in","r");
FILE *fout=fopen("t1.out","w");
long mp[1003][1003];
long st[1003],mps,f[1003][1003],zs[1003],ans[1003];
void shtr(long m){
	long i,j,k;
	// printf("%ld\n",m);
	// system("pause");
	for (i=mp[m][0];i>0;--i){
		shtr(mp[m][i]);
		ans[mp[m][i]]=((ans[mp[m][i]]*ans[mp[m][i+1]])%10007)*(f[zs[mp[m][i+1]]][zs[mp[m][i]]])%10007;
		zs[mp[m][i]]+=zs[mp[m][i+1]];
	}
	zs[m]=zs[mp[m][1]]+1;
	ans[m]=ans[mp[m][1]];
	return ;
}
void in(){
	long i,j,k,n;
	fscanf(fin,"%ld",&n);
	for (i=1;i<=n;++i){
		fscanf(fin,"%ld",&k);
		mp[i][0]=k;
		mp[i][k+1]=0;
		for (j=1;j<=k;++j)
			fscanf(fin,"%ld",&mp[i][j]);
	}
	/*for (i=1;i<=n;++i,printf("\n"))
		for (j=1;j<=n;++j)
			printf("%ld ",f[i][j]);
	system("pause");*/
	ans[0]=1;
	shtr(1);
	fprintf(fout,"%ld\n",ans[1]);
	return ;
}
int main(){
	long i,j,k,m,n;
	for (i=1;i<=1000;++i)
		f[0][i]=1;
	for (i=1;i<=1000;++i)
		for (j=1;j<=1000;++j)
			f[i][j]=(f[i][j-1]+f[i-1][j])%10007;
	fscanf(fin,"%ld",&m);
	for (i=1;i<=m;++i)
		in();
	fclose(fin);
	fclose(fout);
	return 0;
}
