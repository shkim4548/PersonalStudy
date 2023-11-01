#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1001;
bool visited[MAX];
vector<int> graph[MAX];

int cnt = 1;
void DFS(int x) {
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) {
			cnt++;
			DFS(y);
		}
	}
	cout << cnt << '\n';
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int N, M, K, x, y;
		cin >> N >> M >> K;
		for (int j = 0; j < K; j++) {
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		DFS(K);
	}
}