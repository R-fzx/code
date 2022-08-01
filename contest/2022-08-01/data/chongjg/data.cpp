#include<cstdio>
#include<ctime>
#include<algorithm>
#include<set>
using namespace std;
char s[21]={"chongjg\0.in"};
int main()
{
	srand((unsigned)time(NULL));
	for(int z=0;z<=9;z++)
	{
		s[7]='0'+z;
		freopen(s,"w",stdout);
		fclose(stdout);
	}
	return 0;
}
