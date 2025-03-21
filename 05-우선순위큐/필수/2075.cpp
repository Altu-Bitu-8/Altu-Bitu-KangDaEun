#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p;
	priority_queue<int, vector<int>, greater<>> pq;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> p;

			pq.push(p);
			if (pq.size() > n) {
				pq.pop();
			}
		}
	}

	cout << pq.top();

}
