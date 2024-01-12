#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// 간선을 나타내는 pair의 형태
typedef pair<int, int> pii;

// 다익스트라 알고리즘을 통해 최단 경로 및 비용을 찾는 함수
void dijkstra(vector<vector<pii>>& graph, int start, int end, vector<int>& distance, vector<int>& path) {
    int n = graph.size();
    distance.assign(n, INT_MAX);  // 시작점에서의 거리를 무한대로 초기화
    distance[start] = 0;  // 시작점의 거리를 0으로 설정

    // 우선순위 큐를 사용한 다익스트라 알고리즘
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > distance[u]) continue;  // 이미 더 짧은 경로가 있으면 스킵

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // 더 짧은 경로를 찾으면 갱신
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                path[v] = u;  // 최단 경로를 역추적하기 위한 이전 노드 정보 저장
                pq.push({ distance[v], v });
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // 각 도시의 인접한 도시와 비용을 저장하는 그래프
    vector<vector<pii>> graph(n);
    for (int i = 0; i < m; ++i) {
        int start, end, cost;
        cin >> start >> end >> cost;
        graph[start - 1].emplace_back(end - 1, cost);
    }

    int start_city, end_city;
    cin >> start_city >> end_city;
    start_city--;
    end_city--;

    // 최단 경로를 저장하는 벡터
    vector<int> distance, path(n, -1);
    dijkstra(graph, start_city, end_city, distance, path);

    // 최단 경로의 비용 출력
    cout << distance[end_city] << endl;

    // 최단 경로를 역추적하여 출력
    vector<int> shortest_path;
    for (int at = end_city; at != -1; at = path[at]) {
        shortest_path.push_back(at + 1);  // 도시 번호를 1부터 출력하기 위한 조정
    }

    // 최단 경로에 포함된 도시의 개수 출력
    cout << shortest_path.size() << endl;

    // 최단 경로의 도시들을 출력
    for (int i = shortest_path.size() - 1; i >= 0; --i) {
        cout << shortest_path[i] << ' ';
    }

    return 0;
}
