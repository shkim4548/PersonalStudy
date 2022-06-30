#include<iostream>
using namespace std;

int main() {
	int x, y, w, h, Axisx = 0, Axisy = 0, t;
	int dis[4];
	cin >> x >> y >> w >> h;

	dis[0] = -(Axisx - x);
	dis[1] = -(Axisy - y);
	dis[2] = w - x;
	dis[3] = h - y;
	
	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 4; j++) {
			if (dis[i] < dis[j]) {
				t = dis[i];
				dis[i] = dis[j];
				dis[j] = t;
			}
		}
	}
	cout << dis[3] << '\n';
	return 0;
}