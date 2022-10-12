#include<stdio.h>

char w[7][12]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};

int main()
{
	long i,a,b,c,y,r,x=1;
	freopen("DerProze.in","r",stdin);
    freopen("DerProze.out","w",stdout);
	scanf("%ld%ld%ld",&a,&b,&c);
	for(i=1;i<a;i++)
	{
		if((i%4==0&&i%100!=0)||i%400==0)
            x+=2;
        else
            x++;
    }
    y=1;r=1;
	while(y<b||(y==b&&r<c))
	{
		r++;
        x++;
		if(r==32)
           y++,r=1;
		if(r==31 && (y==4||y==6||y==9||y==11))
           y++,r=1;
		if(y==2 && r==30)
           y++,r=1;
		if(y==2 && r==29 && ((a%4!=0&&a%100!=0)||a%400==0))
           y++,r=1;
	}
	printf("%s\n",w[x%7]);
	return 0;
}
