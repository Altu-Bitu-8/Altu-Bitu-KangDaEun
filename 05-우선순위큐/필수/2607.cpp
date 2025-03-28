#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

vector<int> origin;

vector<int> cntAlpha(string s) {
	vector<int> v(26);

	for (auto c : s) {
		v[c - 'A']++;
	}

	return v;
}

bool isSimilar(string s) {
	vector<int> cmp = cntAlpha(s);
	vector<int> vc;

	for (int i = 0; i < 26; i++) {
		if (cmp[i] != origin[i]) {
			vc.push_back(cmp[i] - origin[i]);
		}
	}
	if (vc.empty()) return true;
	if (vc.size() == 1 && abs(vc[0]) == 1) return true;
	if (vc.size() == 2 && abs(vc[0]) == 1 && vc[0] + vc[1] == 0) return true;
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int check = 0;
	string input;

	cin >> n;
	cin >> input;

	origin = cntAlpha(input);

	for (int i = 1; i < n; i++) {
		string inp;
		cin >> inp;

		if (isSimilar(inp)) {
			check++;
		}
	}
	cout << check;
}
