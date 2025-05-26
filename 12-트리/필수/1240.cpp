#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> tree[1001];

int parent[1001];
int depth[1001];
int dist[1001];

void dfs(int node, int par, int d, int totalDist) {
    parent[node] = par;
    depth[node] = d;
    dist[node] = totalDist;

    for (auto& p : tree[node]) {
        int next = p.first;
        int weight = p.second;
        if (next != par) {
            dfs(next, node, d + 1, totalDist + weight);
        }
    }
}

int lca(int a, int b) {
    while (depth[a] > depth[b]) a = parent[a];
    while (depth[b] > depth[a]) b = parent[b];

    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        tree[p].push_back({ q, r });
        tree[q].push_back({ p, r });
    }

    dfs(1, 0, 0, 0);

    while (m--) {
        int a, b;
        cin >> a >> b;
        int anc = lca(a, b);
        int total = dist[a] + dist[b] - 2 * dist[anc];
        cout << total << endl;
    }

}