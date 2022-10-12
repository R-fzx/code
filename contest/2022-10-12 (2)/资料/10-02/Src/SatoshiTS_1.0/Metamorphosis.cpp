#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int dblcmp(double x)
{
	if(fabs(x)<1e-7)
		return 0;
	if(x<0)
		return -1;
	return 1;
}

double slove(int n,int x,int x1,int y1,int x2,int y2)
{
    if(dblcmp(y2)<0 || dblcmp(y1-x)>=0);
}

int main()
{
    int i,j,k,m,n;
    int x1,y1,x2,y2;
    FILE *fin=fopen("Metamorphosis.in","r");
    fopen("Metamorphosis.out","w");
    
    fscanf(fin,"%d%d%d%d",&x1,&y1,&x2,&y2);
    fprintf(fout,"%1lf",slove(500,81,x1,y1,x2,y2));
    //808C
    return 0;
}
