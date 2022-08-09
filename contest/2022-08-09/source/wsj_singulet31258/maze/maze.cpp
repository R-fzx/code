/**
 * Copyright (C) 2022 wsj (also called singulet31258, singulet3c58, quarkstar31258)
 * Nobody else can submit my code to Yali OJ!!!
 *
 * Difficulty: EASY!!!(It can be Accepted for only Simple Brute-Force + A Little Bit of Optimization)
 *
 * My Solution: Divide the maze into two halves and the separator is
 * the diagonal linked with the left lower corner and the right upper corner;
 * Then search respectively the two halves.
 * Ultimately merge results of two seeks into the total answer. (Optimized Brute-Force)
 * 
 * Time Complexity: O(sqrt(2)^(N+M))
 */

#ifndef _YALI_20220809_MAZE_SOLUTION_BY_WSJ_SINGULET31258_
#define _YALI_20220809_MAZE_SOLUTION_BY_WSJ_SINGULET31258_

#include<iostream>
#include<cstdio>
#include<cctype>
#include<map>
#define MAX_QUANTITY_OF_ROWS 1<<5
#define MAX_QUANTITY_OF_COLUMNS 1<<5
#define MAX_SIZE_OF_MAZE 1<<10

using std::map;
using std::cout;

int c,i,j;
int n,m,k;
int a[MAX_QUANTITY_OF_ROWS][MAX_QUANTITY_OF_COLUMNS];
//Obstructed?
int obs[MAX_QUANTITY_OF_ROWS][MAX_QUANTITY_OF_COLUMNS];
map<int,unsigned long long>f[MAX_SIZE_OF_MAZE];
unsigned long long ans;
void read(int*);
void lus(int,int,int);//Left Upper Search
void rls(int,int,int);//Right Lower Search

int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	read(&n);read(&m);read(&k);
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			read(&a[i][j]);
			obs[i][j]=!a[i][j];
		}
	}
	lus(1,1,0);
	rls(n,m,0);
	return cout<<ans,0;//The legal format of uint64 is not definite (%llu or %I64u).
}

void read(int* p){
	while(!isdigit(c=getchar()));
	*p=c&15;
	while(isdigit(c=getchar())) *p=(*p<<1)+(*p<<3)+(c&15);
}

void lus(int x,int y,int now){
	if(obs[x][y]) return;
	now^=a[x][y];
	if(x+y-1^n+m>>1){
		if(x<n) lus(x+1,y,now);
		if(y<m) lus(x,y+1,now);
	}else++f[y+(x<<5)][now];
}

void rls(int x,int y,int now){
	if(obs[x][y]) return;
	if(x+y-1^n+m>>1){
		now^=a[x][y];
		if(x>1) rls(x-1,y,now);
		if(y>1) rls(x,y-1,now);
	}else ans+=f[y+(x<<5)][k^now];
}

#endif
