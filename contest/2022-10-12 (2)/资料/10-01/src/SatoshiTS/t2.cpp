#include<stdio.h>
#include<stdlib.h>

bool flag[10000000];
FILE *fin,*fout;

int main()
{
    int i,j,k,m,n;
	int x,y;
    int answer,now,nowk,num;
	
    fin=fopen("t2.in","r");
	fout=fopen("t2.out","w");
	
    while(true)
	{
		fscanf(fin,"%d%d",&x,&y);
		if(x)
		{
		    num=0;
			answer=0;
			for(i=0;i<=y-x;i++)
				flag[i]=0;
			for(i=2;i<=y;i++)
			{
				now=1;
				nowk=0;
				while(now<=y)
				{
					now*=i;
					nowk++;
					if(now>=x && now<=y)
						if(!flag[now-x])
						{
							answer+=nowk;
							flag[now-x]=1;
							num++;
						}
				}
				if(num>y-x)
					break;
			}
			fprintf(fout,"%d\n",answer);
		}
		if(!x)
		    break;
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
