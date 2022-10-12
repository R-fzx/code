#include <stdio.h>
int a,b,c,n;
int ax,bx,cx;
long f[101][101][101][2]={0};
int main()
{
	FILE *f1=fopen("ゆりっぺ.in","r");
	FILE *f2=fopen("ゆりっぺ.out","w");
	long i,j,p,q,x,y,s,r,t;
	fscanf(f1,"%d%d%d%d",&n,&a,&b,&c);
	if (a+b+c>n)
	{
		fprintf(f2,"I am a godlike cowcowcow\n");
		fclose(f1);fclose(f2);
		return 0;
	}
	for (i=0;i<n;i++)
	{
		fscanf(f1,"%d%d%d",&ax,&bx,&cx);
		for (j=a;j>=0;j--)
			for (p=b;p>=0;p--)
				for (q=c;q>=0;q--)
				{
					s=ax+bx+cx;
					if (j>0 && (f[j-1][p][q][0]+ax>f[j][p][q][0] || f[j-1][p][q][0]+ax==f[j][p][q][0]&&f[j-1][p][q][1]+s>f[j][p][q][1]))
					{
						f[j][p][q][0]=f[j-1][p][q][0]+ax;
						f[j][p][q][1]=f[j-1][p][q][1]+s;
					}
					if (p>0 && (f[j][p-1][q][0]+bx>f[j][p][q][0] || f[j][p-1][q][0]+bx==f[j][p][q][0]&&f[j][p-1][q][1]+s>f[j][p][q][1]))
					{
						f[j][p][q][0]=f[j][p-1][q][0]+bx;
						f[j][p][q][1]=f[j][p-1][q][1]+s;
					}
					if (q>0 && (f[j][p][q-1][0]+cx>f[j][p][q][0] || f[j][p][q-1][0]+cx==f[j][p][q][0]&&f[j][p][q-1][1]+s>f[j][p][q][1]))
					{
						f[j][p][q][0]=f[j][p][q-1][0]+cx;
						f[j][p][q][1]=f[j][p][q-1][1]+s;
					}
				}
	}
	fprintf(f2,"%d\n%d\n",f[a][b][c][0],f[a][b][c][1]);
	fclose(f1);fclose(f2);
	return 0;
}
