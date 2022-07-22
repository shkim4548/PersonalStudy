#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main(void) {
	int n, hash = 31;
	long long hashed = 0;
	char input[50];
	//ÀÔ·ÂÀº ¿µ¹® ¼Ò¹®ÀÚ¸¸, ASCII 'a'==97
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < n; i++) {
		//»çÄ¢ ¿¬»ê ¿¡¼­ °ö¼ÀÀº µ¡¼Àº¸´Ù ¿ì¼±µË´Ï´Ù. ÀØÁö ¸¿½Ã´Ù °ýÈ£Ä¡±â
		hashed += ((int)input[i] - 96) * (int)pow(hash, i);
		//cout << (int)input[i] - 96 << " ";
		//cout << (int)pow(hash, i) << " " << i;
		//cout << hashed << '\n';
	}
	cout << hashed;
}