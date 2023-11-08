#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1001;
vector<bool> visited;
vector<int> graph[MAX];

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y])
			dfs(y);
	}
}

int main() {
	int N, M, u, v, sum = 0;
	vector<int> vec;
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 0; i < M; i++) {
		//cout << graph[i].size() << '\n';
		vec.push_back(graph[i].size());
	}
	sort(vec.begin(), vec.end());
	cout << vec[M-1] << '\n';
}