#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> q; // 문서의 중요도와 순서를 저장하는 큐
        priority_queue<int> pq; // 중요도를 저장하는 우선순위 큐

        for (int i = 0; i < N; ++i) {
            int priority;
            cin >> priority;
            q.push({ priority, i }); // {중요도, 순서} 형태로 큐에 삽입
            pq.push(priority); // 중요도만 우선순위 큐에 삽입
        }

        int cnt = 0;
        while (!q.empty()) {
            int priority = q.front().first;
            int idx = q.front().second;
            q.pop();

            if (pq.top() == priority) {
                pq.pop();
                cnt++;

                if (idx == M) {
                    cout << cnt << endl;
                    break;
                }
            }
            else {
                q.push({ priority, idx });
            }
        }
    }

    return 0;
}
