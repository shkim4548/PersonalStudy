#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
	int x, y, w, h, Axisx = 0, Axisy = 0;
	cin >> x >> y >> w >> h;
	vector<int> dis;
	
	dis[0] = -(Axisx - x);
	dis[1] = -(Axisy - y);
	dis[2] = w - x;
	dis[3] = h - y;

	sort(dis.begin(), dis.end());
	cout << dis[0] << '\n';
	return 0;
}