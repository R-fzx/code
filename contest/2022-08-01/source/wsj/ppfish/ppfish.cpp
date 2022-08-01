#include<cstdio>
#define N 200
#define LEN0 20
int n;
char s[N][LEN0];
void read(char*);
int main(){
	freopen("ppfish.in","r",stdin);
	freopen("ppfish.out","w",stdout);
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;++i){
		read(s[i]);
	}
	return 0;
}
void read(char* s){
	int c,i=0;
	while((c=getchar())^10) s[i++]=c;
}
