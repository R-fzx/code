/*question: dark templar*/
#include<stdio.h>
#include<math.h>
#define IN "dark.in"
#define OUT "dark.out"
FILE *fo,*fp;

double min=18446744073709551615.0;
int n;
typedef struct tt
{
    int x;
    int y;
}templar;
templar t[200009];
bool init()
{
    if ((fp=fopen(IN,"r"))==NULL)return 1;
    if ((fo=fopen(OUT,"w"))==NULL)return 1;
    fscanf(fp,"%d",&n);
    int i;
    for (i=0;i<n;i++)
        fscanf(fp,"%d%d",&t[i].x,&t[i].y);
    return 0;
}
void exit()
{
    fclose(fo);
    fclose(fp);
}
void qsortx(int l,int r)
{
    int i=l,j=r;
    templar x=t[(l+r)/3];
    t[(l+r)/3]=t[l];
    while (i<j)
    {
        while (i<j&&t[j].x>=x.x)j--;
        t[i]=t[j];
        while (i<j&&t[i].x<=x.x)i++;
        t[j]=t[i];
    }
    t[i]=x;
    if (l<i-1)qsortx(l,i-1);
    if (i+1<r)qsortx(i+1,r);
}
void qsorty(int l,int r)
{
    int i=l,j=r;
    templar y=t[(l+r)/3];
    t[(l+r)/3]=t[l];
    while (i<j)
    {
        while (i<j&&t[j].y>=y.y)j--;
        t[i]=t[j];
        while (i<j&&t[i].y<=y.y)i++;
        t[j]=t[i];
    }
    t[i]=y;
    if (l<i-1)qsorty(l,i-1);
    if (i+1<r)qsorty(i+1,r);
}
void work()
{
	int i;
	int z=n-1;
	double tmp;
	
	qsortx(0,n-1);
	for(i=0;i<z;i++)
	{
		tmp=sqrt((double)(t[i].x-t[i+1].x)*(t[i].x-t[i+1].x)+(double)(t[i].y-t[i+1].y)*(t[i].y-t[i+1].y));
	    if(tmp<min)min=tmp;
	}
	qsorty(0,n-1);
		for(i=0;i<z;i++)
	{
		tmp=sqrt((double)(t[i].x-t[i+1].x)*(t[i].x-t[i+1].x)+(double)(t[i].y-t[i+1].y)*(t[i].y-t[i+1].y));
	    if(tmp<min)min=tmp;
	}
	fprintf(fo,"%.2lf",min);
}
int main()
{
    if (init())return 1;
    work();
    exit();
    return 0;
}
