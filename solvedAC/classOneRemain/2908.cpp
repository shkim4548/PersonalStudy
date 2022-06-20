#include<iostream>
using namespace std;

int main(){
    int a,b,res=0;
    cin>>a;
    cin>>b;
    if(a>b){
        res+=a%10;
        res+=a%100-a%10;
        res+=a/100;
    }
    else{
        res+=b%10;
        res+=b%100-b%10;
        res+=b/100;
    }
    cout<<res;
}