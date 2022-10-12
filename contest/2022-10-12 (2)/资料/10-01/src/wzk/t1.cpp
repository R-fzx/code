#include <stdio.h>
int num[50000000];
#define OpenFile 1
int main(int argc, char *argv[])
{
	#if OpenFile
	freopen("t1.in","r",stdin);
	freopen("t1.out","w",stdout);
	#endif
	printf("2\n");
	return 0;
}