#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, k;
int graph[1001][1001] = { 0, }; // 그래프 배열
bool visited[10001] = { false, }; // 방문 배열
int bfs_answer[1001] = { 0, }; // dfs 정답을 담을 배열
int idx = 1;
int cnt = 0;

void bfs(int from) {
	queue<int> q;
	q.push(from);
	visited[from] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; ++i) {
			if (graph[now][i] == 1 && !visited[i]) {
				visited[i] = true;
				cnt++;
				bfs_answer[idx++] = i;
				q.push(i);
			}
		}
	}

	return;
}

int main()
{
	cin >> n;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int x, y;

		cin >> x >> y;

		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	bfs(1);
	cout << cnt;

}