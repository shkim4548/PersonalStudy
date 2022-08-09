#include<iostream>
using namespace std;

bool isPrime(int n){
	if(n<2)
		return false;

	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

int main(void){
	int input, n, cnt=0;
	cin>>input;
	for(int i=1;i<=input;i++){
		cin>>n;
		if(isPrime(n)==true){
			cnt++;
			//cout<<isPrime(n)<<'\n';
		}
	}
	//cout<<'\n';
	cout<<cnt<<'\n';
}