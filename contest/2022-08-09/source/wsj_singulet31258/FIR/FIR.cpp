/**
 * Copyright (C) 2022 wsj (also called singulet31258, singulet3c58, quarkstar31258)
 * Nobody else can submit my code to Yali OJ!!!
 *
 * Difficulty: HARD & COMPLEX
 *
 * My Solution: Brute-Force
 *
 * Time Complexity: ???
 */

#ifndef _YALI_20220809_FIR_SOLUTION_BY_WSJ_SINGULET31258_
#define _YALI_20220809_FIR_SOLUTION_BY_WSJ_SINGULET31258_

#include<cstdio>
#include<cctype>
#define MAX_QUANTITY_OF_STEPS 1001

int c,i,j,n,k,x[MAX_QUANTITY_OF_STEPS],y[MAX_QUANTITY_OF_STEPS];
int occ[MAX_QUANTITY_OF_STEPS][MAX_QUANTITY_OF_STEPS];//Occupied?
int legal(int,int);//Is the chess legal?
int rvict(int,int);//Can get victory by row?
int cvict(int,int);//Can get victory by column?
int dvict(int,int);//Can get victory by diagonal?
int put(int,int);//Put the chess.
void read(int*);

int main(){
	freopen("FIR.in","r",stdin);
	freopen("FIR.out","w",stdout);
	read(&n);read(&k);
	for(i=1;i<=n;++i){
		read(x+i);read(y+i);
		
	}
	return 0;
}

int legal(int x,int y){
	if(occ[x][y]) return 0;
	
}

void read(int* p){
	while(!isdigit(c=getchar()));
	*p=c&15;
	while(isdigit(c=getchar())) *p=(*p<<1)+(*p<<3)+(c&15);
}

#endif
