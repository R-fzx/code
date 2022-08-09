/**
 * Copyright (C) 2022 wsj (also called singulet31258, singulet3c58, quarkstar31258)
 * Nobody else can submit my code to Yali OJ!!!
 *
 * Difficulty: VERY HARD & COMPLEX
 *
 * My Solution: Binary Search + Hash.
 * 
 * Time Complexity: O(NlogN)
 */

#ifndef _YALI_20220809_SNOWMAN_SOLUTION_BY_WSJ_SINGULET31258_
#define _YALI_20220809_SNOWMAN_SOLUTION_BY_WSJ_SINGULET31258_

#include<cstdio>
#include<cctype>
#include<algorithm>
#define MAX_QUANTITY_OF_SNOWMEN 1<<19
#define SUPER_PRIME 793999ULL
#define HYPER_PRIME 1000000007ULL

int i,j,c,n,x[MAX_QUANTITY_OF_SNOWMEN],q[MAX_QUANTITY_OF_SNOWMEN];
int l,u,m,flag;
unsigned long long f[MAX_QUANTITY_OF_SNOWMEN];
unsigned long long b[MAX_QUANTITY_OF_SNOWMEN];//Bases of Hash.
unsigned long long v[MAX_QUANTITY_OF_SNOWMEN];//Values of Hash.
inline bool cmp(int,int);
void read(int*);

using std::sort;

int main(){
	freopen("snowman.in","r",stdin);
	freopen("snowman.out","w",stdout);
	read(&n);
	b[0]=1;
	for(i=1;i<=n;++i){
		read(x+i);
		b[i]=b[i-1]*SUPER_PRIME;
		v[i]=v[i-1]*SUPER_PRIME+HYPER_PRIME+x[i]-x[i-1];
	}
	l=0;u=1+(n>>1);
	while(l<u){
		m=l+u+1>>1;
		for(i=1,j=m-1;j^n+1;f[i]=v[j]-v[i-1]*b[j-i+1],q[i]=i,++i,++j);
		sort(q+1,q+n-m+3,cmp);
		for(i=1,j=1;i^n-m+3;i=j){
			while(f[q[j]]==f[q[i]]&&j<n-m+3) ++j;
			if(q[j-1]-q[i]>=m){
				flag=1;
				break;
			}
		}
		if(flag){
			l=m;
			flag=0;
		}else u=m-1;
	}
	return printf("%d",l),0;
}

inline bool cmp(int x,int y){
	return f[x]<f[y]||f[x]==f[y]&&x<y;
}

void read(int* p){
	while(!isdigit(c=getchar()));
	*p=c&15;
	while(isdigit(c=getchar())) *p=(*p<<1)+(*p<<3)+(c&15);
}

#endif
