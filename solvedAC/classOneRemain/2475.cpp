#include<iostream>
using namespace std;

int main(){
    int n, sum, res, pow;
    for(int i=0;i<5;i++){
        cin>>n;
        sum+=n*n;
    }
    res=sum%10;
    cout<<res;
    return 0;
}