#include<stdio.h>
#include<stdlib.h>
FILE *fin=fopen("DerProze.in","r");
FILE *fout=fopen("DerProze.out","w");
char ans[7][13]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
long mo[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
int main(){
	long i,j,k,y,m,d,sum;
	fscanf(fin,"%ld%ld%ld",&y,&m,&d);
	sum=6;
	if (y>=2000){
		for (i=2000;i<y;++i){
			if (i%4==0 && i%100!=0 || i%400==0) sum+=2;
			else ++sum;
			sum%=7;
		}
		k=y%4==0 && y%100!=0 || y%400==0;
		for (i=1;i<m;++i) sum+=mo[k][i];
		sum+=d;
		sum+=6;
		sum%=7;
	}
	else{
		for (i=1999;i>y;--i){
			if (i%4==0 && i%100!=0 || i%400==0) sum-=2;
			else --sum;
			sum+=7;
			sum%=7;
		}
		k=y%4==0 && y%100!=0 || y%400==0;
		j=0;
		for (i=1;i<m;++i) j+=mo[k][i];
		j+=d;
		j=(k==0?365:366)-j;
		sum-=j%7;
		sum+=6;
		sum%=7;
	}
	fprintf(fout,"%s\n",ans[sum]);
	fclose(fin);
	fclose(fout);
	return 0;
}
