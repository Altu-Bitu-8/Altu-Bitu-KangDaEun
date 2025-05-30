#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> ci;
const int INF = 1e9;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dijkstra(int v, vector<vector<int>>& graph) {
    vector<vector<int>> dist(v, vector<int>(v, INF)); //각 정점까지의 최단 경로 저장
    // 현재 탐색하는 중간 정점까지의 최단 경로
    priority_queue<pair<int, ci>, vector<pair<int, ci>>, greater<>> pq;

    dist[0][0] = graph[0][0];
    pq.push({ dist[0][0], {0, 0} });
    while (!pq.empty()) {
        int weight = pq.top().first; // 현재 정점까지의 경로값
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (weight > dist[x][y]) { // 이미 더 작은 값으로 기록된 정점
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= v || ny >= v) continue;

            int next_cost = weight + graph[nx][ny];
            if (next_cost < dist[nx][ny]) {
                dist[nx][ny] = next_cost;
                pq.push({ next_cost, {nx, ny} });
            }
        }
    }
    return dist[v - 1][v - 1];
}

int main()
{
    int n, t = 1;

    while (cin >> n, n) {
        vector<vector<int>> graph(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                cin >> graph[i][k];
            }
        }

        int answer = dijkstra(n, graph);
        cout << "Problem " << t++ << ": " << answer << '\n';
    }

}