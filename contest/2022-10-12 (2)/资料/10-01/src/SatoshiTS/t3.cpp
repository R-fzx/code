#include<stdio.h>
#include<stdlib.h>
#define mod 10007

int a[10001],len,n;
void plus(int x)
{
    int i;
    for(i=1;i<=len;i++)
		a[i]*=x;
    for(i=1;i<=len;i++)
    {
      a[i+1]+=a[i]/10000;
      a[i]%=10000;
    }
    if(a[len+1])
		len++;
    return;
}
void ural()
{
    int i;
    a[1]++;
    for(i=1;a[i]>=10000;a[i]-=10000,a[i+1]++,i++);
		if(a[len+1])
			len++;
    return;
}
void dail()
{
    int i;
    a[1]--;
    for(i=1;a[i]<0;a[i]+=10000,a[i+1]--,i++);
		if(!a[len])
			len--;
    return;
}
int main()
{
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    int i,j,k,m,n;
    scanf("%d",&n);
    if(n==1)
	{
		printf("0\n");
		return 0;
	}
    a[1]=len=1;
    for(i=3;i<=n;i++)
    {
        plus(i);
        if(i&1)
	        dail();
		else
			ural();
    }
    printf("%d",a[len]);
    for(i=len-1;i>0;i--)
		printf("%04d",a[i]);
    printf("\n");
    return 0;
}
