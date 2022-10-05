#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <complex> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <cassert> 
using namespace std;

int n=50;

int main(){
	char inf[]="d.in ";
	for(int i=0;i<10;i++){
		inf[4]=i+'0';
		freopen(inf,"w",stdout);
		cout<<n<<endl;
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if((j==3)&&(k==3))cout<<"@";else{
					int t=rand()%(long long)20;
					if(t<15)cout<<"-";else
					if(t<19)cout<<"X";else
					cout<<"*";	
				}
			}
			cout<<endl;
		}	
	}
	return 0;
}
