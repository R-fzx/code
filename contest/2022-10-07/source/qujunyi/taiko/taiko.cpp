#include<bits/stdc++.h>
using namespace std;
map<string ,bool> m,mm;
int main(){
    freopen("taiko.in","r",stdin);
    freopen("taiko.out","w",stdout);
    int n;
    cin>> n;
    string a;
    for(int i = 1;i < n;i++){
        a+='0';
    }
    //cout <<a << endl;
        m[a]=1;
    a+='0';
    for(int i = 1;i <= n;i++){
        string b;
        for(int j = 1;j <= i;j++){
            b+='1';
        }
        for(int j = i+1;j < n;j++){
            b+='0';
        }   
        //cout << b << endl;
        m[b]=1;
    }
    int s = 1;
    bool u = 0;
    for(int i = n;i < pow(2,n)-n;i++){
        string b = "";
        //cout << s << " "<< i-1 << endl;
        for(int j = s;j <= i-1;j++ ){
            b+=a[j];
            //cout << j <<" "<<b<< endl;
        }
        //cout << b << endl;
        if(m[b]==0){
            a+='0';
            m[b]=1;
        }else if(mm[b]==0){
            a+='1';
            mm[b]=1;
        }else{
            u=1;
        }
        s++;
    }
    for(int i = 0;i < n;i++){
        a+='1';
    }
    cout<<pow(2,n)<< " " << a;
}