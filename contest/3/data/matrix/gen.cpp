#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a(){return rand()%1234+1;}
int b(){return rand()%4321+1;}
int main()
{
	srand(time(0));
	printf("%d %d %d %d %d %d\n",a(),b(),a(),b(),a(),b());
	return 0;
}
