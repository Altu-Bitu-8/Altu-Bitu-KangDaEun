#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, x, y;
int graph[102][102] = { 0, }; // 그래프 배열
int visited[1002] = { 0, }; // 방문 배열
int bfs_answer[102] = { 0, }; // bfs 정답을 담을 배열
int idx = 1;
queue<int> q;

void bfs(int from) {

	q.push(from);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (graph[now][i] != 0 && !visited[i]) {
				visited[i] = visited[now] + 1;
				bfs_answer[idx++] = i;
				q.push(i);
			}
		}
	}

	return;
}

int main()
{
	int k;

	cin >> n;
	cin >> x >> y;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int tmp_x, tmp_y;

		cin >> tmp_x >> tmp_y;

		graph[tmp_x][tmp_y] = 1;
		graph[tmp_y][tmp_x] = 1;
	}

	bfs(x);

	if (visited[y] == 0) {
		visited[y] = -1;
	}

	cout << visited[y];

}