#include<iostream>
using namespace std;

//sum을 0으로 초기화하는 것의 중요성
int main(){
    int n, sum=0, res, pow;
    for(int i=0;i<5;i++){
        cin>>n;
        sum+=(int)(n*n);
    }
    res=sum%10;
    cout<<res<<endl;
    return 0;
}