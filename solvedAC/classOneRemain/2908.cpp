#include<iostream>
using namespace std;

int main(){
    int a, b, rev1=0, rev2=0;
    cin>>a;
    cin>>b;

    rev1+=a%10*100;
    rev1+=a%100-a%10;
    rev1+=a/100;
    
    rev2+=b%10*100;
    rev2+=b%100-b%10;
    rev2+=b/100;
    
    if(rev1>rev2){
        cout<<rev1;
    }
    else{
        cout<<rev2;
    }

    return 0;
}