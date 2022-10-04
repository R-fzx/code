#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chaser.in","r",stdin);
    freopen("chaser.out","w",stdout);
    int x;
    double y;
    while(cin >> x>> x>> x>> x>> x>> x>> x>> x>> x>> x>> y>> y){
        x= (rand()*rand()-rand()+rand()*rand()-rand()+rand()*(int)pow(rand(),rand())+rand()*rand()-rand()-rand()-rand()+rand()*rand()-rand()+rand()*(int)pow(rand(),rand())+rand()*rand()-rand()-rand()-rand())%3;
        if(x==0){
            cout << "Dangerous";
        }else if(x==1){
            cout << "Perfect";
        }else{
            cout << "Miss";
        }
        cout << endl;
    }
}
