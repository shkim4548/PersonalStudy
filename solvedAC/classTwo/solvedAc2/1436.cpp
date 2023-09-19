#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int n, count = 0;
	string title;
	cin >> n;
	int i = 0;
	while (true) {
		string number = to_string(i);
		for (int j = 0; j <= number.length(); j++) {
			if (number.substr(j, 3).compare("666") == 0) {
				if (title.compare(number) == 0)
					continue;
				title = number;
				count++;
				//cout << "number and count is " << number<< " " << count << endl;
			}
		}
		if (count == n)
			break;
		++i;
	}
	//cout << "title is : "<< title << endl;
	cout << title << endl;
}