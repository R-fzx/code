#include<bits/stdc++.h>
#include<windows.h>
#define run(x) system((x+".exe").c_str())
#define check(x,y) system(("fc "+x+' '+y).c_str())
using namespace std;
string c1,c2,d,out1,out2;
int t,cnt;
/*
bl gcd bl.out gcd.out data 1000
*/
int main(){
	puts("please cin : code, std, code_out, std_out, data, time_limit");
	cin>>c1>>c2>>out1>>out2>>d>>t;
	int t1,t2;
	bool wa(false),tle(false),re(false);
	while(++cnt){
		run(d);
		int s(clock());
		if(run(c1)){
			re=true;
			break;
		}
		t1=clock()-s;
		s=clock();
		if(run(c2)){
			re=true;
			break;
		}
		t2=clock()-s;
		if(t1>=t){
			tle=true;
			break;
		}
		if(check(out1,out2)){
			wa=true;
			break;
		}
		Sleep(100);
		if(cnt%7==0)system("cls");
	}	
	system("cls");
	if(wa){
		cout<<"Wrong Answer\n";
		printf("after %d ms",t1);
	}
	if(tle){
		cout<<"Tle\n";
		printf("after %d ms",t1);
	}
	if(re){
		cout<<"Runtime Error\n";
	}
	return 0;
} 
