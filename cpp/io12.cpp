#include<iostream>
using namespace std;

int main(){
    int a,b,c,res1,res2,res3,res4;
    cin>>a>>b>>c;

    res1=(a+b)%c;
    res2=((a%c)+(b%c))%c;
    res3=(a*b)%c;
    res4=((a%c)*(b%c))%c;
    cout<<res1<<"\n"<<res2<<"\n"<<res3<<"\n"<<res4<<endl;
}