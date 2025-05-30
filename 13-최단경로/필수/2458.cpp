#include <iostream>
#include <vector>

using namespace std;

const int MAX = 501;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true; // a < b
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = true;
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int k = 1; k <= n; k++) {
            if (i == k) continue;
            if (graph[i][k] || graph[k][i])
                count++;
        }
        if (count == n - 1)
            result++;
    }

    cout << result << '\n';
    return 0;
}